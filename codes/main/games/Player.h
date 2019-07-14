/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _PLAYER_H
#define _PLAYER_H
#include <string>
#include "../../tools/Color.h"
#include "../configs/PlayerConfiguration.h"
using std::string;

class Bomber;
class Carrier;
class Fighter;
class Engine;

class Player {
    public:  
        /**
         * 构造函数
         * @param config 配置项
         */
        Player(PlayerConfiguration* const config);

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
        Carrier* getCarrier() const;
            
        /**
         * 返回其第index个轰炸机的指针
         * @param index 索引值
         * @return 轰炸机
         */
        Bomber* getBomber(const int index) const;
            
        /**
         * 返回其第index个战斗机的指针
         * @param index 索引值
         * @return 战斗机
         */
        Fighter* getFighter(const int index) const;

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
        Carrier* carrier;
        Bomber* bombers[3];
        Fighter* fighters[5];
        int power;
};

#endif //_PLAYER_H
