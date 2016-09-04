//
//  QFLTestSimpleAudio.cpp
//  QFLTest
//
//  Created by QuFangliu on 16/9/4.
//
//

#include "QFLTestSimpleAudio.hpp"

#include "SimpleAudioEngine.h"

#include "QFLTools/QFLHelper.hpp"

USING_NS_CC;
using namespace CocosDenshion;

QFLTestSimpleAudio::QFLTestSimpleAudio()
{
    m_nBtnCounter = 0;
    m_pLabel = nullptr;
}

QFLTestSimpleAudio::~QFLTestSimpleAudio()
{
    
}

bool QFLTestSimpleAudio::init()
{
    if (!Layer::init()) {
        return false;
    }
    else {
        this->addUI();
        return true;
    }
}

void QFLTestSimpleAudio::addUI()
{
    //添加背景
    this->addChild(QFL_HELPER->getBlackBGLayer());
    
    //返回按钮
    QFL_HELPER->addBackMenu(this);
    
    //加测试按钮(菜单)
    auto pMenu = Menu::create();
    pMenu->setPosition(Vec2::ZERO);
    this->addChild(pMenu);
    
    //预加载背景音乐Grand
    pMenu->addChild(this->getMenuItem("PreloadBG->Grand", "PreloadGrand"));
    //预加载背景音乐Happy
    pMenu->addChild(this->getMenuItem("PreloadBG->Happy", "PreloadHappy"));
    //播放背景音乐Grand
    pMenu->addChild(this->getMenuItem("PlayBGMusic->Grand", "PlayBGMGrand"));
    //播放背景音乐Happy
    pMenu->addChild(this->getMenuItem("PlayBGMusic->Happy", "PlayBGMHappy"));
    //停止背景音乐
    pMenu->addChild(this->getMenuItem("StopBGMusic", "StopBGM"));
    //当前是否在播放背景音乐
    pMenu->addChild(this->getMenuItem("IsBGMPlaying", "IsBGMPlaying"));
    
    //加显示栏
    m_pLabel = Label::createWithSystemFont("", "", 40);
    m_pLabel->setPosition(SCREEN_CENTER.x, SCREEN_BOTTOM + 40);
    this->addChild(m_pLabel);
}

void QFLTestSimpleAudio::menuCallback(cocos2d::Ref *pSender)
{
    auto pBtn = (Node*)pSender;
    //用Name来判断是哪一个按钮
    if (pBtn->getName() == "PreloadGrand") {
        SimpleAudioEngine::getInstance()->preloadBackgroundMusic("TestSimpleAudio/Sounds/Grand.mp3");
        m_pLabel->setString("BGM->load->Grand");
    }
    else if (pBtn->getName() == "PreloadHappy") {
        SimpleAudioEngine::getInstance()->preloadBackgroundMusic("TestSimpleAudio/Sounds/Happy.mp3");
        m_pLabel->setString("BGM->load->Happy");
    }
    else if (pBtn->getName() == "PlayBGMGrand") {
        SimpleAudioEngine::getInstance()->playBackgroundMusic("TestSimpleAudio/Sounds/Grand.mp3", true);
        m_pLabel->setString("BGM->play->Grand");
    }
    else if (pBtn->getName() == "PlayBGMHappy") {
        SimpleAudioEngine::getInstance()->playBackgroundMusic("TestSimpleAudio/Sounds/Happy.mp3", true);
        m_pLabel->setString("BGM->play->Happy");
    }
    else if (pBtn->getName() == "StopBGM") {
        SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    }
    else if (pBtn->getName() == "IsBGMPlaying") {
        if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()) {
            MessageBox("BGM is playing!", "Tip");
        }
        else {
            MessageBox("BGM is not playing!", "Tip");
        }
    }
    else {
        CCASSERT(false, "Invalid button name.");
    }
}

cocos2d::MenuItemFont* QFLTestSimpleAudio::getMenuItem(const std::string &strText, const std::string &strName)
{
    //计数
    m_nBtnCounter++;
    //生成MenuItem
    auto pMenuItem = MenuItemFont::create(strText, CC_CALLBACK_1(QFLTestSimpleAudio::menuCallback, this));
    pMenuItem->setName(strName);
    pMenuItem->setPosition(SCREEN_CENTER.x, SCREEN_TOP - m_nBtnCounter * 50.0f);
    return pMenuItem;
}






