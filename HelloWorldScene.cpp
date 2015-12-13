#include "HelloWorldScene.h"
#include "MenuScene.h"
#include "EndScene.h"

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
//	scoreboard(enemycount);
	setMissileInterface();
	initGameover();
	__String *tempScore = __String::createWithFormat("%i", score);
	scorelabel = LabelTTF::create(tempScore->getCString(), "Perfect Dark Zone.ttf", 40);
	scorelabel->setPosition(Vec2(150, 680));
	this->addChild(scorelabel, 150);
	this->scheduleUpdate();


	return true;
}

//void HelloWorld::scoreboard(int enemycount) {
//	__String *tempScore = __String::createWithFormat("%i", score);
//	//auto label = Label::createWithTTF("Score: 0 ", "Perfect Dark Zone.ttf", 20);
//	label = LabelTTF::create(tempScore->getCString(), "Perfect Dark Zone.ttf", 40);
////	label->setTextColor(Color4B::MAGENTA);
////	label->enableOutline(Color4B::WHITE, 3);
//	label->setPosition(Vec2(150, 680));
//	this->addChild(label, 150);
//	this->scheduleUpdate();
////	score += (enemycount*10);
////	sprintf(szTEMP, "score:%06i", score);
////	label->setString(szTEMP);
//}



void HelloWorld::initPlayer() {
	sPlayer = Sprite::create();
	sPlayer->setPosition(Vec2(winSize.width / 2, -50));        //화면 아래에서 안보이다가 Title이 사라지면 앞으로 나올예정
	sPlayer->setTag(TAG_SPRITE_PLAYER);
	this->addChild(sPlayer, 200);

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

