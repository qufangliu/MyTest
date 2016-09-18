//
//  TestElevatorTwo.cpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/19.
//
//

#include "TestElevatorTwo.hpp"
#include "QFLTools/QFLHelper.hpp"

#include "ElevatorTwo.hpp"

USING_NS_CC;


TestElevatorTwo::TestElevatorTwo()
{
    
}

TestElevatorTwo::~TestElevatorTwo()
{
    
}

bool TestElevatorTwo::init()
{
    if (!Layer::init()) {
        return false;
    }
    else {
        this->initSelf();
        return true;
    }
}

void TestElevatorTwo::initSelf()
{
    //BG layer
    this->addChild(QFL_HELPER->getBlackBGLayer());
    //Back button
    QFL_HELPER->addBackMenu(this);
    
    //初始化电梯
    auto pElevator = new ElevatorTwo();
    
    //添加操作按钮
    //菜单
    auto pMenu = Menu::create();
    pMenu->setPosition(Vec2::ZERO);
    this->addChild(pMenu);
    //按钮
    auto pBtnClick = MenuItemFont::create("我要上电梯", [=](Ref*){
        //按电梯咯
        pElevator->gotoFloor();
    });
    pBtnClick->setPosition(SCREEN_CENTER);
    pMenu->addChild(pBtnClick);
}

