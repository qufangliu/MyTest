//
//  QFLMainLayer.cpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/25.
//
//

#include "QFLMainLayer.hpp"

#include "QFLTools/QFLHelper.hpp"

USING_NS_CC;

QFLMainLayer::QFLMainLayer()
{
    
}

QFLMainLayer::~QFLMainLayer()
{
    
}

//bool QFLMainLayer::init()
//{
//    if (!Layer::init()) {
//        return false;
//    }
//    else {
//        this->addUI();
//        return true;
//    }
//}

//void QFLMainLayer::addUI()
//{
//    //灰色背景
//    auto pLayer = QFL_HELPER->getColorfulLayer(Color4B::BLACK, 100);
//    QFL_HELPER->addNoTouchListener(pLayer);
//    this->addChild(pLayer);
//    
//    //MainLogo
//    auto pLogo = Label::createWithSystemFont("MainLayer", "", 50);
//    pLogo->setPosition(Vec2(SCREEN_CENTER.x, SCREEN_CENTER.y + 60));
//    this->addChild(pLogo);
//    
//    //
//}

void QFLMainLayer::stateIn()
{
    log("进入MainLayer");
}

void QFLMainLayer::stateOut()
{
    log("离开MainLayer");
}