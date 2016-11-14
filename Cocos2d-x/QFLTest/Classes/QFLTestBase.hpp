//
//  QFLTestBase.hpp
//  QFLTest
//
//  Created by QuFangliu on 2016/10/24.
//
//

#ifndef QFLTestBase_hpp
#define QFLTestBase_hpp

#include <stdio.h>
#include "cocos2d.h"

#include "QFLTools/QFLHelper.hpp"

class QFLTestBase : public cocos2d::Layer
{
CC_CONSTRUCTOR_ACCESS:
    QFLTestBase();
    virtual ~QFLTestBase();
    virtual bool init();
    static QFLTestBase* create();
    
protected:
    virtual void enterTest();   //需要重载的函数，作为测试入口
    
private:
    void addBaseUI();           //添加基础的黑色背景和返回按钮
};

#endif /* QFLTestBase_hpp */
