#include "HelloWorldScene.h"
#include "MenuScene.h"

USING_NS_CC;
typedef std::vector<Sprite*> where;
Scene* HelloWorld::createScene()
{
	auto scene = Scene::create();
	auto layer = HelloWorld::create();
	scene->addChild(layer);
	return scene;
}

bool HelloWorld::init()
{
	if (!Layer::init())
	{
		return false;
	}
	winSize = Director::getInstance()->getWinSize();
	srand((int)time(NULL));

	listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	initBG();
	initTitle();
	initGameData();
	initPlayer();
	initGameover();

	return true;
}

void HelloWorld::initPlayer() {
	sPlayer = Sprite::create();
	sPlayer->setPosition(Vec2(winSize.width / 2, 200 - 250));        //화면 아래에서 안보이다가 Title이 사라지면 앞으로 나올예정
	sPlayer->setTag(TAG_SPRITE_PLAYER);
	this->addChild(sPlayer);

	//통짜 이미지에 plist가 없으므로 texture로 잘라서 사용
	auto texture = Director::getInstance()->getTextureCache()->addImage("Spaceship.png");
	//auto texture = TextureCache::getInstance()->addImage("/sprites/Spaceship.png");    //위와 동일
	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1f);
	for (int i = 0; i < 4; i++) {
		animation->addSpriteFrameWithTexture(texture, Rect(i * 96, 0, 96, 104));
	}
	auto animate = Animate::create(animation);
	sPlayer->runAction(RepeatForever::create(animate));

}
