#include <QApplication>
#include "./main/Main.cpp"
#include "./ui/uiconfig.h"
#include "./ui/uitest.h"
#include "./tools/DataReader.h"
#define log Engine::getInstance()->getLogger()
#define judger Engine::getInstance()->getNowGame()->getJudger()

int main(int argc, char *argv[])
{
    StartThread* nowGameThread = new StartThread();
    DataReader* dataReader = new DataReader();
    __main(nowGameThread, argc, argv);
    QApplication a(argc, argv);
    log->information("初始化完毕");
    UIConfig conf;
    conf.init();
    conf.show();
    QObject::connect(nowGameThread,SIGNAL(send(int)),&conf,SLOT(receiveslot(int)));
    UITest uitest;
    log->debug("aaa");
    uitest.show();
    QObject::connect(nowGameThread,SIGNAL(back(QString)),&uitest,SLOT(output(QString)));
    log->debug("bbb");
    dataReader->start();
    log->debug("main end");
    return a.exec();
}
