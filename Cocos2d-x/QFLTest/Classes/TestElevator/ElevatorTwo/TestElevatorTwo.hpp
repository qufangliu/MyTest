//
//  TestElevatorTwo.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/19.
//
//

#ifndef TestElevatorTwo_hpp
#define TestElevatorTwo_hpp

#include <stdio.h>
#include "cocos2d.h"

class TestElevatorTwo : public cocos2d::Layer
{
public:
    TestElevatorTwo();
    virtual ~TestElevatorTwo();
    virtual bool init();
    CREATE_FUNC(TestElevatorTwo);
    
public:
    
private:
    void initSelf();
    
};

#endif /* TestElevatorTwo_hpp */
