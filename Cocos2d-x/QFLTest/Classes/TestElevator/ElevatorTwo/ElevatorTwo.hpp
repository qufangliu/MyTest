//
//  ElevatorTwo.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/19.
//
//

#ifndef ElevatorTwo_hpp
#define ElevatorTwo_hpp

#include <stdio.h>

//预先声明一下，在state中需要用到
class ElevatorTwo;


//Elevator has four status : closing, opening, running, stopping
//Four status correspond four classes. All of them inherited from one base state class.
class ElevatorStateBase
{
public:
    virtual ~ElevatorStateBase() {}
    
    //某个状态需要执行的逻辑
    virtual void excute() = 0;
    
    //设置电梯类
    void setElevator(ElevatorTwo *pElevator) { m_pElevator = pElevator; }
protected:
    //保存一个ElevatorTow的指针，为了修改它的状态
    ElevatorTwo *m_pElevator;
};


//四种状态的类
//Closing
class ElevatorStateClosing : public ElevatorStateBase
{
public:
    ElevatorStateClosing();
    virtual ~ElevatorStateClosing();
    
    //执行逻辑
    virtual void excute() override;
};

//Opening
class ElevatorStateOpening : public ElevatorStateBase
{
public:
    ElevatorStateOpening();
    virtual ~ElevatorStateOpening();
    
    //执行逻辑
    virtual void excute() override;
};

//Running
class ElevatorStateRunning : public ElevatorStateBase
{
public:
    ElevatorStateRunning();
    virtual ~ElevatorStateRunning();
    
    //执行逻辑
    virtual void excute() override;
};

//Stopping
class ElevatorStateStopping : public ElevatorStateBase
{
public:
    ElevatorStateStopping();
    virtual ~ElevatorStateStopping();
    
    //执行逻辑
    virtual void excute() override;
};


//电梯类
class ElevatorTwo
{
public:
    ElevatorTwo();
    virtual ~ElevatorTwo();
    
    //对外开放的操作
    void gotoFloor();
    
public:
    //每个状态都有一个class
    ElevatorStateBase *m_pStateClosing = nullptr;
    ElevatorStateBase *m_pStateOpening = nullptr;
    ElevatorStateBase *m_pStateRunning = nullptr;
    ElevatorStateBase *m_pStateStopping = nullptr;

    //设置状态
    void setState(ElevatorStateBase *pState) { m_pState = pState; pState->excute();}
    
private:
    //当前状态
    ElevatorStateBase *m_pState = m_pStateClosing;  //默认关闭状态
};




#endif /* ElevatorTwo_hpp */
