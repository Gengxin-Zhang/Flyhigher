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

class Engine;

class GameConfiguration {
    public: 
        /**
         * 获取地图配置项
         * @return 地图配置项
         */
        MapConfiguration* getMapConfig() const;
        
        /**
         * 获取裁判配置项
         * @return 裁判配置项
         */
        JudgerConfiguration* getJudgerConfig() const;
        
        /**
         * 获取主循环配置项
         * @return 主循环配置项
         */
        LoopConfiguration* getLoopConfig() const;
        
        /**
         * 获取玩家个数
         * @return 玩家个数
         */
        int getPlayerNumber() const;
            
        /**
         * 获取玩家配置项
         * @param index 下标
         */
        PlayerConfiguration* getPlayersConfig(const int index) const;
            
        /**
         * 构造函数
         * @param mapConfig 地图配置项
         * @param judgerConfig 裁判配置项
         * @param loopConfig 主循环配置项
         * @param playerNumber 玩家个数
         * @param playersConfig 玩家配置项组
         */
        GameConfiguration(MapConfiguration* const mapConfig, JudgerConfiguration* const judgerConfig,
         LoopConfiguration* const loopConfig, const int playerNumber, PlayerConfiguration** playersConfig);
        
        /**
         * 析构函数
         */
        ~GameConfiguration();
private: 
    MapConfiguration* mapConfig;
    JudgerConfiguration* judgerConfig;
    LoopConfiguration* loopConfig;
    int playerNumber;
    PlayerConfiguration** playersConfig;
};

#endif //_GAMECONFIGURATION_H
