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

Engine* Engine::engine =  nullptr;

Engine* Engine::getInstance(){
    if(!hasInit){
        engine = new Engine();
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
    logger->debug("引擎中止");
    if(nowGameThread){
        logger->debug("调用线程析构");
        nowGameThread->~thread();
    }
    delete [] nowGame;
}

void Engine::startEngine(const bool debugMode) {
    if(hasStarted){
        throw invalid_argument("You have already started once!");
    }
    this->debugMode = debugMode;
    this->registerLogger(new Logger("./out.txt"));
    logger->infomation("成功启动！");
    logger->debug("debug模式：开启");
    //-------------Test-----------------
    Point2D ps[2] = {Point2D(150, 150), Point2D(350, 350)};
    PlayerConfiguration* pc1[2] = {new PlayerConfiguration("XHH", Color(100,100,100,100),
                                   new CarrierConfiguration(
                                       new WeaponConfiguration(10, 60, 5, 100),
                                       new NukeConfiguration(2000, 100, 20, 50, 5),
                                       new PlaneConfiguration(2000, 0.1, 30, 0, 0)),
                                   new BomberConfiguration(
                                       new WeaponConfiguration(10, 80, 10, 50),
                                       new PlaneConfiguration(500, 0.5, 10, 1, 20)),
                                   new FighterConfiguration(
                                       new WeaponConfiguration(2, 20, 20, 10),
                                       new RebuildableConfiguration(100, 200),
                                       new PlaneConfiguration(200, 10, 5, 5, 5))),
           new PlayerConfiguration("NMD", Color(100,25,80,232),
                                       new CarrierConfiguration(
                                           new WeaponConfiguration(10, 60, 5, 100),
                                           new NukeConfiguration(2000, 100, 20, 50, 5),
                                           new PlaneConfiguration(2000, 0.1, 30, 0, 0)),
                                       new BomberConfiguration(
                                           new WeaponConfiguration(10, 80, 10, 50),
                                           new PlaneConfiguration(500, 0.5, 10, 1, 20)),
                                       new FighterConfiguration(
                                           new WeaponConfiguration(2, 20, 20, 10),
                                           new RebuildableConfiguration(100, 200),
                                           new PlaneConfiguration(200, 10, 5, 5, 5)))};
            startGame(new GameConfiguration(new MapConfiguration(500, 500, 2, ps),
                                                    new JudgerConfiguration(),
                                                    new LoopConfiguration(200, milliseconds(50)), 2, pc1));
}

void Engine::registerLogger(Logger* const logger) {
    this->logger = logger;
}

bool Engine::onDebugMode() const{
    return debugMode;
}

Logger* Engine::getLogger() const{
    return logger;
}

void* threadStartGame(Game* game){
    game->run();
    return nullptr;
}

void Engine::startGame(GameConfiguration * const config){
    if(hasNowGame){

    }
    hasNowGame = true;
    logger->debug("创建启动线程");
    this->nowGame = new Game(config);
    this->nowGameThread = new thread(threadStartGame, nowGame);
    logger->debug("启动线程开始执行");
    this->nowGameThread->detach();
}

Game* Engine::getNowGame() const{
    return nowGame;
}

void Engine::shutdown() const{
    delete this;
}
