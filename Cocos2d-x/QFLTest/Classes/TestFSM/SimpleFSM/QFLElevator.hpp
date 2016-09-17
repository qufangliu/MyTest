//
//  QFLElevator.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/16.
//
//

#ifndef QFLElevator_hpp
#define QFLElevator_hpp

#include <stdio.h>

//State
enum State{
    State_Opening   = 1,
    State_Closing   = 2,
    State_Running   = 3,
    State_Stopping  = 4
};

//Base class
class Elevator
{
public:
    //Properties
    State m_eState;
    
    //Function
    virtual void setState(State eState) = 0;
    
    virtual void open() = 0;
    virtual void close() = 0;
    virtual void run() = 0;
    virtual void stop() = 0;
};

//Example
class MyElevator : public Elevator
{
public:
    MyElevator();
    ~MyElevator();
    
public:
    void setState(State eState) { m_eState = eState; }
    
    void open();
    void close();
    void run();
    void stop();
};

#endif /* QFLElevator_hpp */
