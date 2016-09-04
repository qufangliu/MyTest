//
//  QFLTestStreak.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/4.
//
//

#ifndef QFLTestStreak_hpp
#define QFLTestStreak_hpp

#include <stdio.h>
#include "cocos2d.h"

class QFLTestMotionStreak : public cocos2d::Layer
{
public:
    QFLTestMotionStreak();
    virtual ~QFLTestMotionStreak();
    virtual bool init();
    CREATE_FUNC(QFLTestMotionStreak);
    
    virtual bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
    virtual void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
    virtual void onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
    
private:
    void addUI();
    void playStreak();  //玩一玩条纹
    
private:
    cocos2d::MotionStreak *m_pStreak;
    
};

#endif /* QFLTestStreak_hpp */
