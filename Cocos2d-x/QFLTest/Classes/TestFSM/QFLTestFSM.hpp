//
//  QFLTestFSM.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/16.
//
//

#ifndef QFLTestFSM_hpp
#define QFLTestFSM_hpp

#include <stdio.h>
#include "cocos2d.h"

class QFLTestFSM : public cocos2d::Layer
{
public:
    QFLTestFSM();
    virtual ~QFLTestFSM();
    virtual bool init();
    CREATE_FUNC(QFLTestFSM);
    
public:
    
private:
    void initSelf();
    void startElevator();
};

#endif /* QFLTestFSM_hpp */
