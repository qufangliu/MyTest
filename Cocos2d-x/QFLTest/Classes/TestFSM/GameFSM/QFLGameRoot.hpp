//
//  QFLGameRoot.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/24.
//
//

/*
 GameRoot
    |-MainState(MainLayer)
        |-MainState(LogoLayer)
        |-SettingState(SettingLayer)
        |-StoreState(StoreLayer)
    |-GameState(GameLayer)
        |-PlayState(PlayLayer)
        |-PauseState(PauseLayer)
        |-ResultState(ResultLayer)
 */

#ifndef QFLGameRoot_hpp
#define QFLGameRoot_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "QFLStateNodeBase.hpp"

class QFLGameRoot :public cocos2d::Layer, public QFLStateNodeBase
{
public:
    QFLGameRoot();
    virtual ~QFLGameRoot();
    virtual bool init() override;
    CREATE_FUNC(QFLGameRoot);

    //因为包含了子类，所以要有状态与状态转换
    //状态
    enum State
    {
        MainState   = 1,
        GameState   = 2
    };
    virtual void setState(State eState);    //因为State所指内容与父类中不同，不能写override
    
    //本身也是一个状态，所以要有逻辑处理
    virtual void stateIn() override;
    virtual void stateOut() override;
    
private:
    void addUI();
    State m_eState;
};

#endif /* QFLGameRoot_hpp */
