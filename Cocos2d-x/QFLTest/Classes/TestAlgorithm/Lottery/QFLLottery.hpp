//
//  QFLLottery.hpp
//  QFLTest
//
//  Created by QuFangliu on 2016/10/24.
//
//
/*
 这是一个老虎机示例？
 没错，就是老虎机
 */

#ifndef QFLLottery_hpp
#define QFLLottery_hpp

#include <stdio.h>
#include "QFLTestBase.hpp"

//抽奖状态
enum LotteryState
{
    Lottery_Ready       = 1,    //准备好了，可以开始
    Lottery_Start       = 2,    //押好了，开始转
    Lottery_Wait        = 3,    //转到最快
    Lottery_Stop        = 4,    //开始减速，到停止
    Lottery_Award       = 5,    //停下来了，显示奖励
};

//机器类
class QFLLottery : public QFLTestBase
{
CC_CONSTRUCTOR_ACCESS:
    QFLLottery();
    virtual ~QFLLottery();
    CREATE_FUNC(QFLLottery);            //很重要
    
private:
    virtual void enterTest() override;  //测试项目入口
    
private:
    void initMachine();     //初始化机器
    void addUI();           //添加按钮UI
    
    void changeState(LotteryState eState);
    
    //显示控制部分
//    void lightIndex(int nIndex);    //点亮某个Index
//    void offIndex(int nIndex);      //熄灭某个Index
    
    //跑马灯
//    void startToRun();  //开始跑
//    void running
    
private:
    std::vector<cocos2d::Node*> m_vectorCard;   //框框
};

#endif /* QFLLottery_hpp */
