//
//  QFLGameTwoGameLayer.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/10/8.
//
//

#ifndef QFLGameTwoGameLayer_hpp
#define QFLGameTwoGameLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "QFLGameTwoStateBase.hpp"

class QFLGameTwoGameLayer : public cocos2d::Layer, public GameTwoState
{
public:
    QFLGameTwoGameLayer();
    virtual ~QFLGameTwoGameLayer();
    virtual bool init() override;
    CREATE_FUNC(QFLGameTwoGameLayer);
    
    void Enter(cocos2d::Layer* pLayer) override;
    void Execute() override;
    void Exit(cocos2d::Layer* pLayer) override;
    
private:
    void addUI();
};

#endif /* QFLGameTwoGameLayer_hpp */
