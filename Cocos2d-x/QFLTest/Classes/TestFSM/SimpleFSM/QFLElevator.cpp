//
//  QFLElevator.cpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/16.
//
//

#include "QFLElevator.hpp"
#include <iostream>

MyElevator::MyElevator()
{
    m_eState = State::State_Closing;    //Default state
}

MyElevator::~MyElevator()
{
    
}

void MyElevator::open()
{
    switch (m_eState) {
        case State_Closing:
        {
            this->setState(State::State_Opening);
        }
            break;
        case State_Opening:
        {
            return;
        }
            break;
        case State_Running:
        {
            return;
        }
            break;
        case State_Stopping:
        {
            this->setState(State::State_Opening);
        }
            break;
        default:
            break;
    }
    
    std::cout << "Elevator is opening!" <<std::endl;
}

void MyElevator::close()
{
    switch (m_eState) {
        case State_Closing:
        {
            return;
        }
            break;
        case State_Opening:
        {
            this->setState(State::State_Closing);
        }
            break;
        case State_Running:
        {
            return;
        }
            break;
        case State_Stopping:
        {
            return;
        }
            break;
        default:
            break;
    }
    
    std::cout << "Elevator is closing!" <<std::endl;
}

void MyElevator::run()
{
    switch (m_eState) {
        case State_Closing:
        {
            this->setState(State::State_Running);
        }
            break;
        case State_Opening:
        {
            return;
        }
            break;
        case State_Running:
        {
            return;
        }
            break;
        case State_Stopping:
        {
            this->setState(State::State_Running);
        }
            break;
        default:
            break;
    }
    
    std::cout << "Elevator is running!" <<std::endl;
}

void MyElevator::stop()
{
    switch (m_eState) {
        case State_Closing:
        {
            this->setState(State::State_Stopping);
        }
            break;
        case State_Opening:
        {
            return;
        }
            break;
        case State_Running:
        {
            this->setState(State::State_Stopping);
        }
            break;
        case State_Stopping:
        {
            return;
        }
            break;
        default:
            break;
    }
    
    std::cout << "Elevator is stopping!" <<std::endl;
}
