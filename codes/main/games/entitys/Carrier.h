/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _CARRIER_H
#define _CARRIER_H

#include "LivingEntity.h"
#include "../../configs/CarrierConfiguration.h"
#include "../conceptions/Nuke.h"
#include "../conceptions/Weapon.h"
using std::enable_shared_from_this;

class Player;

class Carrier: public LivingEntity {
    public:
        /**
         * 构造函数
         * @param player 所属玩家方
         * @param config 母舰配置项
         * @param parentEntity 父实体
         * @param x x坐标
         * @param y y坐标
         */
        Carrier(shared_ptr<Player> const player, shared_ptr<CarrierConfiguration> const config,
         shared_ptr<Entity> const parentEntity = nullptr, const double x = 0, const double y = 0);
            
        /**
         * 析构函数
         */
        ~Carrier();
         
        /**
         * 视野内的实体
         */
        virtual vector<shared_ptr<Entity>> see() const;
            
        /**
         * 判断实体是否在视野内
         * @param ano 实体
         */
        virtual bool isInSight(const Entity& ano) const;
            
        /**
         * 射击
         * @param direction 方向，以y轴正半轴为0，逆时针为正，弧度制
         */
        virtual bool shoot(const double direction) const;
            
        /**
         * 发射必杀武器
         * @param direction 方向，以y轴正半轴为0，逆时针为正，弧度制
         */
        bool shootGodWeapon(const  double direction) const;

        /**
         * 将实体以字符串显示
         * @return 字符串
         */
        virtual string toString() const;

        /**
         * 获取类型名称
         * @return 类型名称
         */
        virtual string getClassName() const;

        /**
         * 初始化行为
         */
        virtual void init();
    private:
        //主武器
        shared_ptr<Weapon> mainWeapon;
        //必杀武器，只能使用一次
        shared_ptr<Nuke> godWeapon;
        shared_ptr<CarrierConfiguration> config;
};

#endif //_CARRIER_H
