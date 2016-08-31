//
//  QFLHelper.cpp
//  QFLTest
//
//  Created by QuFangliu on 16/8/30.
//
//

#include "QFLHelper.hpp"

USING_NS_CC;

static QFLHelper* m_pInstance = nullptr;

QFLHelper::QFLHelper()
{
    
}

QFLHelper::~QFLHelper()
{
    
}

QFLHelper* QFLHelper::getInstance()
{
    if (!m_pInstance) {
        m_pInstance = new QFLHelper();
        m_pInstance->initHelper();
    }
    else {}
    
    return m_pInstance;
}

void QFLHelper::initHelper()
{
    
}


//==============

//MARK:Tools

//==============

void QFLHelper::addNoTouchLayer(cocos2d::Node *pNode, int nZorder)
{
    //透明层
    auto pLayer = Layer::create();
    pLayer->setContentSize(SCREEN_VISIBLE_SIZE);
    pNode->addChild(pLayer, nZorder);
    
    //触摸屏蔽
    this->addNoTouchListener(pLayer);
}

void QFLHelper::addNoTouchListener(cocos2d::Node *pNode)
{
    //触摸屏蔽
    auto pListener = EventListenerTouchOneByOne::create();
    pListener->setSwallowTouches(true);
    pListener->onTouchBegan = [=](cocos2d::Touch*, cocos2d::Event*){
        return true;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(pListener, pNode);
}

void QFLHelper::addBackMenu(cocos2d::Node *pNode, int nZorder)
{
    //菜单
    auto pMenu = Menu::create();
    pMenu->setPosition(Vec2::ZERO);
    pNode->addChild(pMenu, nZorder);
    
    //返回按钮
    auto pBackItem = MenuItemFont::create("Back", [=](cocos2d::Ref *pRef){
        pNode->removeFromParentAndCleanup(true);
    });
    pBackItem->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
    pBackItem->setPosition(Vec2(pNode->getContentSize().width - 10.0f, 5.0f));
    pMenu->addChild(pBackItem);
}

cocos2d::Layer* QFLHelper::getColorfulLayer(cocos2d::Color4B color, int nOpacity)
{
    auto pLayer = LayerColor::create(color);
    pLayer->setContentSize(SCREEN_VISIBLE_SIZE);
    pLayer->setOpacity(nOpacity);
    return pLayer;
}

cocos2d::Layer* QFLHelper::getBlackBGLayer()
{
    auto pLayer = getColorfulLayer();
    this->addNoTouchListener(pLayer);
    return pLayer;
}
















