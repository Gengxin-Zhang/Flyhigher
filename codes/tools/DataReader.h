#include <iostream>
#include <queue>
#include "SimpleAmqpClient/SimpleAmqpClient.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"


class DataReader{
  public:
    DataReader();
    ~DataReader();
    DataReader(std::string host, int port, std::string exchange, std::string queue);
    std::queue<std::string> msg_pool;
    static std::shared_ptr<DataReader> getInstance();
  private:
    static std::shared_ptr<DataReader> dataReader;
    static bool inited;
    AmqpClient::Channel::ptr_t channel;
    std::string consumer_tag;
    void read_data_from_rmq();
};
