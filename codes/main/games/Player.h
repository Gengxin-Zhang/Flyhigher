/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _PLAYER_H
#define _PLAYER_H
#include "../../tools/Color.h"
#include "../configs/PlayerConfiguration.h"
#include "./entitys/Carrier.h"
#include "./entitys/Bomber.h"
#include "./entitys/Fighter.h"

using std::enable_shared_from_this;

class Engine;
class Logger;

class Player: public enable_shared_from_this<Player> {
    public:  
        /**
         * 构造函数
         * @param config 配置项
         */
        Player(shared_ptr<PlayerConfiguration> const config, const Point2D startPoint);

        /**
         * 析构函数
         */
        ~Player();

        /**
         * 初始化状态
         */
        void init();

        /**
         * 获得胜利
         */
        void win();

        /**
         * 游戏失败
         */
        void lose();

        /**
         * 返回其母舰指针
         * @return 母舰
         */
        shared_ptr<Carrier> getCarrier() const;
            
        /**
         * 返回其第index个轰炸机的指针
         * @param index 索引值
         * @return 轰炸机
         */
        shared_ptr<Bomber> getBomber(const int index) const;
            
        /**
         * 返回其第index个战斗机的指针
         * @param index 索引值
         * @return 战斗机
         */
        shared_ptr<Fighter> getFighter(const int index) const;

        /**
         * 获取玩家名
         * @return 玩家名
         */  
        string getName() const;

        /**
         * 获取玩家颜色
         * @return 玩家颜色
         */  
        Color getColor() const;
            
        /**
         * 增加一定资源值
         * @param power 资源值
         */
        void addPower(const int power);
            
        /**
         * 消耗一定资源值
         * @param power 资源值
         * @return 减少是否成功
         */
        bool subPower(const int power);
    private: 
        string name;
        Color color;
        shared_ptr<Carrier> carrier;
        shared_ptr<Bomber> bombers[3];
        shared_ptr<Fighter> fighters[5];
        int power;
        Point2D startPoint;
        shared_ptr<PlayerConfiguration> config;
};

#endif //_PLAYER_H
