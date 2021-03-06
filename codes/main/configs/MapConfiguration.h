/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _MAPCONFIGURATION_H
#define _MAPCONFIGURATION_H

#include "../../tools/Point2D.h"

class MapConfiguration {
    public: 
        /**
         * 构造函数
         * @param height 高度
         * @param width 宽度
         * @param maxPlayer 最大玩家数
         * @param birthPoints 出生点
         */
        MapConfiguration(const int height, const int width, const int maxPlayer, Point2D* birthPoints);

        /**
         * 析构函数
         */
        ~MapConfiguration();

        /**
         * 获取地图高度
         * @return 地图高度
         */
        int getHeight() const;

        /**
         * 获取地图宽度
         * @return 地图宽度
         */
        int getWidth() const;

        /**
         * 获取最大玩家数
         * #return 最大玩家数
         */
        int getMaxPlayer() const;

        /**
         * 获取出生点
         * @return 出生点数组
         */
        Point2D* getBirthPoints() const;
    private: 
        int height;
        int width;
        int maxPlayer;
        Point2D* birthPoints;
};

#endif //_MAPCONFIGURATION_H
