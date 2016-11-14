//
//  QFLTestBase.cpp
//  QFLTest
//
//  Created by QuFangliu on 2016/10/24.
//
//

#include "QFLTestBase.hpp"

USING_NS_CC;

QFLTestBase::QFLTestBase()
{
    
}

QFLTestBase::~QFLTestBase()
{
    
}

bool QFLTestBase::init()
{
    if (Layer::init()) {
        this->addBaseUI();
        this->enterTest();
        return true;
    }
    else {
        return false;
    }
}

QFLTestBase* QFLTestBase::create()
{
    QFLTestBase *pBase = new(std::nothrow) QFLTestBase();
    
    if (pBase && pBase->init()) {
        pBase->autorelease();
        return pBase;
    }
    else {
        CC_SAFE_DELETE(pBase);
        return nullptr;
    }
}

void QFLTestBase::addBaseUI()
{
    //添加黑色背景
    auto pBGLayer = QFL_HELPER->getBlackBGLayer();
    this->addChild(pBGLayer);
    //添加返回按钮
    QFL_HELPER->addBackMenu(this);
}

void QFLTestBase::enterTest()
{
    log("Need to override this method!");
}
