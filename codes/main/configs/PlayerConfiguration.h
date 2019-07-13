/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _PLAYERCONFIGURATION_H
#define _PLAYERCONFIGURATION_H

#include <string>
#include "../../../tools/Color.h"
using std::string;

class PlayerConfiguration {
    public: 
        /**
         * 构造函数
         * @param name 名字
         * @param color 颜色
         */
        PlayerConfiguration(const string name, const Color color);

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
    private: 
        String name;
        Color color;
};

#endif //_PLAYERCONFIGURATION_H