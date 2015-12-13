#ifndef __END_SCENE_H__
#define __END_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "MenuScene.h"
USING_NS_CC;

class EndScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(EndScene);
	//void StartCallback(cocos2d::Ref* pSender);
	void EndCallback(cocos2d::Ref* pSender);
};

#endif
