//
//  ElevatorOne.cpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/18.
//
//

#include "ElevatorOne.hpp"
#include <iostream>

#define QFLLOG(_text_)  do  \
                        {   \
                            std::cout << _text_ << std::endl;   \
                        } while (false) \

ElevatorOne::ElevatorOne()
{
    m_eState = ElevatorOneState::State_Stopping;    //默认静止状态
    m_nFloor = 1;                                   //默认楼层1楼
    m_nTargetFloor = 1;                             //默认目标1楼
}

ElevatorOne::~ElevatorOne()
{
    
}

//操作
void ElevatorOne::gotoFloor(int nFloor)
{
    if (m_nTargetFloor == nFloor) {
        //不需要运动
        QFLLOG("Elevator is here.");
    }
    else {
        //设置目标楼层
        m_nTargetFloor = nFloor;
        //状态转换
        this->setState(ElevatorOneState::State_Opening);
    }
}

//状态转换
void ElevatorOne::setState(ElevatorOneState eState)
{
    m_eState = eState;
    
    switch (eState) {
        case State_Opening:
            this->open();
            break;
        case State_Closing:
            this->close();
            break;
        case State_Running:
            this->run();
            break;
        case State_Stopping:
            this->stop();
            break;
        default:
            break;
    }
}

//运行逻辑
//开门
void ElevatorOne::open()
{
    QFLLOG("Elevator open...");
    
    //下一个状态必然是close
    this->setState(ElevatorOneState::State_Closing);
}
//关门
void ElevatorOne::close()
{
    QFLLOG("Elevator close...");
    
    //根据目标楼层，判断进入怎样的状态
    if (m_nFloor != m_nTargetFloor) {
        this->setState(ElevatorOneState::State_Running);
    }
    else {
        //结束状态
    }
}
//运行
void ElevatorOne::run()
{
    QFLLOG("Elevator run..." << m_nTargetFloor);
    
    //移动到对应的楼层
    m_nFloor = m_nTargetFloor;
    
    //下一个状态必然是stop
    this->setState(ElevatorOneState::State_Stopping);
}
//静止
void ElevatorOne::stop()
{
    QFLLOG("Elevator stop...");
    
    //下一个状态必然是open
    this->setState(ElevatorOneState::State_Opening);
}