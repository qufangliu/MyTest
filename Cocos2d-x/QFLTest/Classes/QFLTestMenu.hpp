//
//  QFLTestMenu.hpp
//  QFLTest
//
//  Created by QuFangliu on 16/8/30.
//
//

#ifndef QFLTestMenu_hpp
#define QFLTestMenu_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

#include "QFLTools/QFLHelper.hpp"

class QFLTestMenu : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(QFLTestMenu);
    
private:
    void addUI();
    void addMenus();
    
    void addMenuItem(const std::string &strItem, const std::function<void()> &funcCallback);
    
private:
    cocos2d::ui::ListView *m_pListMenu;
    
    int m_nItemCounter;
};

#endif /* QFLTestMenu_hpp */
