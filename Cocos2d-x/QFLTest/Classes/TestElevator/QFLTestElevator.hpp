//
//  QFLTestElevator.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/18.
//
//

#ifndef QFLTestElevator_hpp
#define QFLTestElevator_hpp

#include <stdio.h>
#include "cocos2d.h"

class QFLTestElevator : public cocos2d::Layer
{
public:
    QFLTestElevator();
    virtual ~QFLTestElevator();
    virtual bool init();
    CREATE_FUNC(QFLTestElevator);
    
public:
    
private:
    void initSelf();
    
    //add testing button
    void addElevator(const std::string &strText, const std::function<void()> &funcCall);
    
private:
    cocos2d::Menu *m_pMenu;
    int m_nCount;
};

#endif /* QFLTestElevator_hpp */
