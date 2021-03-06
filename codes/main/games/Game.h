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
#include <map>
#include "ResourceEntityGenerator.h"

class Engine;

class Game {
    public:
        std::shared_ptr<Player>* tmp_players;
        /**
         * 构造函数
         * @param config 配置项
         */
        Game(shared_ptr<GameConfiguration> const config);
        
        /**
         * 析构函数
         */
        ~Game();
        
        /**
         * 开始游戏
         */
        int run();

        /**
         * 获取地图实例
         * @return 地图
         */
        shared_ptr<Map> getMap() const;

        /**
         * 获取裁判实例
         * @return 裁判
         */
        shared_ptr<Judger> getJudger() const;

        /**
         * 获取主循环实例
         * @return 主循环
         */
        shared_ptr<Loop> getLoop() const;

        /**
         * 获取玩家实例
         * @param name 玩家UID
         * @return 玩家实例
         */
        shared_ptr<Player> getPlayer(const string uid);

        /**
         * 获取当前玩家数
         * @return 玩家个数
         */
        int getPlayerNumber() const;

        /**
         * 获取全部玩家
         * @return 全部玩家
         */
        std::map<string, shared_ptr<Player>> getPlayers();

        /**
         * 获取资源生成器
         * @return 资源生成器
         */
        std::shared_ptr<ResourceEntityGenerator> getResourceGenerator();
    private:
        
        int player_num;
        shared_ptr<Loop> loop;
        shared_ptr<Map> map;
        shared_ptr<Judger> judger;
        std::map<string, shared_ptr<Player>> players;
        std::shared_ptr<ResourceEntityGenerator> resourceGenerator;
};

#endif //_GAME_H
