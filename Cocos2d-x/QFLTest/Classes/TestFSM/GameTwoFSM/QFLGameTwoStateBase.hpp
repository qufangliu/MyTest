//
//  QFLGameTwoStateBase.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/10/8.
//
//

#ifndef QFLGameTwoStateBase_hpp
#define QFLGameTwoStateBase_hpp

#include <stdio.h>
#include "cocos2d.h"

#include "QFLTools/QFLHelper.hpp"

//State的基类
class GameTwoState
{
public:
    virtual ~GameTwoState() {}
    virtual void Enter(cocos2d::Layer* pLayer) = 0;
    virtual void Execute() = 0;
    virtual void Exit(cocos2d::Layer* pLayer) = 0;
};

//游戏中的事件（通过事件来进行状态切换）
namespace GameTwoEvent {
    SC(std::string) Main_Start      = "Event_Main_Start";   //[Main]开始游戏的事件
    SC(std::string) Game_Over       = "Event_Game_Over";    //[Game]结束游戏的事件
    SC(std::string) Result_Home     = "Event_Result_Home";  //[Result]结算界面回主页
    SC(std::string) Result_Replay   = "Event_Result_Replay";//[Result]结算界面重新开始
}


#endif /* QFLGameTwoStateBase_hpp */
