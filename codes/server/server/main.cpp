//
//  main.cpp
//  server
//
//  Created by zhangone on 2019/7/18.
//  Copyright © 2019 zhangone. All rights reserved.
//
 
#include <iostream>
#include <chrono> 
#include <stack> 
#include <map>
#include <vector>
#include <ctime>
#include <fstream>

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
 
#include <SimpleAmqpClient/SimpleAmqpClient.h>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "yaml-cpp/yaml.h"

typedef websocketpp::server<websocketpp::config::asio> server;
typedef websocketpp::config::asio::message_type::ptr message_ptr;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;
using namespace rapidjson;



// 配置信息
static std::string CONFIG_NAME = "config.yaml"; // 配置文件 .yaml

int WS_PORT = 9090; // Websocket端口
std::string RMQ_HOST = "127.0.0.1"; // RabbitMQ 服务器地址
int RMQ_PORT = 5672; // RabbitMQ 端口
std::string RMQ_KEY = "FLYHIGHER"; // RabbitMQ key
std::string RMQ_EXCHANGENAME = "FLYHIGHER";
std::string RMQ_USER = "FLYHIGHER"; //RabbitMQ服务端登录用户名
std::string RMQ_PWD = ""; //RabbitMQ服务端登录密码


bool DEBUG_MODE = false; // 调试模式开关
int PLAYER_COUNT = 0; // 配置文件中的玩家数
int64_t MIN_INTERVAL; // 两条消息的最小时间间隔
//int MAX_PLAYER; // 最大用户数 没有必要

AmqpClient::Channel::ptr_t channel;

struct user{
    // 存储用户数据
    std::string appid; // 分配的用户appid
    std::string name; // 用户名，辅助显示
    std::string color;
    uint64_t last_message; // 记录最近一次收到消息的时间戳
    bool verified = false;
    user(){};
};

std::vector<user> players; // 配置文件中的用户信息
std::map<std::string, user> users; // 维护用户 appid->user 映射表 ， 为了连接安全， 后期可改为secretkey加密验证，并为每条连接分配uuid的模式

const user &verify_user(std::string appid){
    if(users.find(appid) != users.end()){
        return users[appid];
    }else{
        return user();
    }
}

// 使用JSON
template <typename T>
void operator >> (const YAML::Node& node, T& i) {
    i = node.as<T>();
};

//void operator >> (const YAML::Node& node, int &s){
//    s = node.as<int>();
//}

uint64_t now(){
    // 获取 uint64_t 格式的当前时间戳
    std::chrono::milliseconds ms =
                 std::chrono::duration_cast< std::chrono::milliseconds >(
                 std::chrono::system_clock::now().time_since_epoch());
    return (uint64_t)ms.count();
}

std::string value_to_string(Value value){
    // 将Value格式数据转换为string
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    value.Accept(writer);
    return buffer.GetString();
}

std::string document_to_string(Document &document){
    // 将Document格式数据转换为string
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    document.Accept(writer);
    return buffer.GetString();
} 

void init_server(){
    // 初始化服务器，读取配置信息，建立RabbitMQ连接
    YAML::Node server = YAML::LoadFile(CONFIG_NAME);
    server["DEBUG_MODE"] >> DEBUG_MODE;
    server["WS_PORT"] >> WS_PORT;
    server["RMQ_HOST"] >> RMQ_HOST;
    server["RMQ_PORT"] >> RMQ_PORT;
    server["RMQ_KEY"] >>  RMQ_KEY;
    server["RMQ_USER"] >> RMQ_USER;
    server["RMQ_PWD"] >> RMQ_PWD;
    server["MIN_INTERVAL"] >> MIN_INTERVAL;
//    std::cout << DEBUG_MODE;
    channel = AmqpClient::Channel::Create(RMQ_HOST);//, RMQ_PORT, RMQ_USER, RMQ_PWD);
    channel-> DeclareExchange(RMQ_EXCHANGENAME, AmqpClient::Channel::EXCHANGE_TYPE_TOPIC);
    std::string queue_name = channel->DeclareQueue("FLYHIGHER", false, true, false, false);
    channel->BindQueue(queue_name, RMQ_EXCHANGENAME, "");
}

