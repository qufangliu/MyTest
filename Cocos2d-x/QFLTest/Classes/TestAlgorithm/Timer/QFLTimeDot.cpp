//
//  QFLTimeDot.cpp
//  QFLTest
//
//  Created by QuFangliu on 2016/10/25.
//
//

#include "QFLTimeDot.hpp"
#include "ui/CocosGUI.h"

USING_NS_CC;

QFLTimeDot::QFLTimeDot()
{
    
}

QFLTimeDot::~QFLTimeDot()
{
    
}

void QFLTimeDot::enterTest()
{
    this->addTimer();
}

void QFLTimeDot::addTimer()
{
    //绘制正弦曲线y=a*sin(w*x + b) + k;
    float fA = 200.0f;  //a振幅200像素
    float fW = 1.0f;    //w角速度1.0
    float fB = 0;       //初相为0
    float fK = 0;       //偏距为0
    
    //中心点放在屏幕中心
    auto pCenter = DrawNode::create();
    pCenter->drawDot(Vec2::ZERO, 3, Color4F::WHITE);
    pCenter->setPosition(SCREEN_CENTER);
    this->addChild(pCenter);
    
    //计算点的位置
    float fRatio = 1;   //5个像素一个点
    for (int i = 0; i < SCREEN_WIDTH / fRatio; i++) {
        float fY = this->getSinY(fA, fW, i * fRatio - SCREEN_WIDTH * 0.5, fB, fK);
        auto vecPos = Vec2(SCREEN_WIDTH * -0.5 + i * fRatio, fY);
        
        pCenter->drawDot(vecPos, 1, Color4F(rand_0_1(), rand_0_1(), rand_0_1(), 1.0f));
    }
}

float QFLTimeDot::getSinY(float fA, float fW, float fX, float fB, float fK)
{
    //注意这里角度转弧度
    return fA * std::sin((fW * fX + fB) / 180.0f) + fK;
}



