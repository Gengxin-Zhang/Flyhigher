/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _PLAYERCONFIGURATION_H
#define _PLAYERCONFIGURATION_H

#include <string>
#include "CarrierConfiguration.h"
#include "BomberConfiguration.h"
#include "FighterConfiguration.h"
#include "../../tools/Color.h"

using std::string;

class PlayerConfiguration {
    public: 
        /**
         * 构造函数
         * @param name 名字
         * @param color 颜色
         */
        PlayerConfiguration(const string name, const Color color,
         CarrierConfiguration* const carrierConfig, BomberConfiguration* const bomberConfig,
         FighterConfiguration* const fighterConfig);

        /**
         * 析构函数
         */
        ~PlayerConfiguration();
        
        /**
         * 获取玩家名称
         * @return 玩家名
         */
        string getName() const;
        
        /**
         * 获取玩家颜色
         * @return 颜色
         */
        Color getColor() const;

        /**
         * 获取母舰配置项
         * @return 母舰配置项
         */
        CarrierConfiguration* getCarrierConfig() const;

        /**
         * 获取轰炸机配置项
         * @return 轰炸机配置项
         */
        BomberConfiguration* getBomberConfig() const;

        /**
         * 获取战斗机配置项
         * @return 战斗机配置项
         */
        FighterConfiguration* getFighterConfig() const;
    private: 
        string name;
        Color color;
        CarrierConfiguration* carrierConfig;
        BomberConfiguration* bomberConfig;
        FighterConfiguration* fighterConfig;
};

#endif //_PLAYERCONFIGURATION_H
