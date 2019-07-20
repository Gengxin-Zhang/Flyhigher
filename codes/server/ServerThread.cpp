#include "ServerThread.h"
#include "./websocketAPI.hpp"
#include "../main/systems/Engine.h"
#define log Engine::getInstance()->getLogger()

ServerThread::ServerThread()
{

}

void ServerThread::run(){
    server echo_server;
    init_server();
    while (true){
        try {
            log->information("[*] Server Starting on 0.0.0.0:", WS_PORT);
            echo_server.init_asio();
            echo_server.set_open_handler(bind(&on_open, &echo_server, ::_1));
            echo_server.set_message_handler(bind(&on_message, &echo_server, ::_1, ::_2));
            // 在所有网络接口的 PORT 上监听
            echo_server.listen(WS_PORT);
            // 启动服务器端Accept事件循环
            echo_server.start_accept();
            log->information("[+] Websocket Server Start successed!");
            // 启动事件循环（ASIO的io_service），当前线程阻塞
            echo_server.run();
        }catch (websocketpp::exception const &e) {
            log->severe("[x] Websocket Server Error!");
            log->debug(e.what());
        } catch (...){
            log->severe("[x] Websocket Server Error!");
            log->debug("[x] Other Exception");
        }
        log->warning("[*] Server Restarting");
    }
}
