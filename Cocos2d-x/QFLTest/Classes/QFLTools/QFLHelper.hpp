//
//  QFLHelper.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/8/30.
//
//

#ifndef QFLHelper_hpp
#define QFLHelper_hpp

#include <stdio.h>
#include "cocos2d.h"

class QFLHelper
{
public:
    virtual ~QFLHelper();
    static QFLHelper* getInstance();
    
private:
    QFLHelper();
    void initHelper();
    
public:
    
    //==========
    //屏幕Size相关
    //==========
    cocos2d::Size getWinSize() { return cocos2d::Director::getInstance()->getWinSize(); }
    cocos2d::Size getVisibleSize() { return cocos2d::Director::getInstance()->getVisibleSize(); }
    cocos2d::Vec2 getVisibleOrigin() { return cocos2d::Director::getInstance()->getVisibleOrigin(); }
    
    float getScreenTop() { return getVisibleOrigin().y + getVisibleSize().height; }
    float getScreenBottom() { return getVisibleOrigin().y; }
    float getScreenLeft() { return getVisibleOrigin().x; }
    float getScreenRight() { return getVisibleOrigin().x + getVisibleSize().width; }
    
    cocos2d::Vec2 getScreenCenter() { return getVisibleSize() * 0.5; }
    cocos2d::Vec2 getScreenLeftBottom() { return getVisibleOrigin(); }
    cocos2d::Vec2 getScreenLeftTop() { return cocos2d::Vec2(getScreenLeft(), getScreenTop()); }
    cocos2d::Vec2 getScreenRightBottom() { return cocos2d::Vec2(getScreenRight(), getScreenBottom()); }
    cocos2d::Vec2 getScreenRightTop() { return cocos2d::Vec2(getScreenRight(), getScreenTop()); }
    
    
    //==========
    //屏蔽、背景、按钮等
    //==========
    
    //添加删除触摸屏蔽层
    void addNoTouchLayer(cocos2d::Node *pNode, int nZorder = 100);
    void removeNoTouchLayer(cocos2d::Node *pNode);
    //添加触摸屏蔽
    void addNoTouchListener(cocos2d::Node *pNode);
    //添加Back按钮
    void addBackMenu(cocos2d::Node *pNode, int nZorder = 100);
    //生成纯色层
    cocos2d::Layer* getColorfulLayer(cocos2d::Color4B color = cocos2d::Color4B::BLACK, int nOpacity = 255);
    //生成黑色背景＋触摸屏蔽＋Back按钮
    cocos2d::Layer* getBlackBGLayer();
    
private:
    
    //==========
    //屏蔽、背景、按钮等
    //==========
    std::map<cocos2d::Node*, int> m_mapNoTouchCounter;  //触摸屏蔽的计数
    
};

//==========
//工具宏
//==========

//Helper的宏
#define QFL_HELPER      QFLHelper::getInstance()

//Size相关的宏
#define SCREEN_VISIBLE_SIZE     QFL_HELPER->getVisibleSize()
#define SCREEN_WIN_SIZE         QFL_HELPER->getWinSize()
#define SCREEN_VISIBLE_ORIGIN   QFL_HELPER->getVisibleOrigin()

#define SCREEN_TOP              QFL_HELPER->getScreenTop()
#define SCREEN_BOTTOM           QFL_HELPER->getScreenBottom()
#define SCREEN_LEFT             QFL_HELPER->getScreenLeft()
#define SCREEN_RIGHT            QFL_HELPER->getScreenRight()

#define SCREEN_CENTER           QFL_HELPER->getScreenCenter()
#define SCREEN_LEFT_BOTTOM      QFL_HELPER->getScreenLeftBottom()
#define SCREEN_LEFT_TOP         QFL_HELPER->getScreenLeftTop()
#define SCREEN_RIGHT_BOTTOM     QFL_HELPER->getScreenRightBottom()
#define SCREEN_RIGHT_TOP        QFL_HELPER->getScreenRightTop()

//==========
//常量配置
//==========
#define SC(T)   static const T
namespace QFLConfig {
    SC(std::string) strSystemFontName       = "Arial";      //测试中所有使用系统字体的字体名
    SC(int) nSystemFontSize                 = 40;           //测试中所有使用系统字体的字体大小
}

#endif /* QFLHelper_hpp */
