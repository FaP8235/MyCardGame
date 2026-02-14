
#ifndef __GAME_VIEW_H__
#define __GAME_VIEW_H__

#include "cocos2d.h"

class GameView : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(GameView);
};

#endif // __GAME_VIEW_H__
