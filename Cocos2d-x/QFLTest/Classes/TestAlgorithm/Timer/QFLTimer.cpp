//
//  QFLTimer.cpp
//  QFLTest
//
//  Created by QuFangliu on 2016/10/25.
//
//

#include "QFLTimer.hpp"

USING_NS_CC;

QFLTimer::QFLTimer()
{
    m_fInterval = 0.0f;
    m_fTimeCounter = 0.0f;
}

QFLTimer::~QFLTimer()
{
    
}

QFLTimer* QFLTimer::create()
{
    QFLTimer *pTimer = new(std::nothrow) QFLTimer();
    if (pTimer) {
        pTimer->autorelease();
        return pTimer;
    }
    else {
        CC_SAFE_DELETE(pTimer);
        return nullptr;
    }
}

void QFLTimer::initTimer()
{
    //保存Scheduler
    m_pScheduler = Director::getInstance()->getScheduler();
}

//时间间隔
void QFLTimer::setInterval(float fInterval)
{
    m_fInterval = fInterval;
}
float QFLTimer::getInterval()
{
    return m_fInterval;
}

//回调
void QFLTimer::setCallback(const std::function<void()> &funcCallback)
{
    m_funcCallback = funcCallback;
}
std::function<void()> QFLTimer::getCallback()
{
    return m_funcCallback;
}

//控制启动
void QFLTimer::start()
{
    m_pScheduler->scheduleUpdate(this, 1, false);
}
void QFLTimer::stop()
{
    m_pScheduler->unscheduleUpdate(this);
}

void QFLTimer::pause()
{
    m_pScheduler->pauseTarget(this);
}
void QFLTimer::resume()
{
    m_pScheduler->resumeTarget(this);
}

//计时器
void QFLTimer::update(float dt)
{
    //计时
    m_fTimeCounter += dt;
    
    //判断是否响应
    if (m_fTimeCounter >= m_fInterval) {
        //恢复时间
        m_fTimeCounter -= m_fInterval;
        //回调
        if (m_funcCallback) {
            m_funcCallback();
        }
        else {}
    }
    else {}
}










