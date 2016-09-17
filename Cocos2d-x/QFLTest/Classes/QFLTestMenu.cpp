//
//  QFLTestMenu.cpp
//  QFLTest
//
//  Created by QuFangliu on 16/8/30.
//
//

#include "QFLTestMenu.hpp"

#include "QFLTools/QFLHelper.hpp"

//TestClass
#include "TestBlend/QFLTestBlend.hpp"
#include "TestSimpleAudio/QFLTestSimpleAudio.hpp"
#include "TestMotionStreak/QFLTestStreak.hpp"
#include "TestFSM/QFLTestFSM.hpp"
#include "TestElevator/QFLTestElevator.hpp"

USING_NS_CC;

cocos2d::Scene* QFLTestMenu::createScene()
{
    auto pTestScene = Scene::create();
    auto pTestMenuLayer = QFLTestMenu::create();
    pTestScene->addChild(pTestMenuLayer);
    return pTestScene;
}

bool QFLTestMenu::init()
{
    if (!Layer::init()) {
        return false;
    }
    else {
        this->addUI();
        this->addMenus();
        return true;
    }
}

void QFLTestMenu::addUI()
{
    //获取size
    auto sizeScreen = Director::getInstance()->getVisibleSize();
    
    //生成列表
    m_pListMenu = ui::ListView::create();
    m_pListMenu->setContentSize(sizeScreen);
    m_pListMenu->setPosition(SCREEN_VISIBLE_ORIGIN);
    m_pListMenu->setGravity(cocos2d::ui::ListView::Gravity::CENTER_VERTICAL);
    m_pListMenu->setBounceEnabled(true);
    m_pListMenu->setDirection(cocos2d::ui::ScrollView::Direction::VERTICAL);
    m_pListMenu->setScrollBarEnabled(false);
    this->addChild(m_pListMenu);
    
    //初始化菜单计数
    m_nItemCounter = 0;
}

void QFLTestMenu::addMenus()
{
    //添加菜单项
    this->addMenuItem("TestBlend", [=](){
        this->addChild(QFLTestBlend::create());
    });
    this->addMenuItem("TestSimpleAudioEngine", [=](){
        this->addChild(QFLTestSimpleAudio::create());
    });
    this->addMenuItem("TestMotionStreak", [=](){
        this->addChild(QFLTestMotionStreak::create());
    });
    this->addMenuItem("TestFSM", [=](){
        this->addChild(QFLTestFSM::create());
    });
    this->addMenuItem("TestElevator", [=](){
        this->addChild(QFLTestElevator::create());
    });
}

void QFLTestMenu::addMenuItem(const std::string &strItem, const std::function<void()> &funcCallback)
{
    //计数
    m_nItemCounter ++;
    
    //生成一个Item
    auto pModel = cocos2d::ui::Widget::create();
    pModel->setContentSize(Size(SCREEN_VISIBLE_SIZE.width, 50.0f));
    
    //添加Label
    auto pLabel = Label::createWithSystemFont(StringUtils::format("%d:%s", m_nItemCounter, strItem.c_str()),
                                              QFLConfig::strSystemFontName,
                                              QFLConfig::nSystemFontSize);
    pLabel->setPosition(pModel->getContentSize() * 0.5);
    pModel->addChild(pLabel);
    
    //添加事件
    pModel->setTouchEnabled(true);  //这里很重要
    pModel->addClickEventListener([=](Ref* ref){
        funcCallback();
    });
    
    //添加Item
    m_pListMenu->pushBackCustomItem(pModel);
}











