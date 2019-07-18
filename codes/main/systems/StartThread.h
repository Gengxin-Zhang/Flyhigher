#ifndef STARTTHREAD_H
#define STARTTHREAD_H

#include "../games/Game.h"
#include <QThread>


class StartThread: public QThread{
public:
    StartThread(shared_ptr<Game> const game);
protected:
    void run();
private:
    shared_ptr<Game> game;
};

#endif // STARTTHREAD_H
