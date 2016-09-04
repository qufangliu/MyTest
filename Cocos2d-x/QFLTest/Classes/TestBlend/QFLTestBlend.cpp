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
    this->showExample("{GL_DST_COLOR, GL_ONE}", {GL_DST_COLOR, GL_ONE});
    this->showExample("{GL_DST_ALPHA, GL_ONE}", {GL_DST_ALPHA, GL_ONE});
    this->showExample("{GL_ZERO, GL_ONE}", {GL_ZERO, GL_ONE});
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
    
    //生成Example(原本打算用LayerColor,但是LayerColor没有setBlend方法。。。)
    //Red,1
    auto pRed = Sprite::create("TestBlend/Images/Red.png");
    pRed->setPosition(Vec2(pPanel->getContentSize().width - pRed->getContentSize().width * 0.75,
                           pPanel->getContentSize().height * 0.5 + pRed->getContentSize().height * 0.5));
    pPanel->addChild(pRed, 1);
    //Green,2
    auto pGreen = Sprite::create("TestBlend/Images/Green.png");
    pGreen->setPosition(Vec2(pPanel->getContentSize().width - pGreen->getContentSize().width * 0.5,
                             pPanel->getContentSize().height * 0.5));
    pPanel->addChild(pGreen, 2);
    //Blue,3
    auto pBlue = Sprite::create("TestBlend/Images/Blue.png");
    pBlue->setPosition(Vec2(pPanel->getContentSize().width - pBlue->getContentSize().width,
                            pPanel->getContentSize().height * 0.5));
    pPanel->addChild(pBlue, 3);
    
    //Blend，这里对三个精灵都设置了同样的blendfunc
    pRed->setBlendFunc(blend);
    pGreen->setBlendFunc(blend);
    pBlue->setBlendFunc(blend);
    
    //添加Item到List
    m_pListExample->pushBackCustomItem(pPanel);
}

cocos2d::Layer* QFLTestBlend::getColorfulLayer(cocos2d::Size size, cocos2d::Color4B color, const std::string &strText)
{
    //LayerColor
    auto pLayer = LayerColor::create(color);
    pLayer->setContentSize(size);
    
    //Text
    if (strText != "") {
        auto pText = Label::createWithSystemFont(strText, "", 30);
        pText->setPosition(pLayer->getContentSize() * 0.5);
        pLayer->addChild(pText);
    }
    
    return pLayer;
}



