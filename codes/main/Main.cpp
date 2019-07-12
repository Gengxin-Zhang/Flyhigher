/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */

#include <cstring>
#include <iostream>
using std::cout, std::endl, std::string;

int main(int argc, char** argv){
    bool debugMode = false;
    string workDir ;
    string host = "127.0.0.1";
    int port = 23333;

    for(int i=0; i<argc; ++i){
        if(strcmp(argv[i], "debug")){
            debugMode = true;
            cout<<"Debug mode enabled"<<endl;
        }else if(strcmp);
    }
    Engine* engine = Engine.getInstance();
    engine->startEngine(debugMode, host, port);
    return 0;
}