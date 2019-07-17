/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */

#include "./systems/Engine.h"

int __main(int argc, char** argv){
    bool debugMode = false;
    for(int i=0; i<argc; ++i){
        if(strcmp(argv[i], "debug")){
            debugMode = true;
            cout<<"Debug mode enabled"<<endl;
        }
    }
    shared_ptr<Engine> engine = Engine::getInstance();
    engine->startEngine(debugMode);
    return 0;
}
