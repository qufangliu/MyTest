//
//  QFLGameTwoResultLayer.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/10/8.
//
//

#ifndef QFLGameTwoResultLayer_hpp
#define QFLGameTwoResultLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "QFLGameTwoStateBase.hpp"

class QFLGameTwoResultLayer : public cocos2d::Layer, public GameTwoState
{
public:
    QFLGameTwoResultLayer();
    virtual ~QFLGameTwoResultLayer();
    virtual bool init() override;
    CREATE_FUNC(QFLGameTwoResultLayer);
    
    void Enter(cocos2d::Layer* pLayer) override;
    void Execute() override;
    void Exit(cocos2d::Layer* pLayer) override;
    
private:
    void addUI();
};
#endif /* QFLGameTwoResultLayer_hpp */
