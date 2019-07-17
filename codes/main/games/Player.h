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
#include <map>
using std::enable_shared_from_this, std::map;

class Player: public enable_shared_from_this<Player> {
    public:  
        /**
         * 构造函数
         * @param config 配置项
         */
        Player(shared_ptr<PlayerConfiguration> const config);

        /**
         * 析构函数
         */
        ~Player();

        /**
         * 初始化状态
         */
        void init(const string uid, const string name, const Color color, const Point2D startPoint);

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
         * 返回指定uid轰炸机的指针
         * @param uid 唯一ID
         * @return 轰炸机
         */
        shared_ptr<Bomber> getBomber(const int uid);
            
        /**
         * 返回指定uid战斗机的指针
         * @param uid 唯一ID
         * @return 战斗机
         */
        shared_ptr<Fighter> getFighter(const int uid);

        /**
         * 返回所有轰炸机的组成的map
         * @return 轰炸机们
         */
        map<int, shared_ptr<Bomber>> getBombers() const;

        /**
         * 返回所有战斗机的组成的map
         * @return 战斗机们
         */
        map<int, shared_ptr<Fighter>> getFighters() const;

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

        /**
         * 建造一个战斗机
         * @return 操作是否成功
         */
        bool build();

        /**
         * 建造完毕
         */
        void buildCompletely();

        /**
         * 建造是否完成
         * @return 建造是否完成
         */
        bool isBuildFinished() const;

        /**
         * 是否允许母舰周围的自动回复生命值
         * @return 是否允许
         */
        bool isAllowHeal() const;

        /**
         * 设置是否允许母舰周围的自动回复生命值
         * @param allowHeal 是否允许
         */
        void setAllowHeal(const bool allowHeal);


        /**
         * 获取Player的唯一ID
         * @param uid 唯一ID
         */
        string getUID() const;

        int getPower() const;
        bool getBuilding() const;

        int getRemainBuildTick() const;
    private: 
        bool isBuilding;
        long buildStartTick;
        long buildEndTick;
        string uid;
        string name;
        Color color;
        shared_ptr<Carrier> carrier;
        map<int, shared_ptr<Bomber>> bombers;
        map<int, shared_ptr<Fighter>> fighters;
        int power;
        Point2D startPoint;
        shared_ptr<PlayerConfiguration> config;
        bool allowHeal;
};

#endif //_PLAYER_H
