#include "ResourceEntityGenerator.h"
#include "../systems/Engine.h"
#include "./entitys/LargeStar.h"
#include "./entitys/LittleStar.h"
#define loop Engine::getInstance()->getNowGame()->getLoop()
#define map Engine::getInstance()->getNowGame()->getMap()
#define config Configuration::getInstance()

ResourceEntityGenerator::ResourceEntityGenerator()
{
    srand(time(0));
}

void ResourceEntityGenerator::generate(const int nowResourceEntityNumber){
    const int MAX_ALLOW = 100;
    for(int i=0; i<MAX_ALLOW-nowResourceEntityNumber; ++i){
        int a = rand()%4;
        if(a){
            generateLittle();
        }else{
            generateLarge();
        }
    }
}

void ResourceEntityGenerator::generateLittle(){
    int h = map->getHeight();
    int w = map->getWidth();
    int x = rand()%(w-20) + 10;
    int y = rand()%(h-20) + 10;
    shared_ptr<LittleStar> re = shared_ptr<LittleStar>(new LittleStar(config->getGameConfiguration()->getLittleStarConfig(), x, y));
    loop->addResourceEntity(re);
}

void ResourceEntityGenerator::generateLarge(){
    int h = map->getHeight();
    int w = map->getWidth();
    int x = rand()%(w-20) + 10;
    int y = rand()%(h-20) + 10;
    shared_ptr<LargeStar> re = shared_ptr<LargeStar>(new LargeStar(config->getGameConfiguration()->getLargeStarConfig(), x, y));
    loop->addResourceEntity(re);
}
