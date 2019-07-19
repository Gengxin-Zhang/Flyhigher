#include "DataReader.h"
#include <thread>

DataReader::DataReader(){
    channel = AmqpClient::Channel::Create("localhost");
    channel->DeclareExchange("FLYHIGHER", AmqpClient::Channel::EXCHANGE_TYPE_TOPIC);
    std::string queue_name = channel->DeclareQueue("FLYHIGHER", false, true, false, false);
    channel->BindQueue(queue_name, "FLYHIGHER", "*");
    consumer_tag = channel->BasicConsume(queue_name, "", true, true, false, 1);
}

DataReader::~DataReader(){
    channel->BasicCancel(consumer_tag);
}

void DataReader::run(){
    while(true){
        AmqpClient::Envelope::ptr_t envelope = channel->BasicConsumeMessage(consumer_tag);
        std::string buffer = envelope->Message()->Body();
        msg_pool.push(buffer);
    }
}
