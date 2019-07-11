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
void Vector2D();
    
/**
 * 根据给定x,y坐标构造向量
 * @param x
 * @param y
 */
void Vector2D(double x, double y);
    
/**
 * 拷贝构造函数
 * @param ano
 */
void Vector2D(Vector2D ano);
    
/**
 * 获取x坐标
 */
double getX();
    
/**
 * 获取y坐标
 */
double getY();
    
/**
 * 加上另一个向量，生成一个新向量
 * @param ano
 */
Vector2D plus(Vector2D ano);
    
/**
 * 减去另一个向量，生成一个新向量
 * @param ano
 */
Vector2D minus(Vector2D ano);
    
/**
 * 与另一个向量进行向量积，生成一个新向量
 * @param ano
 */
double multiply(Vector2D ano);
    
/**
 * 与一个数字进行数量积，生成一个新向量
 * @param lambda
 */
Vector2D multiply(double lambda);
    
/**
 * 生成一个新的反向向量
 */
Vector2D reverse();
    
/**
 * 生成一个新的向量，表示方向向量
 */
Vector2D getDirection();
    
/**
 * 获取向量的模（长度）
 */
double getModule();
    
/**
 * 获取同另一个向量的夹角余弦
 * @param ano Vector2D
 */
double getCosineWith(void ano Vector2D);
    
/**
 * 生成新向量表示此向量旋转固定角度的结果，顺时针为正
 * @param rad double
 */
Vector2D rotate(void rad double);
private: 
    /**
 * x坐标
 */
double x;
    /**
 * y坐标
 */
double y;
};

#endif //_VECTOR2D_H