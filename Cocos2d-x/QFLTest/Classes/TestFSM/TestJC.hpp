//
//  TestJC.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/27.
//
//

#ifndef TestJC_hpp
#define TestJC_hpp

#include <stdio.h>
#include <iostream>

//基类
class Base
{
public:
    Base() { m_pCurrentObj = nullptr; } //构造函数中初始化指针
    virtual ~Base() {}
    
    virtual void showName() = 0;
    
public:
    std::string m_strName = "Base";
    Base *m_pCurrentObj;
};

//派生类
class SubA : public Base
{
public:
    SubA() {}
    virtual ~SubA() {}
    
    void showName() { std::cout << m_strName << std::endl; }
    
    //自己的逻辑方法
    void excute();
};

class SubB : public Base
{
public:
    SubB() {}
    virtual ~SubB() {}
    
    void showName() { std::cout << m_strName << std::endl; }
    
    //自己的逻辑方法
    void excute();
public:
    std::string m_strName = "SubB";
};

#endif /* TestJC_hpp */
