//
//  QFLStateNodeBase.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/22.
//
//
/*
 这里是一个状态类的基类，状态机中的每个状态类（包括根状态）都继承自这个类即可。
 使用这个基类派生出子类，可以形成树状的状态机结构
 */

#ifndef QFLStateNodeBase_hpp
#define QFLStateNodeBase_hpp

#include <stdio.h>

class QFLStateNodeBase
{
public:
    
    //构造析构函数
    QFLStateNodeBase();
    virtual ~QFLStateNodeBase();
    
    //父状态类存储操作
    QFLStateNodeBase* getParentState() { return m_pParentState; }
    virtual void setParentNode(QFLStateNodeBase *pParentNode) { m_pParentState = pParentNode; }
    
    //父类需要实现的内容
    //状态
    enum State
    {
        
    };
    //状态转换
    virtual void setState(State eState) {};    //包含子状态的状态，才需要实现这个函数
    
    //当前状态的逻辑处理
    virtual void stateIn() = 0;
    virtual void stateOut() = 0;
    
    QFLStateNodeBase* m_pParentState;                   //父状态类（单独一个）
    QFLStateNodeBase* m_pCurrentState;                  //当前状态类
//    State m_eState; //状态标志    //这里没有办法抽象出来
};

#endif /* QFLStateNodeBase_hpp */
