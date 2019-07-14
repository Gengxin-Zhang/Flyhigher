/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _COLOR_H
#define _COLOR_H

class Color{
    public: 
        /**
         * 获取透明度，百分整数
         * @return 透明度
         */
        int getAlpha() const;
        
        /**
         * 获取红色值
         * @return 红色值
         */
        int getR() const;

        /**
         * 获取绿色值
         * @return 红色值
         */ 
        int getG() const;

        /**
         * 获取蓝色值
         * @return 红色值
         */ 
        int getB() const;

        /**
         * 默认构造函数(0,0,0,0)
         */
        Color();
            
        /**
         * 构造函数
         * @param alpha 透明度
         * @param r 红色
         * @param g 绿色
         * @param b 蓝色
         */
        Color(const int alpha, const int r, const int g, const int b);
            
        /**
         * 拷贝构造函数
         * @param color 另一个颜色对象
         */
        Color(const Color& color);

        /**
         * 析构函数
         */  
        ~Color();
    private: 
        int alpha;
        int r;
        int g;
        int b;
};

#endif //_COLOR_H
