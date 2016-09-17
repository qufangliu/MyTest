//
//  TestElevatorOne.cpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/18.
//
//

#include "TestElevatorOne.hpp"
#include "QFLTools/QFLHelper.hpp"

#include "ElevatorOne.hpp"

USING_NS_CC;

TestElevatorOne::TestElevatorOne()
{
    
}

TestElevatorOne::~TestElevatorOne()
{
    
}

bool TestElevatorOne::init()
{
    if (!Layer::init()) {
        return false;
    }
    else {
        this->initSelf();
        return true;
    }
}

void TestElevatorOne::initSelf()
{
    //BG layer
    this->addChild(QFL_HELPER->getBlackBGLayer());
    //Back button
    QFL_HELPER->addBackMenu(this);
    
    //elevator
    auto pElevator = new ElevatorOne();
    
    //controller
    //menu
    auto pMenu = Menu::create();
    pMenu->setPosition(Vec2::ZERO);
    this->addChild(pMenu);
    
    //button-run
    auto pItemRun = MenuItemFont::create("Elevator-Run", [=](Ref*){
        pElevator->gotoFloor(20);
    });
    pItemRun->setPosition(SCREEN_CENTER);
    pMenu->addChild(pItemRun);
}