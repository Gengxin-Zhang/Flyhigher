/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _VECTOR2D_H
#define _VECTOR2D_H

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
    private: 
        //x坐标
        double x;
        //y坐标
        double y;
};

#endif //_VECTOR2D_H