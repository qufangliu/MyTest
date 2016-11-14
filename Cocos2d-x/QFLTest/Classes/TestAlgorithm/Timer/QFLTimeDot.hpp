//
//  QFLTimeDot.hpp
//  QFLTest
//
//  Created by QuFangliu on 2016/10/25.
//
//

#ifndef QFLTimeDot_hpp
#define QFLTimeDot_hpp

#include <stdio.h>
#include "QFLTestBase.hpp"

#include "QFLTimer.hpp"

class QFLTimeDot : public QFLTestBase
{
CC_CONSTRUCTOR_ACCESS:
    QFLTimeDot();
    virtual ~QFLTimeDot();
    CREATE_FUNC(QFLTimeDot);

private:
    
    virtual void enterTest();
    void addTimer();
    
    float getSinY(float fA, float fW, float fX, float fB, float fK);
};

#endif /* QFLTimeDot_hpp */
