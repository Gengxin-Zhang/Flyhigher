/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _LOGGER_H
#define _LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
using std::ofstream, std::cout, std::endl, std::string;

class Logger {
    public:
        /**
         * 根据记录文件的路径构建Logger对象
         * @param file 路径
         */
        Logger(const string file);

        /**
         * 析构函数
         */
        ~Logger();
            
        /**
         * 输出debug信息
         * @param str 文字说明
         * @param num 数字变量
         */
        void debug(const string str, const long num);
            
        /**
         * 输出debug信息
         * @param str 文字说明
         * @param num 数字变量
         */
        void debug(const string str, const int num);

        /**
         * 输出debug信息
         * @param str 文字说明
         */
        void debug(const string str);
            
        /**
         * 输出debug信息
         * @param str 文字说明
         * @param flag 布尔变量
         */
        void debug(const string str, const bool flag);
            
        /**
         * 输出info信息
         * @param str 文字说明
         * @param num 数字变量
         */
        void information(const string str, const long num);

        /**
         * 输出info信息
         * @param str 文字说明
         * @param num 数字变量
         */
        void information(const string str, const int num);
            
        /**
         * 输出info信息
         * @param str 文字说明
         */
        void information(const string str);
            
        /**
         * 输出info信息
         * @param str 文字说明
         * @param flag 布尔变量
         */
        void information(const string str, const bool flag);
            
        /**
         * 输出warn信息
         * @param str 文字说明
         * @param num 数字变量
         */
        void warning(const string str, const long num);
            
        /**
         * 输出warn信息
         * @param str 文字说明
         * @param num 数字变量
         */
        void warning(const string str, const int num);

        /**
         * 输出warn信息
         * @param str 文字说明
         */
        void warning(const string str);
            
        /**
         * 输出warn信息
         * @param str 文字说明
         * @param flag 布尔变量
         */
        void warning(const string str, const bool flag);
            
        /**
         * 输出severe信息
         * @param str 文字说明
         * @param num 数字变量
         */
        void severe(const string str, const long num);

        /**
         * 输出severe信息
         * @param str 文字说明
         * @param num 数字变量
         */
        void severe(const string str, const int num);
            
        /**
         * 输出severe信息
         * @param str 文字说明
         */
        void severe(const string str);
            
        /**
         * 输出severe信息
         * @param str 文字说明
         * @param flag 布尔变量
         */
        void severe(const string str, const bool flag);

        ofstream& getOut();
    private: 
        void out_time();
        ofstream out;
};

#endif //_LOGGER_H
