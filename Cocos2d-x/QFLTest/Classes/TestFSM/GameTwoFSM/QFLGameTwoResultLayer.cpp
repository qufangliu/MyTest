//
//  QFLGameTwoResultLayer.cpp
//  QFLTest
//
//  Created by QuFangliu on 16/10/8.
//
//

#include "QFLGameTwoResultLayer.hpp"
#include "QFLTools/QFLHelper.hpp"

USING_NS_CC;

QFLGameTwoResultLayer::QFLGameTwoResultLayer()
{
    
}

QFLGameTwoResultLayer::~QFLGameTwoResultLayer()
{
    
}

bool QFLGameTwoResultLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    else {
        this->addUI();
        return true;
    }
}

void QFLGameTwoResultLayer::addUI()
{
    //黑色背景
    auto pLayer = QFL_HELPER->getColorfulLayer();
    QFL_HELPER->addNoTouchListener(pLayer);
    this->addChild(pLayer);
    
    //GameLogo
    auto pLogo = Label::createWithSystemFont("ResultLayer", "", 50);
    pLogo->setPosition(Vec2(SCREEN_CENTER.x, SCREEN_CENTER.y + 60));
    this->addChild(pLogo);
    
    //菜单
    auto pMenu = Menu::create();
    pMenu->setPosition(Vec2::ZERO);
    this->addChild(pMenu);
    
    //按钮
    auto pHome = MenuItemFont::create("Home", [=](cocos2d::Ref* pRef){
        Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(GameTwoEvent::Result_Home);
    });
    pHome->setPosition(Vec2(SCREEN_CENTER.x, SCREEN_CENTER.y - 100));
    pMenu->addChild(pHome);
    
    auto pReplay = MenuItemFont::create("Replay", [=](cocos2d::Ref* pRef){
        Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(GameTwoEvent::Result_Replay);
    });
    pReplay->setPosition(Vec2(SCREEN_CENTER.x, SCREEN_CENTER.y - 150));
    pMenu->addChild(pReplay);
}

void QFLGameTwoResultLayer::Enter(cocos2d::Layer* pLayer)
{
    log("<Enter>\t\t->ResultLayer");
    
    //添加到Scene中
    pLayer->addChild(this);
    
    //执行游戏
    this->Execute();
}

void QFLGameTwoResultLayer::Execute()
{
    log("<Execute>\t->ResultLayer");
}

void QFLGameTwoResultLayer::Exit(cocos2d::Layer* pLayer)
{
    log("<Exit>\t\t->ResultLayer\n");
    
    //移除游戏
    this->removeFromParentAndCleanup(true);
}