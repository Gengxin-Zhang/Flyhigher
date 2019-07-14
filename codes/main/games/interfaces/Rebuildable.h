/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _COLLECTOR_H
#define _COLLECTOR_H

#include "../../configs/RebuildableConfiguration.h"

class Rebuildable {
    public:

        /**
         * 重建单位
         */
        virtual void rebuild() = 0;
};

#endif //_COLLECTOR_H
