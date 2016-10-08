//
//  QFLGameRoot.cpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/24.
//
//

#include "QFLGameRoot.hpp"

#include "QFLTools/QFLHelper.hpp"
#include "QFLMainLayer.hpp"
#include "QFLGameLayer.hpp"

USING_NS_CC;

QFLGameRoot::QFLGameRoot()
{
    
}

QFLGameRoot::~QFLGameRoot()
{
    
}

bool QFLGameRoot::init()
{
    if (!Layer::init()) {
        return false;
    }
    else {
        this->addUI();
        return true;
    }
}

void QFLGameRoot::addUI()
{
    //黑色透明背景
    this->addChild(QFL_HELPER->getBlackBGLayer());
    QFL_HELPER->addBackMenu(this);
    
    //标志RootLayer
    auto pLogo = Label::createWithSystemFont("RootLayer", "", 50);
    pLogo->setPosition(SCREEN_CENTER);
    this->addChild(pLogo);
}

void QFLGameRoot::setState(QFLGameRoot::State eState)
{
    //上一个状态退出
    if (m_pCurrentState) {
        m_pCurrentState->stateOut();
        ((Node*)m_pCurrentState)->removeFromParentAndCleanup(true);
    }
    else {}
    
    //设置状态
    switch (eState) {
        case MainState:
        {
            m_eState = QFLGameRoot::State::MainState;
//            m_pCurrentState = QFLMainLayer::create();
        }
            break;
        case GameState:
        {
            m_eState = QFLGameRoot::State::GameState;
            m_pCurrentState = QFLGameLayer::create();
        }
            break;
        default:
            CCASSERT(false, "Invalid state.");
            break;
    }
    
    //进入新状态
    m_pCurrentState = new QFLMainLayer();
    this->addChild((Node*)m_pCurrentState);
    m_pCurrentState->stateIn();
}

void QFLGameRoot::stateIn()
{
    //本状态自己的In处理
    log("进入游戏");
    
    //进入子状态Main
    this->setState(QFLGameRoot::State::MainState);
}

void QFLGameRoot::stateOut()
{
    log("退出游戏!");
}

