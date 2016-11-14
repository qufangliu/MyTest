//
//  QFLTestEvent.hpp
//  QFLTest
//
//  Created by QuFangliu on 2016/10/28.
//
//
/*
 用于测试绑定Node的EventListener
 Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(EventListener* listener, Node* node)
 当UI被删除时，对应的事件也会消失
 */

#ifndef QFLTestEvent_hpp
#define QFLTestEvent_hpp

#include <stdio.h>
#include "QFLTestBase.hpp"

class QFLTestEvent : public QFLTestBase
{
public:
    QFLTestEvent();
    virtual ~QFLTestEvent();
    CREATE_FUNC(QFLTestEvent);
    
private:
    virtual void enterTest() override;
    
    void addUI();

    void addEventUI();      //添加监听了事件的UI
    void removeEventUI();   //删除这个UI
    void sendEvent();       //发送事件
    
private:
    cocos2d::Label* m_pUINode;
    
};

#endif /* QFLTestEvent_hpp */
