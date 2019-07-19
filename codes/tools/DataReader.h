#include <iostream>
#include <queue>
#include "SimpleAmqpClient/SimpleAmqpClient.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <QThread>


class DataReader: public QThread{
    Q_OBJECT
  public:
    DataReader();
    ~DataReader();
    std::queue<std::string> getMsgPool();
  private:
    AmqpClient::Channel::ptr_t channel;
    std::string consumer_tag;
    std::queue<std::string> msg_pool;
  protected:
    virtual void run();
};