void save_data(std::string){
    // 保存数据到缓存文件
}

void send_message_to_rmq(std::string key, std::string data){
    // 与AMQP交互， 推送消息到RabbitMQ
    channel->BasicPublish(RMQ_EXCHANGENAME, key,
                          AmqpClient::BasicMessage::Create(data));
}


void handel_auth(server *s, websocketpp::connection_hdl *hdl, std::string appid, const Document& data, std::string raw_data){
    Document result;
    result.SetObject();
    Document::AllocatorType& allocator = result.GetAllocator();
    
//    for (int i=0; i<PLAYER_COUNT; i++){
//        if (appid == players[i].appid){
//            users[appid] = players[i];
//            result.AddMember("op", "auth", allocator);
//            result.AddMember("status", true, allocator);
//            result.AddMember("code", 0, allocator);
//            result.AddMember("msg", "", allocator);
//            result.AddMember("data", Value(kNullType), allocator);
//            s->send(*hdl, document_to_string(result).c_str(), websocketpp::frame::opcode::text);
//            return;
//        }
//    }
    try{
        user usertemp = user();
        usertemp.appid = appid;
        usertemp.name = data["name"].GetString();
        usertemp.color = data["color"].GetString();
        usertemp.last_message = now();
        users[appid] = usertemp;
        send_message_to_rmq("auth", raw_data);
        result.AddMember("op", "auth", allocator);
        result.AddMember("status", true, allocator);
        result.AddMember("code", 0, allocator);
        result.AddMember("msg", "", allocator);
        result.AddMember("data", Value(kNullType), allocator);
        s->send(*hdl, document_to_string(result).c_str(), websocketpp::frame::opcode::text);
        return;
    }catch( ... ){
        result.AddMember("op", "auth", allocator);
        result.AddMember("status", false, allocator);
        result.AddMember("code", 1004, allocator);
        result.AddMember("msg", "appid error", allocator);
        result.AddMember("data", Value(kNullType), allocator);
        s->send(*hdl, document_to_string(result).c_str(), websocketpp::frame::opcode::text);
        return;
    }
}

void handel_action(server *s, websocketpp::connection_hdl *hdl, user& u, std::string raw_data){
    Document result;
    result.SetObject();
    Document::AllocatorType& allocator = result.GetAllocator();
    
    uint64_t now_time = now();
    
    if (now_time - u.last_message < MIN_INTERVAL){
        // 两次消息的时间间隔小于最小限制
        result.AddMember("op", "action", allocator);
        result.AddMember("status", false, allocator);
        result.AddMember("code", 1005, allocator);
        result.AddMember("msg", "time interval error", allocator);
        result.AddMember("data", Value(kNullType), allocator);
        s->send(*hdl, document_to_string(result).c_str(), websocketpp::frame::opcode::text);
        return;
    }
    
    send_message_to_rmq("action", raw_data);
    result.AddMember("op", "action", allocator);
    result.AddMember("status", true, allocator);
    result.AddMember("code", 0, allocator);
    result.AddMember("msg", "", allocator);
    result.AddMember("data", Value(kNullType), allocator);
    s->send(*hdl, document_to_string(result), websocketpp::frame::opcode::text);
    return;
}

void on_open( server *s, websocketpp::connection_hdl hdl ) {
    // 根据连接句柄获得连接对象
    server::connection_ptr con = s->get_con_from_hdl( hdl );
    // 获得URL路径
    // 要求连接者发送身份认证数据
    s->send(hdl, "{\"op\":\"auth\"}", websocketpp::frame::opcode::text);
    return;
}

