//
//  QFLTimer.hpp
//  QFLTest
//
//  Created by QuFangliu on 2016/10/25.
//
//

#ifndef QFLTimer_hpp
#define QFLTimer_hpp

#include <stdio.h>
#include "cocos2d.h"

class QFLTimer : public cocos2d::Ref
{
CC_CONSTRUCTOR_ACCESS:
    QFLTimer();
    virtual ~QFLTimer();
    static QFLTimer* create();
    void initTimer();
    
public:
    //时间间隔
    void setInterval(float fInterval);
    float getInterval();
    
    //回调
    void setCallback(const std::function<void()> &funcCallback);
    std::function<void()> getCallback();
    
    //控制启动
    void start();
    void stop();
    
    void pause();
    void resume();
    
    //计时器
    void update(float dt);
    
private:
    cocos2d::Scheduler *m_pScheduler;   //借用cocos2d-x引擎提供的计时器
    
    float m_fInterval;                      //间隔时间
    float m_fTimeCounter;                   //当前已经经过的时间
    std::function<void()> m_funcCallback;   //回调函数
};

#endif /* QFLTimer_hpp */
