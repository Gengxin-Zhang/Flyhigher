/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _GAME_H
#define _GAME_H

#include "../configs/GameConfiguration.h"
#include "Loop.h"
#include "Judger.h"
#include "Map.h"
#include "Player.h"
#include <string>
#include <cstring>
#include <map>
using std::string;

class Engine;
class Logger;

class Game {
    public: 
        /**
         * 构造函数
         * @param config 配置项
         */
        Game(GameConfiguration* const config);
        
        /**
         * 析构函数
         */
        ~Game();
        
        /**
         * 开始游戏
         */
        void run();

        /**
         * 获取地图实例
         * @return 地图
         */
        Map* getMap() const;

        /**
         * 获取裁判实例
         * @return 裁判
         */
        Judger* getJudger() const;

        /**
         * 获取主循环实例
         * @return 主循环
         */
        Loop* getLoop() const;

        /**
         * 获取玩家实例
         * @param name 玩家名称
         * @return 玩家实例
         */
        Player* getPlayer(const string name);

        /**
         * 获取当前玩家数
         * @return 玩家个数
         */
        int getPlayerNumber() const;
    private:
        
        int player_num;
        Loop* loop;
        Map* map;
        Judger* judger;
        std::map<string, Player*> players;
};

#endif //_GAME_H