void on_message( server *s, websocketpp::connection_hdl hdl, message_ptr msg ) {
    // websocket 消息响应函数
    std::string raw_data = msg->get_payload();
    // std::cout << &hdl << std::endl;
    Document data;
    Document result;
    result.SetObject();
    Document::AllocatorType& allocator = result.GetAllocator();
    data.Parse(raw_data.c_str());
    
    if (data.HasParseError()){
        // 消息非JSON格式，返回错误，
        Value value(kNullType);
        result.AddMember("op", "null", allocator);
        result.AddMember("status", false, allocator);
        result.AddMember("code", 1001, allocator);
        result.AddMember("msg", "JSON Error: invalid syntax", allocator);
        result.AddMember("data", value, allocator);
        s->send(hdl, document_to_string(result).c_str(), websocketpp::frame::opcode::text);
        return;
    }
    if (!(data.HasMember("op") and data["op"].GetString()) and (data.HasMember("appid") and data["appid"].GetString())){
        // 不含有必须的数据 op 和 appid， 消息不合法
        Value value(kNullType);
        result.AddMember("op", "null", allocator);
        result.AddMember("status", false, allocator);
        result.AddMember("code", 1002, allocator);
        result.AddMember("msg", "op is needed", allocator);
        result.AddMember("data", value, allocator);
        s->send(hdl, document_to_string(result).c_str(), websocketpp::frame::opcode::text);
        return;
    }
    std::string appid = data["appid"].GetString();
    const std::string op = data["op"].GetString();
    // 首先判断是否是认证信息
    if (op == "auth"){
        // 身份验证消息
        handel_auth(s, &hdl, appid, data, raw_data);
    }
    user now_user = verify_user(appid);
    if (!now_user.verified){
        // 未认证的连接
        Value value(kNullType);
        result.AddMember("op", "null", allocator);
        result.AddMember("status", false, allocator);
        result.AddMember("code", 1003, allocator);
        result.AddMember("msg", "auth failed", allocator);
        result.AddMember("data", value, allocator);
        s->send(hdl, document_to_string(result).c_str(),websocketpp::frame::opcode::text);
        return;
    }
    if(op == "action"){
        // 动作消息
        handel_action(s, &hdl, now_user, raw_data);
    }else if(op == "quit"){
        // 退出消息
//        return;
    }else{
        // 未知类型的消息，返回错误
        Value value(kNullType);
        rapidjson::Value op_value(rapidjson::kStringType);
        op_value.SetString(op.c_str(), (unsigned int)op.size());
        result.AddMember("op", op_value, allocator);
        result.AddMember("status", false, allocator);
        result.AddMember("code", 1006, allocator);
        result.AddMember("msg", "unknow op message failed", allocator);
        result.AddMember("data", value, allocator);
        s->send(hdl, document_to_string(result).c_str(),websocketpp::frame::opcode::text);
    }
    save_data(raw_data);
}

int main() {
    server echo_server;
    
    // 调整日志策略, none关闭日志
    echo_server.set_access_channels( websocketpp::log::alevel::none );
    echo_server.clear_access_channels( websocketpp::log::alevel::none );
    
    // 读取数据，初始化服务器
    init_server();
    
    while (true){
        try {
            std::cout << "[*] Server Starting on 0.0.0.0:" << WS_PORT << std::endl;
            echo_server.init_asio();
//            send_message_to_rmq("test", "test");
            
//            RabbitMQ测试
//            for (int i=0;i<100;i++)
//                send_message_to_rmq("test", "test");
        
            echo_server.set_open_handler( bind( &on_open, &echo_server, ::_1 ));
            echo_server.set_message_handler( bind( &on_message, &echo_server, ::_1, ::_2 ));
            // 在所有网络接口的 PORT 上监听
            echo_server.listen( WS_PORT );
        
            // 启动服务器端Accept事件循环
            echo_server.start_accept();
            std::cout << "[+] Server Start successed!" << std::endl;
            // 启动事件循环（ASIO的io_service），当前线程阻塞
            echo_server.run();
        
        } catch ( websocketpp::exception const &e ) {
            if (DEBUG_MODE)
                std::cout << "[x] Server Error" << e.what() << std::endl;
            else
                std::cout << "[x] Server Error" << std::endl;
        } catch ( ... ) {
            std::cout << "[x] Other Exception" << std::endl;
        }
        std::cout << "[*] Server Restarting" << std::endl;
    }
}
