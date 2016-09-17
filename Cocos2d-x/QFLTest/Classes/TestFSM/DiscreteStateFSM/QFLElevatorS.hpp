//
//  QFLElevatorS.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/17.
//
//

#ifndef QFLElevatorS_hpp
#define QFLElevatorS_hpp

#include <stdio.h>
#include <iostream>

//State
enum EleState{
    EleStateOpening     = 1,
    EleStateClosing     = 2,
    EleStateRunning     = 3,
    EleStateStopping    = 4
};

//Basic elevator
class ElevatorBase {
public:
    virtual void open() {}
    virtual void close() {}
    virtual void run() {}
    virtual void stop() {}
};

//Elevators for four state
//Opening state
class OpeningElevator : public ElevatorBase
{
public:
    void open() {
        std::cout << "Opening" << std::endl;
    }
};

//Closing state
class ClosingElevator : public ElevatorBase
{
public:
    void close() {
        std::cout << "Closing" << std::endl;
    }
};

//Running state
class RunningElevator : public ElevatorBase
{
public:
    void run() {
        std::cout << "Running" << std::endl;
    }
};

//Stopping state
class StoppingElevator : public ElevatorBase
{
public:
    void stop() {
        std::cout << "Stopping" << std::endl;
    }
};


//Basic function of elevator, also controller of elevator
class ElevatorOperator {
public:
    ElevatorOperator() {
        
        m_pOpeningState = new OpeningElevator();
        m_pClosingState = new ClosingElevator();
        m_pRunningState = new RunningElevator();
        m_pStoppingState = new StoppingElevator();
        
        m_eState = EleStateStopping;
        m_pElevator = m_pStoppingState;
    }
    
    OpeningElevator *m_pOpeningState;
    ClosingElevator *m_pClosingState;
    RunningElevator *m_pRunningState;
    StoppingElevator *m_pStoppingState;
    
    ElevatorBase *m_pElevator;
    EleState m_eState;
    
    void setEleState(EleState eState) {
        m_eState = eState;
        switch (eState) {
            case EleStateOpening:
                m_pElevator = m_pOpeningState;
                this->open();
                break;
            case EleStateClosing:
                m_pElevator = m_pClosingState;
                this->close();
                break;
            case EleStateRunning:
                m_pElevator = m_pRunningState;
                this->run();
                break;
            case EleStateStopping:
                m_pElevator = m_pStoppingState;
                this->stop();
                break;
            default:
                break;
        }
    }
    
    void open() { m_pElevator->open(); }
    void close() { m_pElevator->close(); }
    void run() { m_pElevator->run(); }
    void stop() { m_pElevator->stop(); }
};




#endif /* QFLElevatorS_hpp */
