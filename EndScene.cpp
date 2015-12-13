#include "EndScene.h"
#include "MenuScene.h"
using namespace CocosDenshion;

Scene* EndScene::createScene()
{
	auto scene = Scene::create();
	auto layer = EndScene::create();
	scene->addChild(layer, 10);
	return scene;
}

bool EndScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm.mp3", true);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("bgm.mp3");
	auto bg = Sprite::create("EndScene.png");
	bg->setPosition(Point(650, 360));
	this->addChild(bg, 11);

	return true;
}


void EndScene::EndCallback(cocos2d::Ref* pSender)
{
	exit(0);
}
