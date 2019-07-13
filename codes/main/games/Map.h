/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _MAP_H
#define _MAP_H

#include "../configs/MapConfiguration.h"
#include "../../tools/Point2D.h"
#include "./entitys/Entity.h"

class Map {
    public:
        /**
         * 构造函数
         * @param 地图配置项
         */
        Map(MapConfiguration* const config);

        /**
         * 析构函数
         */
        ~Map();

        /**
         * 获取地图高度
         * @return 高度
         */
        double getHeight() const;

        /**
         * 获取地图宽度
         * @return 宽度
         */
        double getWidth() const;

        /**
         * 判断实体是否位于地图中
         * @param entity 实体
         * @return 是否位于地图中
         */
        bool isEntityInMap(const Entity& entity) const;

        /**
         * 获取地图允许的最大玩家数
         * @return 允许的最大玩家数
         */
        int getMaxPlayersAllowed() const;

        /**
         * 获取出生点中心
         * @param index 出生点编号
         * @return 出生点
         */
        Point2D getBrithPoint(const int index) const;
    private:
        double height;
        double width;
        int maxPlayersAllowed;
        const Point2D* birthPoints;
};

#endif //_MAP_H