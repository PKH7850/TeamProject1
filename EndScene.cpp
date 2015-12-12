#include "EndScene.h"
#include "MenuScene.h"
using namespace CocosDenshion;

Scene* EndScene::createScene()
{
	auto scene = Scene::create();
	auto layer = EndScene::create();
	scene->addChild(layer);
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
	auto bg = Sprite::create("menu.png");
	bg->setPosition(Point(650, 360));
	this->addChild(bg);

	auto startLabel = MenuItemFont::create("Back Menu", CC_CALLBACK_1(EndScene::StartCallback, this));
	auto endLabel = MenuItemFont::create("Exit", CC_CALLBACK_1(EndScene::EndCallback, this));
	auto menu = Menu::create(startLabel, endLabel, NULL);
	startLabel->setPosition(Point(10, -10));
	endLabel->setPosition(Point(10, -60));
	this->addChild(menu);

	return true;
}

void EndScene::StartCallback(cocos2d::Ref* pSender)
{
	SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	auto scene = TransitionFadeBL::create(1.0f, MenuScene::createScene());
	Director::getInstance()->replaceScene(scene);
}

void EndScene::EndCallback(cocos2d::Ref* pSender)
{
	exit(0);
}