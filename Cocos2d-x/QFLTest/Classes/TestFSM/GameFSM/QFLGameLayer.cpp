//
//  QFLGameLayer.cpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/25.
//
//

#include "QFLGameLayer.hpp"

USING_NS_CC;

QFLGameLayer::QFLGameLayer()
{
    
}

QFLGameLayer::~QFLGameLayer()
{
    
}

bool QFLGameLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    else {
        this->addUI();
        return true;
    }
}

void QFLGameLayer::addUI()
{
    
}

void QFLGameLayer::stateIn()
{
    log("进入GameLayer");
}

void QFLGameLayer::stateOut()
{
    log("离开GameLayer");
}