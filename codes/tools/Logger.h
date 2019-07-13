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
        Logger(string file);

        /**
         * 析构函数
         */
        ~Logger();
            
        /**
         * @param num
         */
        void debug(int num);
            
        /**
         * @param str
         */
        void debug(string str);
            
        /**
         * @param flag
         */
        void debug(bool flag);
            
        /**
         * @param num
         */
        void infomation(int num);
            
        /**
         * @param str
         */
        void infomation(string str);
            
        /**
         * @param flag
         */
        void infomation(bool flag);
            
        /**
         * @param num
         */
        void warning(int num);
            
        /**
         * @param str
         */
        void warning(string str);
            
        /**
         * @param flag
         */
        void warning(bool flag);
            
        /**
         * @param num
         */
        void severe(int num);
            
        /**
         * @param str
         */
        void severe(string str);
            
        /**
         * @param flag
         */
        void severe(bool flag);
    private: 
        ofstream out;
};

#endif //_LOGGER_H