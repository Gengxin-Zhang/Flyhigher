#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <QThread>


class ServerThread: public QThread
{
    Q_OBJECT
public:
    ServerThread();
protected:
    void run();
};

#endif // SERVERTHREAD_H
