/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Engine.h"

/**
 * Engine implementation
 */

bool Engine::hasInit = false;

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
    
}

void Engine::registerLogger(Logger* const logger) {
    this->logger = logger;
}