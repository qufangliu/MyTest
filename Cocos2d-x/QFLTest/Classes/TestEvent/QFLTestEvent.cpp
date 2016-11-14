//
//  QFLTestEvent.cpp
//  QFLTest
//
//  Created by QuFangliu on 2016/10/28.
//
//

#include "QFLTestEvent.hpp"

USING_NS_CC;

QFLTestEvent::QFLTestEvent()
{
    m_pUINode = nullptr;    //注意，这里要进行初始化，否则是野指针
}

QFLTestEvent::~QFLTestEvent()
{
    Vector<<#class T#>>
}

void QFLTestEvent::enterTest()
{
    this->addUI();  //添加测试按钮
}

void QFLTestEvent::addUI()
{
    //在屏幕下部添加三个按钮
    auto pMenu = Menu::create();
    pMenu->setPosition(Vec2::ZERO);
    this->addChild(pMenu);
    
    //添加UI
    auto pBtnAddUI = MenuItemFont::create("AddUI", [=](Ref*){
        //因为这里并不需要用到Ref这个参数，所以直接lambda表达式解决
        this->addEventUI();
    });
    pBtnAddUI->setPosition(SCREEN_CENTER + Vec2(-80, -100));
    pMenu->addChild(pBtnAddUI);
    
    //删除UI
    auto pBtnRemoveUI = MenuItemFont::create("RemoveUI", [=](Ref*){
        this->removeEventUI();
    });
    pBtnRemoveUI->setPosition(SCREEN_CENTER + Vec2(80, -100));
    pMenu->addChild(pBtnRemoveUI);
    
    //发送事件
    auto pBtnSendEvent = MenuItemFont::create("SendEvent", [=](Ref*){
        this->sendEvent();
    });
    pBtnSendEvent->setPosition(SCREEN_CENTER + Vec2(0, -150));
    pMenu->addChild(pBtnSendEvent);
    
    //默认要添加UI
    this->addEventUI();
}

void QFLTestEvent::addEventUI()
{
    if (m_pUINode == nullptr) {
        //生成UINode
        m_pUINode = Label::createWithSystemFont("Nothing", "Arial", 50);
        m_pUINode->setPosition(SCREEN_CENTER + Vec2(0, 100));
        this->addChild(m_pUINode);
        
        //添加监听事件,注意，这里不是直接添加到Dispatcher
        
        auto pListener = EventListenerCustom::create("QFLTestEvent", [=](EventCustom*){
            //停止action
            m_pUINode->stopAllActions();
            //显示随机数值
            m_pUINode->setString(StringUtils::format("%d", rand()));
            //2秒后还原
            m_pUINode->runAction(Sequence::create(DelayTime::create(2.0f),
                                                  CallFunc::create([=](){ m_pUINode->setString("Nothing"); }),
                                                  NULL));
        });
        
        Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(pListener, m_pUINode);
    }
    else {}
}

void QFLTestEvent::removeEventUI()
{
    if (m_pUINode != nullptr) {
        m_pUINode->removeFromParentAndCleanup(true);
        m_pUINode = nullptr;
    }
    else {}
}

void QFLTestEvent::sendEvent()
{
    Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("QFLTestEvent");
}
