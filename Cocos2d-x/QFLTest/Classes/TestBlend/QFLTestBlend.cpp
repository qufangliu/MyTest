//
//  QFLTestBlend.cpp
//  QFLTest
//
//  Created by QuFangliu on 16/8/31.
//
//

#include "QFLTestBlend.hpp"
#include "QFLTools/QFLHelper.hpp"

USING_NS_CC;

QFLTestBlend::QFLTestBlend()
{
    m_nExampleCount = 0;
}

QFLTestBlend::~QFLTestBlend()
{
    
}

bool QFLTestBlend::init()
{
    if (!Layer::init()) {
        return false;
    }
    else {
        this->addUI();
        this->addTestValue();
        return true;
    }
}

void QFLTestBlend::addUI()
{
    //加背景
    this->addChild(QFL_HELPER->getBlackBGLayer());
    
    //加返回按钮
    QFL_HELPER->addBackMenu(this);
    
    //加List
    m_pListExample = ui::ListView::create();
    m_pListExample->setContentSize(Size(SCREEN_VISIBLE_SIZE.width - 100, SCREEN_VISIBLE_SIZE.height));  //右边留100px的边
    m_pListExample->setPosition(SCREEN_VISIBLE_ORIGIN);
    m_pListExample->setGravity(cocos2d::ui::ListView::Gravity::CENTER_VERTICAL);
    m_pListExample->setDirection(cocos2d::ui::ScrollView::Direction::VERTICAL);
    m_pListExample->setScrollBarEnabled(false);
    m_pListExample->setBounceEnabled(true);
    this->addChild(m_pListExample);
}

void QFLTestBlend::addTestValue()
{
    //添加测试用Blend
    
    this->showExample("{GL_ONE, GL_ONE}", {GL_ONE, GL_ONE});
    this->showExample("{GL_SRC_ALPHA, GL_ONE}", {GL_SRC_ALPHA, GL_ONE});
    this->showExample("{GL_SRC_COLOR, GL_ONE}", {GL_SRC_COLOR, GL_ONE});
}

void QFLTestBlend::showExample(const std::string &strText, cocos2d::BlendFunc blend)
{
    //计数
    m_nExampleCount ++;
    
    //生成Item
    auto pPanel = ui::Widget::create();
    pPanel->setContentSize(Size(m_pListExample->getContentSize().width, 220));
    
    //添加Text
    auto pLabel = Label::createWithSystemFont(StringUtils::format("%d:%s", m_nExampleCount, strText.c_str()),
                                              QFLConfig::strSystemFontName,
                                              30);
    pLabel->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
    pLabel->setPosition(Vec2(50.0, pPanel->getContentSize().height * 0.5));
    pPanel->addChild(pLabel);
    
    //生成Example
    //1.上半截白色背景
    auto pNodeWhite = Sprite::create("Images/TestBlend/White.png");
    pNodeWhite->setPosition(Vec2(pPanel->getContentSize().width - 25 - pNodeWhite->getContentSize().width * 0.5,
                                 pPanel->getContentSize().height - 10 - pNodeWhite->getContentSize().height * 0.5));
    pPanel->addChild(pNodeWhite);
    //2.左边彩色
    auto pColorfulLeft = Sprite::create("Images/TestBlend/Colorful.png");
    pColorfulLeft->setPosition(Vec2(pPanel->getContentSize().width - 100 - pColorfulLeft->getContentSize().width * 0.5,
                                    10 + pColorfulLeft->getContentSize().height * 0.5));
    pPanel->addChild(pColorfulLeft);
    //3.右边彩色
    auto pColorfulRight = Sprite::create("Images/TestBlend/Colorful.png");
    pColorfulRight->setRotation(90.0);
    pColorfulRight->setPosition(Vec2(pPanel->getContentSize().width - pColorfulRight->getContentSize().width * 0.5,
                                     10 + pColorfulRight->getContentSize().height * 0.5));
    pPanel->addChild(pColorfulRight);
    
    //添加BlendFunc
    pColorfulRight->setBlendFunc(blend);
    
    //添加Item到List
    m_pListExample->pushBackCustomItem(pPanel);
}