//
//  QFLGameTwoScene.cpp
//  QFLTest
//
//  Created by QuFangliu on 16/10/8.
//
//

#include "QFLGameTwoScene.hpp"

#include "QFLTools/QFLHelper.hpp"

//基类
#include "QFLGameTwoStateBase.hpp"

//状态类
#include "QFLGameTwoMainLayer.hpp"
#include "QFLGameTwoGameLayer.hpp"
#include "QFLGameTwoResultLayer.hpp"

USING_NS_CC;

QFLGameTwoScene::QFLGameTwoScene()
{
    
}

QFLGameTwoScene::~QFLGameTwoScene()
{
    
}
bool QFLGameTwoScene::init()
{
    if (!Layer::init()) {
        return false;
    }
    else {
        this->addUI();
        this->addEventListener();
        this->initGame();
        return true;
    }
}

void QFLGameTwoScene::addUI()
{
    //黑色背景
    auto pLayer = QFL_HELPER->getColorfulLayer();
    QFL_HELPER->addNoTouchListener(pLayer);
    this->addChild(pLayer);
    
    //返回按钮
    QFL_HELPER->addBackMenu(this, 100);
}

void QFLGameTwoScene::initGame()
{
    //进入一个初始状态
    log("游戏开始");
    m_pCurrentState = QFLGameTwoMainLayer::create();
    m_pCurrentState->Enter(this);
}

void QFLGameTwoScene::addEventListener()
{
    Director::getInstance()->getEventDispatcher()->addCustomEventListener(GameTwoEvent::Main_Start, [=](EventCustom* pEvent){
        log("[Event]->Main_Start");
        this->ChangeState(QFLGameTwoGameLayer::create());
    });
    Director::getInstance()->getEventDispatcher()->addCustomEventListener(GameTwoEvent::Game_Over, [=](EventCustom* pEvent){
        log("[Event]->Game_Over");
        this->ChangeState(QFLGameTwoResultLayer::create());
    });
    Director::getInstance()->getEventDispatcher()->addCustomEventListener(GameTwoEvent::Result_Home, [=](EventCustom* pEvent){
        log("[Event]->Result_Home");
        this->ChangeState(QFLGameTwoMainLayer::create());
    });
    Director::getInstance()->getEventDispatcher()->addCustomEventListener(GameTwoEvent::Result_Replay, [=](EventCustom* pEvent){
        log("[Event]->Result_Replay");
        this->ChangeState(QFLGameTwoGameLayer::create());
    });
}

void QFLGameTwoScene::ChangeState(GameTwoState *pState)
{
    //旧状态退出
    m_pCurrentState->Exit(this);
    
    //保存新状态
    m_pCurrentState = pState;
    
    //新状态进入
    m_pCurrentState->Enter(this);
}

