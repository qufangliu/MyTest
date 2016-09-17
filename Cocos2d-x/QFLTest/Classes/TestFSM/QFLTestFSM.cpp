//
//  QFLTestFSM.cpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/16.
//
//

#include "QFLTestFSM.hpp"

#include "QFLTools/QFLHelper.hpp"

#include "SimpleFSM/QFLElevator.hpp"
#include "DiscreteStateFSM/QFLElevatorS.hpp"

USING_NS_CC;

QFLTestFSM::QFLTestFSM()
{
    
}

QFLTestFSM::~QFLTestFSM()
{
    
}

bool QFLTestFSM::init()
{
    if (!Layer::init()) {
        return false;
    }
    else {
        this->initSelf();
        return true;
    }
}

void QFLTestFSM::initSelf()
{
    //BG layer
    this->addChild(QFL_HELPER->getBlackBGLayer());
    //Back button
    QFL_HELPER->addBackMenu(this);
    
    //start testing
    this->startElevator();
}

void QFLTestFSM::startElevator()
{
    /*
        Test 1
        状态机的一种方式：
            1.一个类中包含了所有状态的处理（例：4种状态，4个处理）。
            2.操作时，要先设置其状态，再执行动作。
            3.每个动作中进行各种状态的判断（例：每个处理函数中，再进行4种状态的判断，对不同状态作出不同反应）。
        缺点：新增状态时，要修改所有处理函数。
     */
    
//    MyElevator *pElevator = new MyElevator();
//    
//    //test running
//    pElevator->open();
//    pElevator->close();
//    pElevator->run();
//    pElevator->stop();
//    pElevator->open();
    
    
    /*
        Test 2
        状态机的另外一种方式：
            1.创建一个基类，包含了各种状态的处理函数（例：4个状态，4种处理）。
            2.根据状态，由基类派生出对应的子类。子类只进行自己状态的处理。
            3.创建一个状态控制器，包含了各个状态对应的子类的对象。
            4.对状态控制器设置状态，控制器根据状态，调用相应子类的处理。
        缺点：类太多太多了。
     */
    auto pOperator = new ElevatorOperator();
    pOperator->setEleState(EleState::EleStateOpening);
    pOperator->setEleState(EleState::EleStateClosing);
    pOperator->setEleState(EleState::EleStateRunning);
    pOperator->setEleState(EleState::EleStateStopping);
    pOperator->setEleState(EleState::EleStateOpening);
}

