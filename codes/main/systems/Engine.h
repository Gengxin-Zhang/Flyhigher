/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _ENGINE_H
#define _ENGINE_H

#include <string>
#include <exception>
#include "../../tools/Logger.h"
#include "../configs/Configuration.h"
using std::string, std::invalid_argument;

class Engine {
    public:
        /**
         * 析构函数
         */
        ~Engine();
        
        /**
         * 启动主进程
         * @param debugMode 是否启用debug模式
         */
        void startEngine(const bool debugMode);
            
        /**
         * 注册Logger
         * @param logger 记录器
         */
        void registerLogger(Logger* const logger);

        /**
         * 返回Logger
         * @return logger 记录器
         */
        Logger* getLogger() const;

        /**
         * 获取单例模式的Engine的实例
         * @return 实例
         */
        static Engine* getInstance();

        /**
         * 当前是否debug模式
         */
        static bool isDebugMode();
    private:
        /**
         * 构造函数
         */
        Engine();

        /**
         * 是否处于debug模式
         * @return 是否
         */
        bool onDebugMode() const;

        Logger* logger;
        string workDir;
        Configuration* totalConfig;
        static Engine* engine;
        static bool hasInit;
        bool hasStarted;
        bool debugMode;
};

#endif //_ENGINE_H
