//
//  QFLGameTwoScene.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/10/8.
//
//

#ifndef QFLGameTwoScene_hpp
#define QFLGameTwoScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "QFLGameTwoStateBase.hpp"

class QFLGameTwoScene : public cocos2d::Layer   //为了测试,这里把继承自Scene改为了继承自Layer
{
CC_CONSTRUCTOR_ACCESS:
    QFLGameTwoScene();
    virtual ~QFLGameTwoScene();
    virtual bool init();
    CREATE_FUNC(QFLGameTwoScene);
    
public:
    void addUI();
    void initGame();
    void addEventListener();
    
    void ChangeState(GameTwoState* pState);
    
private:
    GameTwoState* m_pCurrentState;  //当前状态
};

#endif /* QFLGameTwoScene_hpp */
