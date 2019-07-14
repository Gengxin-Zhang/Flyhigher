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

Engine* Engine::engine = (Engine*) 0;

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
    debugMode = true;
}

Engine::~Engine() {

}

void Engine::startEngine(const bool debugMode) {
    if(hasStarted){
        throw invalid_argument("You have already started once!");
    }
    this->debugMode = debugMode;
    this->registerLogger(new Logger("./out.txt"));
    logger->infomation("成功启动！");
    logger->debug("debug模式：开启");
    Point2D ps[2] = {Point2D(100, 100), Point2D(400, 400)};
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
    Game* game = new Game(new GameConfiguration(new MapConfiguration(500, 500, 2, ps),
                                                new JudgerConfiguration(),
                                                new LoopConfiguration(200), 2, pc1));
    game->run();
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
