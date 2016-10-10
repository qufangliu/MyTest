//
//  QFLGameTwoMainLayer.cpp
//  QFLTest
//
//  Created by QuFangliu on 16/10/8.
//
//

#include "QFLGameTwoMainLayer.hpp"

#include "QFLTools/QFLHelper.hpp"

USING_NS_CC;

QFLGameTwoMainLayer::QFLGameTwoMainLayer()
{
    
}

QFLGameTwoMainLayer::~QFLGameTwoMainLayer()
{
    
}

bool QFLGameTwoMainLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    else {
        this->addUI();
        return true;
    }
}

void QFLGameTwoMainLayer::Enter(cocos2d::Layer* pLayer)
{
    log("<Enter>\t\t->MainLayer");
    
    //添加到Scene中
    pLayer->addChild(this);
    
    //执行各种事件
    this->Execute();
}

void QFLGameTwoMainLayer::Execute()
{
    log("<Execute>\t->MainLayer");
}

void QFLGameTwoMainLayer::Exit(cocos2d::Layer* pLayer)
{
    log("<Exit>\t\t->MainLayer\n");
    
    //移除
    this->removeFromParentAndCleanup(true);
}

void QFLGameTwoMainLayer::addUI()
{
    //黑色背景
    auto pLayer = QFL_HELPER->getColorfulLayer();
    QFL_HELPER->addNoTouchListener(pLayer);
    this->addChild(pLayer);
    
    //MainLogo
    auto pLogo = Label::createWithSystemFont("MainLayer", "", 50);
    pLogo->setPosition(Vec2(SCREEN_CENTER.x, SCREEN_CENTER.y + 60));
    this->addChild(pLogo);
    
    //菜单
    auto pMenu = Menu::create();
    pMenu->setPosition(Vec2::ZERO);
    this->addChild(pMenu);
    
    //按钮
    auto pStart = MenuItemFont::create("Start", [=](cocos2d::Ref* pRef){
        Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(GameTwoEvent::Main_Start);
    });
    pStart->setPosition(Vec2(SCREEN_CENTER.x, SCREEN_CENTER.y - 100));
    pMenu->addChild(pStart);
}