/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _LARGESTAR_H
#define _LARGESTAR_H

#include "ResourceEntity.h"
#include "../../configs/LargeStarConfiguration.h"


class LargeStar: public ResourceEntity {
    public: 
        /**
         * 构造函数
         * @param config
         */
        LargeStar(LargeStarConfiguration* const config);

        /**
         * 获取类型名称
         * @return 类型名称
         */
        virtual string getClassName() const;

        /**
         * 将实体以字符串显示
         * @return 字符串
         */
        virtual string toString() const;
            
        /**
         * 析构函数
         */
        ~LargeStar();
};

#endif //_LARGESTAR_H
