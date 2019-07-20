#include <QApplication>
#include "./main/Main.cpp"
#include "./ui/uiconfig.h"
#include "./ui/uitest.h"
#include "./server/ServerThread.h"
#include "./tools/DataReader.h"
#define log Engine::getInstance()->getLogger()
#define judger Engine::getInstance()->getNowGame()->getJudger()

int main(int argc, char *argv[])
{
    DataReader* readerThread = new DataReader();
    StartThread* nowGameThread = new StartThread();
    ServerThread* serverThread = new ServerThread();
    __main(nowGameThread, argc, argv);
    QApplication a(argc, argv);
    log->information("初始化完毕");
    serverThread->start();
    readerThread->start();
    UIConfig conf;
    conf.init();
    conf.show();
    QObject::connect(nowGameThread,SIGNAL(send(int)),&conf,SLOT(receiveslot(int)));
    UITest uitest;
    log->debug("UITest 载入");
    if(Engine::isDebugMode()){
        uitest.show();
        QObject::connect(nowGameThread,SIGNAL(back(QString)),&uitest,SLOT(output(QString)));
    }
    log->debug("main end");
    return a.exec();
}
