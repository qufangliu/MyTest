//
//  QFLGameTwoGameLayer.cpp
//  QFLTest
//
//  Created by QuFangliu on 16/10/8.
//
//

#include "QFLGameTwoGameLayer.hpp"

#include "QFLTools/QFLHelper.hpp"

USING_NS_CC;

QFLGameTwoGameLayer::QFLGameTwoGameLayer()
{
    
}

QFLGameTwoGameLayer::~QFLGameTwoGameLayer()
{
    
}

bool QFLGameTwoGameLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    else {
        this->addUI();
        return true;
    }
}

void QFLGameTwoGameLayer::addUI()
{
    //黑色背景
    auto pLayer = QFL_HELPER->getColorfulLayer();
    QFL_HELPER->addNoTouchListener(pLayer);
    this->addChild(pLayer);
    
    //GameLogo
    auto pLogo = Label::createWithSystemFont("GameLayer", "", 50);
    pLogo->setPosition(Vec2(SCREEN_CENTER.x, SCREEN_CENTER.y + 60));
    this->addChild(pLogo);
    
    //菜单
    auto pMenu = Menu::create();
    pMenu->setPosition(Vec2::ZERO);
    this->addChild(pMenu);
    
    //按钮
    auto pOver = MenuItemFont::create("GameOver", [=](cocos2d::Ref* pRef){
        Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(GameTwoEvent::Game_Over);
    });
    pOver->setPosition(Vec2(SCREEN_CENTER.x, SCREEN_CENTER.y - 100));
    pMenu->addChild(pOver);
}

void QFLGameTwoGameLayer::Enter(cocos2d::Layer* pLayer)
{
    log("<Enter>\t\t->GameLayer");
    
    //添加到Scene中
    pLayer->addChild(this);
    
    //执行游戏
    this->Execute();
}

void QFLGameTwoGameLayer::Execute()
{
    log("<Execute>\t->GameLayer");
}

void QFLGameTwoGameLayer::Exit(cocos2d::Layer* pLayer)
{
    log("<Exit>\t\t->GameLayer\n");
    
    //移除游戏
    this->removeFromParentAndCleanup(true);
}
