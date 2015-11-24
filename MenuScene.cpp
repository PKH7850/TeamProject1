#include "MenuScene.h"
#include "HelloWorldScene.h"

using namespace CocosDenshion;

Scene* MenuScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MenuScene::create();
	scene->addChild(layer);
	return scene;
}

bool MenuScene::init()
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

	auto startLabel = MenuItemFont::create("Game Start", CC_CALLBACK_1(MenuScene::StartCallback, this));
	auto endLabel = MenuItemFont::create("Exit", CC_CALLBACK_1(MenuScene::EndCallback, this));
	auto menu = Menu::create(startLabel, endLabel, NULL);
	startLabel->setPosition(Point(10, -10));
	endLabel->setPosition(Point(10, -60));
	this->addChild(menu);

	return true;
}

void MenuScene::StartCallback(cocos2d::Ref* pSender)
{
	SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	auto scene = TransitionFadeBL::create(1.0f, HelloWorld::createScene());
	Director::getInstance()->replaceScene(scene);
}

void MenuScene::EndCallback(cocos2d::Ref* pSender)
{
	exit(0);
}

