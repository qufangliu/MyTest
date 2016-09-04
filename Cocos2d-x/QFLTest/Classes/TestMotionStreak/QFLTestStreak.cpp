//
//  QFLTestStreak.cpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/4.
//
//

#include "QFLTestStreak.hpp"

#include "QFLTools/QFLHelper.hpp"

USING_NS_CC;

QFLTestMotionStreak::QFLTestMotionStreak()
{
    m_pStreak = nullptr;
}

QFLTestMotionStreak::~QFLTestMotionStreak()
{
    
}

bool QFLTestMotionStreak::init()
{
    if (!Layer::init()) {
        return false;
    }
    else {
        this->addUI();
        return true;
    }
}

void QFLTestMotionStreak::addUI()
{
    //添加黑色背景
    this->addChild(QFL_HELPER->getBlackBGLayer(), -1);//注意，如果这里层级为0，那就没得玩了
    //添加返回按钮
    QFL_HELPER->addBackMenu(this);
    
    //添加触摸监听
    auto pListener = EventListenerTouchOneByOne::create();
    pListener->onTouchBegan = CC_CALLBACK_2(QFLTestMotionStreak::onTouchBegan, this);
    pListener->onTouchMoved = CC_CALLBACK_2(QFLTestMotionStreak::onTouchMoved, this);
    pListener->onTouchEnded = CC_CALLBACK_2(QFLTestMotionStreak::onTouchEnded, this);
    pListener->onTouchCancelled = CC_CALLBACK_2(QFLTestMotionStreak::onTouchEnded, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(pListener, this);
    
    //添加MotionStreak，给MotionStreak设置Position时就会有拖尾效果
    m_pStreak = MotionStreak::create(1.0f, 0.1f, 20.0f, Color3B(0xBE, 0xFF, 0xF7), "TestMotionStreak/Images/streak.png");
    m_pStreak->setPosition(SCREEN_CENTER);
    this->addChild(m_pStreak);
    
    this->playStreak();
}

void QFLTestMotionStreak::playStreak()
{
    //停止之前的Action
    m_pStreak->stopAllActions();
    
    //开始新的移动啊
    auto vecPos = Vec2(rand() % (int)SCREEN_VISIBLE_SIZE.width, rand() % (int)SCREEN_VISIBLE_SIZE.height);
    auto pAction = Sequence::create(MoveTo::create(2.0f, vecPos),
                                    CallFunc::create(CC_CALLBACK_0(QFLTestMotionStreak::playStreak, this)),
                                    NULL);
    m_pStreak->runAction(pAction);
}

bool QFLTestMotionStreak::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
    m_pStreak->setPosition(pTouch->getLocation());
    return true;
}

void QFLTestMotionStreak::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
    m_pStreak->setPosition(pTouch->getLocation());
}

void QFLTestMotionStreak::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
    this->playStreak();
}