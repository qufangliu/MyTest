//
//  QFLGameTwoMainLayer.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/10/8.
//
//

#ifndef QFLGameTwoMainLayer_hpp
#define QFLGameTwoMainLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "QFLGameTwoStateBase.hpp"

class QFLGameTwoMainLayer : public cocos2d::Layer, public GameTwoState
{
public:
    QFLGameTwoMainLayer();
    virtual ~QFLGameTwoMainLayer();
    virtual bool init() override;
    CREATE_FUNC(QFLGameTwoMainLayer);
    
    void Enter(cocos2d::Layer* pLayer) override;
    void Execute() override;
    void Exit(cocos2d::Layer* pLayer) override;
    
private:
    void addUI();
};

#endif /* QFLGameTwoMainLayer_hpp */
