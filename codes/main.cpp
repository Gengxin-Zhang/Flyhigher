#include <QCoreApplication>
#include "./main/Main.cpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    __main(argc, argv);
    return a.exec();
}
