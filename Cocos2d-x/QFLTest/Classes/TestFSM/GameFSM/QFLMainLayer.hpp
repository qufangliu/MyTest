//
//  QFLMainLayer.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/25.
//
//

#ifndef QFLMainLayer_hpp
#define QFLMainLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "QFLStateNodeBase.hpp"

class QFLMainLayer : public QFLStateNodeBase
{
public:
    QFLMainLayer();
    virtual ~QFLMainLayer();
//    virtual bool init() override;
//    CREATE_FUNC(QFLMainLayer);
    
    //子类相关
    
    //本状态处理
    virtual void stateIn() override;
    virtual void stateOut() override;
    
private:
    void addUI();
};

#endif /* QFLMainLayer_hpp */
