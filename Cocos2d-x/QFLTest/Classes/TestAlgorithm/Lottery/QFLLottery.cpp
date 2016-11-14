//
//  QFLLottery.cpp
//  QFLTest
//
//  Created by QuFangliu on 2016/10/24.
//
//

#include "QFLLottery.hpp"

USING_NS_CC;

#define SIDE_NUMBER     7   //一条边上7个格子，整体为一个正方形

#define SIDE_WIDTH      420.0f  //方形的宽
#define SIDE_HEIGHT     420.0f  //方形的高

QFLLottery::QFLLottery()
{
    
}

QFLLottery::~QFLLottery()
{
    
}

void QFLLottery::enterTest()
{
    this->initMachine();
    this->addUI();
}

void QFLLottery::initMachine()
{
    //方格所在层
    auto pPanel = Node::create();
    pPanel->setPosition(SCREEN_CENTER);
    this->addChild(pPanel);
    
    //添加节点到Panel
    for (int i = 0; i < (SIDE_NUMBER - 1) * 4; i++) {
        //生成节点
        auto pNode = Label::createWithSystemFont(StringUtils::format("%d", i), "Arial", 50);
        //添加
        pPanel->addChild(pNode);
        //保存
        m_vectorCard.push_back(pNode);
    
        //计算位置,上、右、下、左
        if (i < (SIDE_NUMBER - 1) * 1) {
            pNode->setPosition(SIDE_WIDTH * -0.5 + i * (SIDE_WIDTH / (SIDE_NUMBER - 1)),
                               SIDE_HEIGHT * 0.5);
        }
        else if (i < (SIDE_NUMBER - 1) * 2) {
            pNode->setPosition(SIDE_WIDTH * 0.5,
                               SIDE_HEIGHT * 0.5 - (i % (SIDE_NUMBER - 1)) * (SIDE_HEIGHT / (SIDE_NUMBER - 1)));
        }
        else if (i < (SIDE_NUMBER - 1) * 3) {
            pNode->setPosition(SIDE_WIDTH * 0.5 - (i % (SIDE_NUMBER - 1)) * (SIDE_WIDTH / (SIDE_NUMBER - 1)),
                               SIDE_HEIGHT * -0.5);
        }
        else if (i < (SIDE_NUMBER - 1) * 4) {
            pNode->setPosition(SIDE_WIDTH * -0.5,
                               SIDE_HEIGHT * -0.5 + (i % (SIDE_NUMBER - 1)) * (SIDE_HEIGHT / (SIDE_NUMBER - 1)));
        }
        else {
            CCASSERT(false, "Invalid index of node.");
        }
    }
}

void QFLLottery::addUI()
{
    //添加菜单
    auto pMenu = Menu::create();
    pMenu->setPosition(Vec2::ZERO);
    this->addChild(pMenu);
    
    //添加开始按钮
    auto pBtnStart = MenuItemFont::create("Start", [=](Ref *pRef){
        this->changeState(LotteryState::Lottery_Start);
    });
    pBtnStart->setPosition(SCREEN_CENTER - Vec2(0, SIDE_HEIGHT * 0.5 + 50));
    pMenu->addChild(pBtnStart);
}

void QFLLottery::changeState(LotteryState eState)
{
    switch (eState) {
        case Lottery_Ready:
        {
            
        }
            break;
        case Lottery_Start:
        {
            
        }
            break;
        case Lottery_Wait:
        {
            
        }
            break;
        case Lottery_Stop:
        {
            
        }
            break;
        case Lottery_Award:
        {
            
        }
            break;
        default:
            CCASSERT(false, "Invalid state of lottery.");
            break;
    }
}
