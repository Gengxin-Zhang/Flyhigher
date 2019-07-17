/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _GAMECONFIGURATION_H
#define _GAMECONFIGURATION_H

#include "MapConfiguration.h"
#include "JudgerConfiguration.h"
#include "LoopConfiguration.h"
#include "PlayerConfiguration.h"
#include "LargeStarConfiguration.h"
#include "LittleStarConfiguration.h"

class GameConfiguration {
    public: 
        /**
         * 获取地图配置项
         * @return 地图配置项
         */
        shared_ptr<MapConfiguration> getMapConfig() const;
        
        /**
         * 获取裁判配置项
         * @return 裁判配置项
         */
        shared_ptr<JudgerConfiguration> getJudgerConfig() const;
        
        /**
         * 获取主循环配置项
         * @return 主循环配置项
         */
        shared_ptr<LoopConfiguration> getLoopConfig() const;
        
        /**
         * 获取玩家个数
         * @return 玩家个数
         */
        int getPlayerNumber() const;
            
        /**
         * 获取玩家配置项
         */
        shared_ptr<PlayerConfiguration> getPlayerConfig() const;

        /**
         * 获取大行星配置项
         */
        shared_ptr<LargeStarConfiguration> getLargeStarConfig() const;

        /**
         * 获取小行星配置项
         */
        shared_ptr<LittleStarConfiguration> getLittleStarConfig() const;
            
        /**
         * 构造函数
         * @param mapConfig 地图配置项
         * @param judgerConfig 裁判配置项
         * @param loopConfig 主循环配置项
         * @param playerNumber 玩家个数
         * @param playerConfig 玩家配置项
         * @param largeStarConfig 大行星配置项
         * @param littleStarConfig 小行星配置项
         */
        GameConfiguration(shared_ptr<MapConfiguration> const mapConfig,
                          shared_ptr<JudgerConfiguration> const judgerConfig,
                          shared_ptr<LoopConfiguration> const loopConfig,
                          const int playerNumber, shared_ptr<PlayerConfiguration> const playerConfig,
                          shared_ptr<LargeStarConfiguration> const largeStarConfig,
                          shared_ptr<LittleStarConfiguration> const littleStarConfig);
        
        /**
         * 析构函数
         */
        ~GameConfiguration();
private: 
    shared_ptr<MapConfiguration> mapConfig;
    shared_ptr<JudgerConfiguration> judgerConfig;
    shared_ptr<LoopConfiguration> loopConfig;
    int playerNumber;
    shared_ptr<PlayerConfiguration> playerConfig;
    shared_ptr<LargeStarConfiguration> largeStarConfig;
    shared_ptr<LittleStarConfiguration> littleStarConfig;
};

#endif //_GAMECONFIGURATION_H
