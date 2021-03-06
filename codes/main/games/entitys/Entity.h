/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _ENTITY_H
#define _ENTITY_H

#include "../../../tools/Vector2D.h"
#include <memory>
using std::shared_ptr;

class Entity {
    public: 
        /**
         * 构造函数
         * @param radius 碰撞半径
         * @param parentEntity 父实体指针
         * @param x x坐标
         * @param y y坐标
         */
        Entity(const double radius, shared_ptr<Entity> const parentEntity = nullptr,
               const double x = 0, const double y = 0);
            
        /**
         * 获取父类对象
         */
        shared_ptr<Entity> getParentEntity() const;
            
        /**
         * 获取x坐标
         */
        double getX() const;
            
        /**
         * 设置x坐标
         * @param x x坐标
         */
        void setX(const double x);
            
        /**
         * 获取y坐标
         */
        double getY() const;
            
        /**
         * 设置y坐标
         * @param y y坐标
         */
        void setY(const double y);

        /**
         * 获取坐标的点对象表示
         * @return 点对象
         */
        Point2D getPoint() const;
            
        /**
         * 获取碰撞半径
         */
        double getRadius() const;
            
        /**
         * 是否与另一个实体外切
         * @param ano 另一个实体
         * @return 是否外切
         */
        bool isTangency(const Entity& ano) const;
        
        /**
         * 是否与另一个实体内切
         * @param ano 另一个实体
         */
        bool isInscribed(const Entity& ano) const;
        
        /**
         * 是否与另一个实体交叉（相切也算作一种交叉）
         * @param ano 另一个实体
         */
        bool isOverlapped(const Entity& ano) const;
            
        /**
         * 是否被另一个实体完全包含
         * @param ano 另一个实体
         */
        bool isContained(const Entity& ano) const;
            
        /**
         * 是否和另一个实体相离
         * @param ano 另一个实体
         */
        bool isDisjointed(const Entity& ano) const;
            
        /**
         * 是否包含另一个实体
         * @param ano 另一个实体
         */
        bool contains(const Entity& ano) const;
            
        /**
         * 求此实体中心到另一个实体中心的距离
         * @param ano 另一个实体
         */
        double getDistance(const Entity& ano) const;
            
        /**
         * 求两个实体之间的相对角度，采用弧度制，以指向地图正上方为0 rads
         * @param ano 另一个实体
         */
        double getRelativeAngle(const Entity& ano) const;
            
        /**
         * 从此实体出发，构建一个指向参数实体的向量
         * @param ano 另一个实体
         */
        Vector2D toVector2D(const Entity& ano) const;
            
        /**
         * 将实体以字符串显示
         * @return 字符串
         */
        virtual string toString() const;

        /**
         * 设置实体的位置
         * @param p 位置的点坐标表示
         */
        void setPoint(const Point2D p);
        
        /**
         * 析构函数
         */
        virtual ~Entity();

        /**
         * 获取类型名称
         * @return 类型名称
         */
        virtual string getClassName() const;

        /**
         * 获取UID（实体唯一ID）
         * @return UID
         */
        int getUID() const;
        static int total_id;
    private: 
        int uid;
        //父实体
        shared_ptr<Entity> parentEntity;
        //x坐标
        double x;
        //y坐标
        double y;
        //碰撞半径，实体当做圆
        double radius;
};

#endif //_ENTITY_H
