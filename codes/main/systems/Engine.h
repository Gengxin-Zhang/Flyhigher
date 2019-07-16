/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _ENGINE_H
#define _ENGINE_H

#include <exception>
#include "../../tools/Logger.h"
#include "../configs/Configuration.h"
#include "../games/Game.h"
#include <thread>
using std::invalid_argument, std::thread;

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
        void registerLogger(shared_ptr<Logger> const logger);

        /**
         * 返回Logger
         * @return logger 记录器
         */
        shared_ptr<Logger> getLogger() const;

        /**
         * 获取单例模式的Engine的实例
         * @return 实例
         */
        static shared_ptr<Engine> getInstance();

        /**
         * 当前是否debug模式
         * @return debug模式
         */
        static bool isDebugMode();

        /**
         * 开始一场游戏
         * @param config 游戏配置项
         */
        void startGame(shared_ptr<GameConfiguration> const config);

        /**
         * 获取当前进行的游戏
         * @return 游戏
         */
        shared_ptr<Game> getNowGame() const;

        /**
         * 关闭引擎
         */
        void shutdown() const;
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


        shared_ptr<Logger> logger;
        string workDir;
        shared_ptr<Configuration> totalConfig;
        static shared_ptr<Engine> engine;
        static bool hasInit;
        bool hasStarted;
        bool debugMode;
        shared_ptr<Game> nowGame;
        shared_ptr<thread> nowGameThread;
        bool hasNowGame;
};

#endif //_ENGINE_H
