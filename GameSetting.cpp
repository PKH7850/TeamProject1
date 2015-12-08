#include "HelloWorldScene.h"


void HelloWorld::onEnter()
{
	Layer::onEnter();
	listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = [=](Touch* touch, Event* event)
	{
		log("touch began...");

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		if (rect.containsPoint(locationInNode))
		{
			reZorder(target);

			target->setOpacity(180);
			return true;
		}
		return false;
	};

	listener->onTouchMoved = [](Touch* touch, Event* event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		target->setPosition(target->getPosition() + touch->getDelta());
		CCPoint touchPoint = touch->getLocation();
		if (touchPoint.x > 1250)
		{
			touchPoint.x = 1250;
		}
		else if (touchPoint.x < 10)
		{
			touchPoint.x = 10;
		}
		else if (touchPoint.y < 300)
		{
			touchPoint.y = 300;
		}
		else if (touchPoint.y > 600)
		{
			touchPoint.y = 600;
		}
		CCPoint newLocation = ccp(touchPoint.x, target->getPosition().y);

		target->setPosition(newLocation);
	};

	listener->onTouchEnded = [=](Touch* touch, Event* event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		log("jsprite onTouchesEnded..");
		target->setOpacity(255);
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, sPlayer);
}

void HelloWorld::onExit()
{
	_eventDispatcher->removeAllEventListeners();

	Layer::onExit();
}

void HelloWorld::reZorder(Sprite* pSender)
{
	sPlayer->setZOrder(0);

	pSender->setZOrder(1);
}

void HelloWorld::initGameData() {
	vMissile.clear();
	vEMissile.clear();
	vEnemy.clear();
	vItem.clear();
	vEnemy2.clear();
	//vMidBoss.clear();

	isTitle = true;        //클릭 불가
	isPlayerDie = false;   //플레이어가 죽으면 true
	isGameover = false;    //게임오버가 되면 true

}
void HelloWorld::initBG() {
	SimpleAudioEngine::getInstance()->playBackgroundMusic("menu_bg.mp3");    //타이틀 배경음 추가

	auto node = ParallaxNode::create();
	this->addChild(node);
	node->runAction(RepeatForever::create(Sequence::create(
		MoveBy::create(20.0f, Vec2(0, -720)),
		Place::create(Vec2::ZERO),
		NULL)));

	for (int i = 0; i < 2; i++) {
		auto sprBG = Sprite::create("bg_back.png");
		sprBG->setAnchorPoint(Vec2::ZERO);
		node->addChild(sprBG, 0, Vec2(0, 1), Vec2(0, i * 720));
	}
	for (int i = 0; i < 3; i++) {
		auto sprBG = Sprite::create("bg_middle.png");
		sprBG->setAnchorPoint(Vec2::ZERO);
		node->addChild(sprBG, 1, Vec2(0, 2), Vec2(0, i * 720));
	}
	for (int i = 0; i < 5; i++) {
		auto sprBG = Sprite::create("bg_front.png");
		sprBG->setAnchorPoint(Vec2::ZERO);
		node->addChild(sprBG, 2, Vec2(0, 4), Vec2(0, i * 720));
	}
}
void HelloWorld::initTitle() {
	auto label = Label::createWithTTF("TeamProject", "Schwarzwald Regular.ttf", 140);
	label->setTextColor(Color4B::BLUE);
	label->enableOutline(Color4B::WHITE, 3);
	label->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	label->setTag(TAG_LABEL_TITLE);
	this->addChild(label);
}
void HelloWorld::setTitle() {
	SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm1.mp3");        //배경음 추가
	isTitle = false;        //클릭가능

	auto label = (Label*)this->getChildByTag(TAG_LABEL_TITLE);            //타이틀이 fadeout 으로 사라짐
	label->runAction(FadeOut::create(1.0f));

	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);        //화면 아래에서 안보이다가 Title이 사라지면 앞으로 나오는 액션
	sPlayer->runAction(MoveBy::create(1.0f, Vec2(0, 100)));
	sPlayer->setVisible(true);        //다시 시작시 죽은 플레이어 새로 생성

	this->schedule(schedule_selector(HelloWorld::setMissile), 0.15f);    //플레이어가 미사일 쏘는 간격
	this->schedule(schedule_selector(HelloWorld::setEnemy), 1.0f);        //적 생성하는 간격
	this->scheduleUpdate();
}
bool HelloWorld::onTouchBegan(Touch *touch, Event *unused_event) {

	if (isGameover) {
		resetGameover();
		return true;
	}
	else if (isPlayerDie) {
		return true;
	}
	else if (isTitle) {    //타이틀이 보이면 클릭 못하게 막음
		setTitle();            //타이틀 출력상태에서 터치하면 게임시작됨
		return true;
	}

	return true;
}


