/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _VECTOR2D_H
#define _VECTOR2D_H

#include "Point2D.h"

class Vector2D {
    public: 
        /**
         * 无参构造函数，构造(0,0)
         */
        Vector2D();
            
        /**
         * 根据给定x,y坐标构造向量
         * @param x x坐标
         * @param y y坐标
         */
        Vector2D(const double x, const double y);
            
        /**
         * 拷贝构造函数
         * @param ano 另一个向量
         */
        Vector2D(const Vector2D& ano);

        /**
         * 根据向量长度和方向角构造向量
         * @param module 向量长度
         * @param angle 相对于y轴正半轴的方向角，逆时针为正，弧度制
         * @param has 随便给，因为避免构造函数冲突
         */
        Vector2D(const double module, const double angle, bool has);

        /**
         * 根据向量长度和方向向量构造向量
         * @param module 向量长度
         * @param direction 方向向量
         */
        Vector2D(const double module, const Vector2D& direction);

        /**
         * 根据起始点和终末点来构造向量
         * @param start 起始点
         * @param end 终末点
         */
        Vector2D(const Point2D start, const Point2D end);
            
        /**
         * 获取x坐标
         */
        double getX() const;
            
        /**
         * 获取y坐标
         */
        double getY() const;
            
        /**
         * 加上另一个向量，生成一个新向量
         * @param ano 另一个向量
         */
        Vector2D plus(const Vector2D& ano) const;
            
        /**
         * 减去另一个向量，生成一个新向量
         * @param ano 另一个向量
         */
        Vector2D minus(const Vector2D& ano) const;
            
        /**
         * 与另一个向量进行向量积，生成一个新向量
         * @param ano 另一个向量
         */
        double multiply(const Vector2D& ano) const;
            
        /**
         * 与一个数字进行数量积，生成一个新向量
         * @param lambda 数
         */
        Vector2D multiply(const double lambda) const;
            
        /**
         * 生成一个新的反向向量
         */
        Vector2D reverse() const;
            
        /**
         * 生成一个新的向量，表示方向向量
         */
        Vector2D getDirection() const;
            
        /**
         * 获取向量的模（长度）
         */
        double getModule() const;
            
        /**
         * 获取同另一个向量的夹角余弦
         * @param ano 另一个向量
         */
        double getCosineWith(const Vector2D& ano) const;
            
        /**
         * 生成新向量表示此向量旋转固定角度的结果，逆时针为正
         * @param rad 旋转的弧度，逆时针为正
         */
        Vector2D rotate(const double rad) const;

        /**
         * 由基点沿着向量移动获得新的点
         * @param basePoint 基点
         * @return 结果点
         */
        Point2D toPoint2D(const Point2D basePoint) const;

        /**
         * 获取类型名称
         * @return 类型名
         */
        virtual string getClassName() const;

        /**
         * 字符串表达
         * @return 字符串
         */
        virtual string toString() const;
    private: 
        //x坐标
        double x;
        //y坐标
        double y;
};

#endif //_VECTOR2D_H
