#ifndef STARTTHREAD_H
#define STARTTHREAD_H

#include "../games/Game.h"
#include <QThread>


class StartThread: public QThread{
    Q_OBJECT
signals:
    void send(const int state);
    void back(QString s);
public:
    StartThread();
    void init(shared_ptr<Game> const game);
protected:
    virtual void run();
private:
    shared_ptr<Game> game;
};

#endif // STARTTHREAD_H
