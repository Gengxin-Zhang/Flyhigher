#include "StartThread.h"

#include "Engine.h"

StartThread::StartThread(shared_ptr<Game> const game){
    this->game = game;
}

void StartThread::run(){
    game->run();
}
