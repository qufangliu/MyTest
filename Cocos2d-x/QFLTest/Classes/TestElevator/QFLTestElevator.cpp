//
//  QFLTestElevator.cpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/18.
//
//

#include "QFLTestElevator.hpp"
#include "QFLTools/QFLHelper.hpp"

//Elevators
#include "ElevatorOne/TestElevatorOne.hpp"
#include "ElevatorTwo/TestElevatorTwo.hpp"

USING_NS_CC;

QFLTestElevator::QFLTestElevator()
{
    m_nCount = 0;
    m_pMenu = nullptr;
}

QFLTestElevator::~QFLTestElevator()
{
    
}

bool QFLTestElevator::init()
{
    if (!Layer::init()) {
        return false;
    }
    else {
        this->initSelf();
        return true;
    }
}

void QFLTestElevator::initSelf()
{
    //BG layer
    this->addChild(QFL_HELPER->getBlackBGLayer());
    //Back button
    QFL_HELPER->addBackMenu(this);
    
    //test menu
    m_pMenu = Menu::create();
    m_pMenu->setPosition(Vec2::ZERO);
    this->addChild(m_pMenu);
    
    //test item
    //One
    this->addElevator("Elevator-One", [=](){
        this->addChild(TestElevatorOne::create());
    });
    //Two
    this->addElevator("Elevator_Two", [=](){
        this->addChild(TestElevatorTwo::create());
    });
}

void QFLTestElevator::addElevator(const std::string &strText, const std::function<void()> &funcCall)
{
    auto pItem = MenuItemFont::create(strText, [=](Ref*){ funcCall(); });
    pItem->setPosition(SCREEN_CENTER.x , SCREEN_TOP - 100 - m_nCount * 50);
    m_pMenu->addChild(pItem);
    
    m_nCount++;
}
