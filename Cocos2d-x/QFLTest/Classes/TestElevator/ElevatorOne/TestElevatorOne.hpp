//
//  TestElevatorOne.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/18.
//
//

#ifndef TestElevatorOne_hpp
#define TestElevatorOne_hpp

#include <stdio.h>
#include "cocos2d.h"

class TestElevatorOne : public cocos2d::Layer
{
public:
    TestElevatorOne();
    virtual ~TestElevatorOne();
    virtual bool init();
    CREATE_FUNC(TestElevatorOne);
    
public:
    
private:
    void initSelf();
};

#endif /* TestElevatorOne_hpp */
