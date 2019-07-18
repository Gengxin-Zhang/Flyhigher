/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _MAP_H
#define _MAP_H

#include "../configs/MapConfiguration.h"
#include "./entitys/Entity.h"
#include <vector>
using std::vector;

class Map {
    public:
        /**
         * 构造函数
         * @param 地图配置项
         */
        Map(shared_ptr<MapConfiguration> const config);

        /**
         * 析构函数
         */
        ~Map();

        /**
         * 获取地图高度
         * @return 高度
         */
        int getHeight() const;

        /**
         * 获取地图宽度
         * @return 宽度
         */
        int getWidth() const;

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
         * 获取随机出生点中心（注意：每次调用此函数返回值不同，只允许一个player调用一次）
         * @return 出生点
         */
        Point2D getBrithPoint();
    private:
        /**
         * 获取不重复随机值，用于随机出生点
         * @return 随机出生点的序号
         */
        int getRandperm();
        int height;
        int width;
        int maxPlayersAllowed;
        const Point2D* birthPoints;
        vector<int> temp;
        int inx;
};

#endif //_MAP_H
