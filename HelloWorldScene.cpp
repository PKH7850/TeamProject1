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
	scoreboard(enemycount);
	initGameover();

	return true;
}

void HelloWorld::scoreboard(int enemycount) {
	
	auto label = Label::createWithTTF("Score: 0 ", "Schwarzwald Regular.ttf", 32);
	label->setTextColor(Color4B::MAGENTA);
	label->enableOutline(Color4B::WHITE, 3);
	label->setPosition(Vec2(90, 680));
	this->addChild(label);
	score += (enemycount*10);
	sprintf(szTEMP, "Score: %05i", score);
	label->setString(szTEMP);
}



void HelloWorld::initPlayer() {
	sPlayer = Sprite::create();
	sPlayer->setPosition(Vec2(winSize.width / 2, 200 - 250));        //ȭ�� �Ʒ����� �Ⱥ��̴ٰ� Title�� ������� ������ ���ÿ���
	sPlayer->setTag(TAG_SPRITE_PLAYER);
	this->addChild(sPlayer);

	//��¥ �̹����� plist�� �����Ƿ� texture�� �߶� ���
	auto texture = Director::getInstance()->getTextureCache()->addImage("Spaceship.png");
	//auto texture = TextureCache::getInstance()->addImage("/sprites/Spaceship.png");    //���� ����
	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1f);
	for (int i = 0; i < 4; i++) {
		animation->addSpriteFrameWithTexture(texture, Rect(i * 96, 0, 96, 104));
	}
	auto animate = Animate::create(animation);
	sPlayer->runAction(RepeatForever::create(animate));

}
