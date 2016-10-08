//
//  QFLGameLayer.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/25.
//
//

#ifndef QFLGameLayer_hpp
#define QFLGameLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "QFLStateNodeBase.hpp"

class QFLGameLayer : public cocos2d::Layer, public QFLStateNodeBase
{
public:
    QFLGameLayer();
    virtual ~QFLGameLayer();
    virtual bool init() override;
    CREATE_FUNC(QFLGameLayer);
    
    //子类相关
    
    //本状态处理
    virtual void stateIn() override;
    virtual void stateOut() override;
    
private:
    void addUI();
};

#endif /* QFLGameLayer_hpp */
