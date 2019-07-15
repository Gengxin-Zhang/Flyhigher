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
         * @param num
         */
        void debug(const string str, const long num);
            
        /**
         * @param num
         */
        void debug(const string str, const int num);

        /**
         * @param str
         */
        void debug(const string str);
            
        /**
         * @param flag
         */
        void debug(const string str, const bool flag);
            
        /**
         * @param num
         */
        void infomation(const string str, const long num);

        /**
         * @param num
         */
        void infomation(const string str, const int num);
            
        /**
         * @param str
         */
        void infomation(const string str);
            
        /**
         * @param flag
         */
        void infomation(const string str, const bool flag);
            
        /**
         * @param num
         */
        void warning(const string str, const long num);
            
        /**
         * @param num
         */
        void warning(const string str, const int num);

        /**
         * @param str
         */
        void warning(const string str);
            
        /**
         * @param flag
         */
        void warning(const string str, const bool flag);
            
        /**
         * @param num
         */
        void severe(const string str, const long num);

        /**
         * @param num
         */
        void severe(const string str, const int num);
            
        /**
         * @param str
         */
        void severe(const string str);
            
        /**
         * @param flag
         */
        void severe(const string str, const bool flag);
    private: 
        void out_time();
        ofstream out;
};

#endif //_LOGGER_H
