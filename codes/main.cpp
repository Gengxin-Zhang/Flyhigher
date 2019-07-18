#include <QApplication>
#include "./main/Main.cpp"
#include "./ui/uiconfig.h"
#define log Engine::getInstance()->getLogger()

int main(int argc, char *argv[])
{
    __main(argc, argv);
    QApplication a(argc, argv);
    log->information("初始化完毕");
    UIConfig conf;
    conf.init();
    conf.show();
    //可能要开辟网络部分的线程，因此不能阻塞
    return a.exec();
}
