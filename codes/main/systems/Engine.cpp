/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Engine.h"
#include "../games/Game.h"

/**
 * Engine implementation
 */


bool Engine::hasInit = false;

shared_ptr<Engine> Engine::engine =  nullptr;

shared_ptr<Engine> Engine::getInstance(){
    if(!hasInit){
        engine = shared_ptr<Engine>(new Engine());
        hasInit = true;
    }
    return engine;
}

bool Engine::isDebugMode(){
    return getInstance()->onDebugMode();
}

Engine::Engine() {
    hasStarted = false;
    hasNowGame = false;
    debugMode = true;
}

Engine::~Engine() {

}

void Engine::startEngine(const bool debugMode) {
    if(hasStarted){
        throw invalid_argument("You have already started once!");
    }
    this->debugMode = debugMode;
    this->registerLogger(shared_ptr<Logger>(new Logger("./out.txt")));
    logger->information("成功启动！");
    logger->debug("debug模式：开启");
}

void Engine::registerLogger(shared_ptr<Logger> const logger) {
    this->logger = logger;
}

bool Engine::onDebugMode() const{
    return debugMode;
}

shared_ptr<Logger> Engine::getLogger() const{
    return logger;
}

void* threadStartGame(shared_ptr<Game> game){
    game->run();
    return nullptr;
}

void Engine::startGame(shared_ptr<GameConfiguration> const config){
    if(hasNowGame){
        logger->warning("不能启动两次游戏！");
        return;
    }
    hasNowGame = true;
    logger->debug("创建启动线程");
    this->nowGame = shared_ptr<Game>(new Game(config));
    logger->debug("启动线程开始执行");
    this->nowGameThread = shared_ptr<thread>(new thread(threadStartGame, nowGame));
}

shared_ptr<Game> Engine::getNowGame() const{
    return nowGame;
}

void Engine::shutdown() const{
    engine.reset();
}
