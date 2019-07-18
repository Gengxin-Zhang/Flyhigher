#include "DataReader.h"
#include <thread>


bool DataReader::inited = false;

std::shared_ptr<DataReader> DataReader::dataReader = nullptr;

DataReader::DataReader(){
    channel = AmqpClient::Channel::Create("localhost");
    channel->DeclareExchange("FLYHIGHER", AmqpClient::Channel::EXCHANGE_TYPE_TOPIC);
    std::string queue_name = channel->DeclareQueue("FLYHIGHER", false, true, false, false);
    channel->BindQueue(queue_name, "FLYHIGHER", "*");
    consumer_tag = channel->BasicConsume(queue_name, "", true, true, false, 1);
    std::thread t1(read_data_from_rmq);
}

DataReader::~DataReader(){
    channel->BasicCancel(consumer_tag);
}

std::shared_ptr<DataReader> DataReader::getInstance(){
    if (!inited){
        dataReader = std::shared_ptr<DataReader>(new DataReader());
        inited = true;
    }
    return dataReader;
}

void DataReader::read_data_from_rmq(){
    AmqpClient::Envelope::ptr_t envelope = channel->BasicConsumeMessage(consumer_tag);
    std::string buffer = envelope->Message()->Body();
    msg_pool.push(buffer);
}