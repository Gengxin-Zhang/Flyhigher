/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _POINT2D_H
#define _POINT2D_H

class Point2D {
    public: 
        /**
         * 无参构造函数，默认（0，0）点
         */
        Point2D();
            
        /**
         * 构造函数
         * @param x x坐标
         * @param y y坐标
         */
        Point2D(const double x, const double y);
            
        /**
         * 拷贝构造函数
         * @param ano 另一个点
         */
        Point2D(const Point2D& ano);
            
        /**
         * 到另一个点的距离
         * @param ano 另一个点
         */
        double distanceTo(const Point2D& ano) const;

        /**
         * 获取x坐标
         * @return x坐标
         */
        double getX() const;

        /**
         * 获取y坐标
         * @return y坐标
         */
        double getY() const;
            
        /**
         * 向x方向移动一个距离
         * @param x 距离
         */
        void moveX(const double x);
            
        /**
         * 向y方向移动一个距离
         * @param y 距离
         */
        void moveY(const double y);
    private: 
        double x;
        double y;
};

#endif //_POINT2D_H