void HelloWorld::resetPlayer() {
	isPlayerDie = true;        //플레이어가 죽음
	SimpleAudioEngine::getInstance()->playEffect("explosion.wav");
	auto sPlayer = (Sprite*)getChildByTag(TAG_SPRITE_PLAYER);
	sPlayer->setVisible(false);            //플레이어가 죽었으므로 플레이어를 지움


	auto spr = Sprite::create();        //플레이어가 죽을때 애니메이션 생성
	spr->setPosition(sPlayer->getPosition());
	this->addChild(spr);

	auto ani = Animation::create();
	ani->setDelayPerUnit(0.05f);
	auto texture = Director::getInstance()->getTextureCache()->addImage("Explosion.png");    //통짜 이미지를 텍스쳐로 잘라서 사용
	for (int i = 0; i < 11; i++) {
		ani->addSpriteFrameWithTexture(texture, Rect(i % 5 * 160, i / 5 * 160, 160, 160));    //Explosion.png를 잘라서 순차적으로 사용
	}
	auto animate = Animate::create(ani);
	spr->runAction(animate);

	spr->runAction(Sequence::create(
		DelayTime::create(0.55f),
		RemoveSelf::create(),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::setGameover, this)),
		NULL));

	count = 0;
	this->unschedule(schedule_selector(HelloWorld::setMissile));
	this->unschedule(schedule_selector(HelloWorld::upGradeP2));
	this->unschedule(schedule_selector(HelloWorld::upGradeP3));
	this->unschedule(schedule_selector(HelloWorld::upGradeP4));
	this->unschedule(schedule_selector(HelloWorld::upGradeF2));
	this->unschedule(schedule_selector(HelloWorld::upGradeF3));
	this->unschedule(schedule_selector(HelloWorld::upGradeF4));
	this->unschedule(schedule_selector(HelloWorld::upGradeL2));
	this->unschedule(schedule_selector(HelloWorld::upGradeL3));
	this->unschedule(schedule_selector(HelloWorld::upGradeL4));
	this->unschedule(schedule_selector(HelloWorld::upGradeSub));

}

void HelloWorld::initGameover() {        //게임오버와 다시시작을 그림
	auto label_1 = Label::createWithTTF("GAME OVER", "SAM_5C_27TRG_.TTF", 120);
	label_1->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	label_1->setTextColor(Color4B::RED);
	label_1->setScale(0.0f);
	label_1->setVisible(false);
	label_1->setTag(TAG_LABEL_GAMEOVER_1);
	this->addChild(label_1, 1);

	auto label_2 = Label::createWithTTF("PRESS TO START", "SAM_5C_27TRG_.TTF", 40);
	label_2->setPosition(Vec2(winSize.width / 2, 100));
	label_2->setScale(0.0f);
	label_2->setVisible(false);
	label_2->setTag(TAG_LABEL_GAMEOVER_2);
	this->addChild(label_2, 1);
}

void HelloWorld::setGameover() {        //게임오버시 게임오버와 다시시작 타이틀을 셋팅함
	isGameover = true;

	auto label_1 = (Label*)this->getChildByTag(TAG_LABEL_GAMEOVER_1);
	label_1->runAction(Sequence::create(
		Show::create(),
		Spawn::create(
			ScaleTo::create(1.0f, 1.0f),
			RotateBy::create(1.0f, 360 * 5),
			NULL),
		NULL));

	auto label_2 = (Label*)this->getChildByTag(TAG_LABEL_GAMEOVER_2);
	label_2->runAction(Sequence::create(
		Show::create(),
		DelayTime::create(1.2f),
		ScaleTo::create(0.4f, 1.0f),
		NULL));
}

void HelloWorld::resetGameover()        //게임을 다시시작함
{
	auto label_1 = (Label*)this->getChildByTag(TAG_LABEL_GAMEOVER_1);
	label_1->stopAllActions();
	label_1->setScale(0.0f);
	label_1->setRotation(0);
	label_1->setVisible(false);

	auto label_2 = (Label*)this->getChildByTag(TAG_LABEL_GAMEOVER_2);
	label_2->stopAllActions();
	label_2->setScale(0.0f);
	label_2->setVisible(false);

	for (SpriteEnemy* enemy : vEnemy) {
		this->removeChild(enemy);
	}

	for (SpriteEnemy* enemy2 : vEnemy2) {
		this->removeChild(enemy2);
	}
	/*
	for (MiddleBoss* enemy3 : vMidBoss){
		this->removeChild(enemy3);
	}*/
	/*
	for (Boss* enemy4 : vBoss){
		this->removeChild(enemy4);
	}*/
	for (Sprite* missile : vMissile) {
		this->removeChild(missile);
	}

	for (Sprite* emissile : vEMissile) {
		this->removeChild(emissile);
	}

	for (Sprite* eitem : vItem) {
		this->removeChild(eitem);
	}

	this->unscheduleAllSelectors();

	initGameData();
	setTitle();
}