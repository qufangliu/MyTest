//
//  ElevatorOne.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/18.
//
//

/*
    电梯测试_1
 
    运行逻辑:
        停止->开门(进入)->关门->运动->停止->开门(离开)->关门
 
    ????我tm写的什么
 
 
 */

#ifndef ElevatorOne_hpp
#define ElevatorOne_hpp

#include <stdio.h>

enum ElevatorOneState
{
    State_Opening   = 1,    //电梯门打开状态
    State_Closing   = 2,    //电梯门关闭状态
    State_Running   = 3,    //电梯运动状态
    State_Stopping  = 4     //电梯静止状态
};

class ElevatorOne
{
public:
    ElevatorOne();
    virtual ~ElevatorOne();
    
public:
    void gotoFloor(int nFloor);
    
private:
    void setState(ElevatorOneState eState); //只能通过事件来改变电梯的状态，电梯自动运行
    
    void open();    //开门
    void close();   //关门
    void run();     //运动
    void stop();    //减速到停止
    
private:
    ElevatorOneState m_eState;  //电梯状态标志
    int m_nTargetFloor;         //电梯目标楼层
    int m_nFloor;               //电梯所在楼层
};

#endif /* ElevatorOne_hpp */
