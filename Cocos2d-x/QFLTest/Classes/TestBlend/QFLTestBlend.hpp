//
//  QFLTestBlend.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/8/31.
//
//

#ifndef QFLTestBlend_hpp
#define QFLTestBlend_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

class QFLTestBlend : public cocos2d::Layer
{
public:
    QFLTestBlend();
    virtual ~QFLTestBlend();
    virtual bool init();
    CREATE_FUNC(QFLTestBlend);
    
private:
    void addUI();
    void addTestValue();
    
    void showExample(const std::string &strText, cocos2d::BlendFunc blend);
    
private:
    cocos2d::ui::ListView *m_pListExample;
    int m_nExampleCount;
};

#endif /* QFLTestBlend_hpp */
