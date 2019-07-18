#include "StartThread.h"

#include "Engine.h"

StartThread::StartThread(){
}

void StartThread::init(shared_ptr<Game> const game){
    this->game = game;
}

void StartThread::run(){
    emit send(game->run());
}
