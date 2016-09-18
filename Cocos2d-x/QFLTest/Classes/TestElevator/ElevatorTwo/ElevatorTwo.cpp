//
//  ElevatorTwo.cpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/19.
//
//

#include "ElevatorTwo.hpp"
#include <iostream>

#define QFLLOG(_text_)  do  \
                        {   \
                            std::cout << _text_ << std::endl;   \
                        } while (false) \

//ElevatorStateBase不需要在这里写实现部分了，它是一个抽象类，不能实例化

//Closing
ElevatorStateClosing::ElevatorStateClosing()
{
    m_pElevator = nullptr;
}
ElevatorStateClosing::~ElevatorStateClosing()
{
    
}
void ElevatorStateClosing::excute()
{
    //Closing的逻辑部分
    
    //关门之后，进行一些处理
    QFLLOG("Closing->关上电梯门，等待有人按电梯");
    
    //处理完成，根据条件判断下一状态
    if (rand() % 100 > 50) {
        //假设50%几率，电梯里面没有人（这里的关闭可能是之前一轮运行完后的关闭）
        QFLLOG("Closing->没有要去的楼层,停在这个状态");
    }
    else {
        //50%几率，有人选择了下一个楼层
        QFLLOG("Closing->准备前往下一个目标楼层");
        m_pElevator->setState(m_pElevator->m_pStateRunning);
    }
}

//Opening
ElevatorStateOpening::ElevatorStateOpening()
{
    m_pElevator = nullptr;
}
ElevatorStateOpening::~ElevatorStateOpening()
{
    
}
void ElevatorStateOpening::excute()
{
    //Opening的逻辑部分
    
    //开门之后，进行一些处理
    QFLLOG("Opening->打开电梯门");
    
    //处理完成，下一状态就是关门（转换到下一状态这件事，可以由某些条件触发）
    QFLLOG("Opening->上客、下客完成，准备关门");
    m_pElevator->setState(m_pElevator->m_pStateClosing);
}

//Running
ElevatorStateRunning::ElevatorStateRunning()
{
    m_pElevator = nullptr;
}
ElevatorStateRunning::~ElevatorStateRunning()
{
    
}
void ElevatorStateRunning::excute()
{
    //Running的逻辑部分
    
    //运行到指定的楼层
    QFLLOG("Running->运行前往指定的楼层（加速，匀速，减速）");
    
    //处理完成，下一状态就是保持电梯停止（状态转换事件可以由条件触发）
    QFLLOG("Running->到了指定楼层，准备停止");
    m_pElevator->setState(m_pElevator->m_pStateStopping);
}

//Stopping
ElevatorStateStopping::ElevatorStateStopping()
{
    m_pElevator = nullptr;
}
ElevatorStateStopping::~ElevatorStateStopping()
{
    
}
void ElevatorStateStopping::excute()
{
    //Stopping的逻辑部分
    
    //保持电梯停止
    QFLLOG("Stopping->保持电梯停止（刹车，锁定）");
    
    //处理完成，下一状态就是开门（状态转换可以根据轿箱内是否有人来进行条件触发）
    QFLLOG("Stopping->电梯锁定到楼层，准备开门");
    m_pElevator->setState(m_pElevator->m_pStateOpening);
}


//电梯类
ElevatorTwo::ElevatorTwo()
{
    //初始化自己的几个状态
    m_pStateClosing = new ElevatorStateClosing();
    m_pStateOpening = new ElevatorStateOpening();
    m_pStateRunning = new ElevatorStateRunning();
    m_pStateStopping = new ElevatorStateStopping();
    
    //状态类设置"控制"类
    m_pStateClosing->setElevator(this);
    m_pStateOpening->setElevator(this);
    m_pStateRunning->setElevator(this);
    m_pStateStopping->setElevator(this);
}

ElevatorTwo::~ElevatorTwo()
{
    //注意，要清内存噢
    delete m_pStateClosing;
    delete m_pStateOpening;
    delete m_pStateRunning;
    delete m_pStateStopping;
}

void ElevatorTwo::gotoFloor()
{
    //用户的操作，必定是上或者下，也就是从这个事件开始改变状态
    
    //事件导致的状态就是开门
    this->setState(m_pStateOpening);
}

