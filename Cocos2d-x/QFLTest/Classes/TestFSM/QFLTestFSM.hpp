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
//    void startElevator();
    void addTestItem(const std::string &strText, const std::function<void()> &funcCall);
    
private:
    cocos2d::Menu *m_pMenu;
    int m_nCount;
};

#endif /* QFLTestFSM_hpp */
