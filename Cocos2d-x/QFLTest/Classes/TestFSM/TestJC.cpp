//
//  TestJC.cpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/27.
//
//

#include "TestJC.hpp"

void SubA::excute()
{
    //生成一个SubB的对象，尝试用m_pCurrentObj来指向它
    auto pObj = new SubB();
    
    pObj->showName();
    
    m_pCurrentObj = pObj;   //这里是赋值不了
    
    m_pCurrentObj->showName();
}

void SubB::excute()
{
    
}
