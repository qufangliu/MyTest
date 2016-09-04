//
//  QFLTestSimpleAudio.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/4.
//
//

#ifndef QFLTestSimpleAudio_hpp
#define QFLTestSimpleAudio_hpp

#include <stdio.h>
#include "cocos2d.h"

class QFLTestSimpleAudio : public cocos2d::Layer
{
public:
    QFLTestSimpleAudio();
    virtual ~QFLTestSimpleAudio();
    virtual bool init();
    CREATE_FUNC(QFLTestSimpleAudio);
    
private:
    void addUI();
    void menuCallback(cocos2d::Ref *pSender);
    
    cocos2d::MenuItemFont* getMenuItem(const std::string &strText, const std::string &strName);
    
private:
    int m_nBtnCounter;
    cocos2d::Label *m_pLabel;
};

#endif /* QFLTestSimpleAudio_hpp */
