#include <QApplication>
#include "./main/Main.cpp"
#include "./ui/uiconfig.h"
#include "./ui/uitest.h"
#define log Engine::getInstance()->getLogger()
#define judger Engine::getInstance()->getNowGame()->getJudger()

int main(int argc, char *argv[])
{
    StartThread* nowGameThread = new StartThread();
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
    //可能要开辟网络部分的线程，因此不能阻塞
    log->debug("main end");
    return a.exec();
}
