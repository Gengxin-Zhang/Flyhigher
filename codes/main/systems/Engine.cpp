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
    logger->infomation("成功启动！");
    logger->debug("debug模式：开启");
    //-------------Test-----------------
    Point2D ps[2] = {Point2D(150, 150), Point2D(350, 350)};
    shared_ptr<PlayerConfiguration> pc1[2] = {shared_ptr<PlayerConfiguration>(new PlayerConfiguration("XHH", Color(100,100,100,100),
                                   shared_ptr<CarrierConfiguration>(new CarrierConfiguration(
                                       shared_ptr<WeaponConfiguration>(new WeaponConfiguration(10, 60, 5, 100)),
                                       shared_ptr<NukeConfiguration>(new NukeConfiguration(2000, 100, 20, 50, 5)),
                                       shared_ptr<PlaneConfiguration>(new PlaneConfiguration(2000, 0.1, 30, 0, 0)))),
                                   shared_ptr<BomberConfiguration>(new BomberConfiguration(
                                       shared_ptr<WeaponConfiguration>(new WeaponConfiguration(10, 80, 10, 50)),
                                       shared_ptr<PlaneConfiguration>(new PlaneConfiguration(500, 0.5, 10, 1, 20)))),
                                   shared_ptr<FighterConfiguration>(new FighterConfiguration(
                                       shared_ptr<WeaponConfiguration>(new WeaponConfiguration(2, 20, 20, 10)),
                                       shared_ptr<RebuildableConfiguration>(new RebuildableConfiguration(100, 200)),
                                       shared_ptr<PlaneConfiguration>(new PlaneConfiguration(200, 10, 5, 5, 5)))))),
           shared_ptr<PlayerConfiguration>(new PlayerConfiguration("NMD", Color(100,25,80,232),
                                   shared_ptr<CarrierConfiguration>(new CarrierConfiguration(
                                       shared_ptr<WeaponConfiguration>(new WeaponConfiguration(10, 60, 5, 100)),
                                       shared_ptr<NukeConfiguration>(new NukeConfiguration(2000, 100, 20, 50, 5)),
                                       shared_ptr<PlaneConfiguration>(new PlaneConfiguration(2000, 0.1, 30, 0, 0)))),
                                   shared_ptr<BomberConfiguration>(new BomberConfiguration(
                                       shared_ptr<WeaponConfiguration>(new WeaponConfiguration(10, 80, 10, 50)),
                                       shared_ptr<PlaneConfiguration>(new PlaneConfiguration(500, 0.5, 10, 1, 20)))),
                                   shared_ptr<FighterConfiguration>(new FighterConfiguration(
                                       shared_ptr<WeaponConfiguration>(new WeaponConfiguration(2, 20, 20, 10)),
                                       shared_ptr<RebuildableConfiguration>(new RebuildableConfiguration(100, 200)),
                                       shared_ptr<PlaneConfiguration>(new PlaneConfiguration(200, 10, 5, 5, 5))))))};
            startGame(shared_ptr<GameConfiguration>(new GameConfiguration(
                                                    shared_ptr<MapConfiguration>(new MapConfiguration(500, 500, 2, ps)),
                                                    shared_ptr<JudgerConfiguration>(new JudgerConfiguration(500)),
                                                    shared_ptr<LoopConfiguration>(new LoopConfiguration(200, milliseconds(50))), 2, pc1)));
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

    }
    hasNowGame = true;
    logger->debug("创建启动线程");
    this->nowGame = shared_ptr<Game>(new Game(config));
    this->nowGameThread = shared_ptr<thread>(new thread(threadStartGame, nowGame));
    logger->debug("启动线程开始执行");
    this->nowGameThread->detach();
}

shared_ptr<Game> Engine::getNowGame() const{
    return nowGame;
}

void Engine::shutdown() const{
    engine.reset();
}
