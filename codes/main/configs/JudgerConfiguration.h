/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _JUDGERCONFIGURATION_H
#define _JUDGERCONFIGURATION_H

class JudgerConfiguration {
    public:
        /**
         * 构造函数
         * @param maxTimeout 允许的最大超时时间
         */
        JudgerConfiguration(const int maxTimeout);

        /**
         * 析构函数
         */
        ~JudgerConfiguration();

        /**
         * 获取最大超时时间
         * @return 超时时间
         */
        int getMaxTimeout() const;
    private:
       int maxTimeout;
};

#endif //_JUDGERCONFIGURATION_H
