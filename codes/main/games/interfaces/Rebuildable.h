/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _REBUILDABLE_H
#define _REBUILDABLE_H

#include "../../configs/RebuildableConfiguration.h"

class Rebuildable {
    public:

        /**
         * 重建单位
         */
        virtual void rebuild() = 0;

        /**
         * 虚析构函数
         */
        virtual ~Rebuildable();
};
#endif //_REBUILDABLE_H
