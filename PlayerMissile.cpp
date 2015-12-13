#include "HelloWorldScene.h"

void HelloWorld::setMissile(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //미사일 이펙트 추가
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("p1.png");
	vMissile.pushBack(sMissile);                                            //백터에 미사일 Sprite 저장
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //플레이어의 위치에서 y축으로 60만큼 앞에서 미사일 발사
	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //미사일이 2초동안 상단으로 이동 후
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //미사일을 제거하는 함수 호출
		NULL));
	this->addChild(sMissile, 30);
}
void HelloWorld::upGradeP2(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //미사일 이펙트 추가
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("p2.png");
	vMissile.pushBack(sMissile);                                            //백터에 미사일 Sprite 저장
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //플레이어의 위치에서 y축으로 60만큼 앞에서 미사일 발사
	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //미사일이 2초동안 상단으로 이동 후
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //미사일을 제거하는 함수 호출
		NULL));
	this->addChild(sMissile, 31);
}

void HelloWorld::upGradeP3(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //미사일 이펙트 추가
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("p3.png");
	vMissile.pushBack(sMissile);                                            //백터에 미사일 Sprite 저장
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //플레이어의 위치에서 y축으로 60만큼 앞에서 미사일 발사
	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //미사일이 2초동안 상단으로 이동 후
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //미사일을 제거하는 함수 호출
		NULL));
	this->addChild(sMissile, 32);
}

void HelloWorld::upGradeP4(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //미사일 이펙트 추가
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("p4.png");
	vMissile.pushBack(sMissile);                                            //백터에 미사일 Sprite 저장
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //플레이어의 위치에서 y축으로 60만큼 앞에서 미사일 발사
	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //미사일이 2초동안 상단으로 이동 후
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //미사일을 제거하는 함수 호출
		NULL));
	this->addChild(sMissile, 33);
}

void HelloWorld::upGradeF2(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //미사일 이펙트 추가
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("f2.png");
	vMissile.pushBack(sMissile);                                            //백터에 미사일 Sprite 저장
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //플레이어의 위치에서 y축으로 60만큼 앞에서 미사일 발사
	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //미사일이 2초동안 상단으로 이동 후
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //미사일을 제거하는 함수 호출
		NULL));
	this->addChild(sMissile, 34);
}

void HelloWorld::upGradeF3(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //미사일 이펙트 추가
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("f3.png");
	vMissile.pushBack(sMissile);                                            //백터에 미사일 Sprite 저장
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //플레이어의 위치에서 y축으로 60만큼 앞에서 미사일 발사
	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //미사일이 2초동안 상단으로 이동 후
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //미사일을 제거하는 함수 호출
		NULL));
	this->addChild(sMissile, 35);
}

void HelloWorld::upGradeF4(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //미사일 이펙트 추가
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("f4.png");
	vMissile.pushBack(sMissile);                                            //백터에 미사일 Sprite 저장
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //플레이어의 위치에서 y축으로 60만큼 앞에서 미사일 발사
	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //미사일이 2초동안 상단으로 이동 후
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //미사일을 제거하는 함수 호출
		NULL));
	this->addChild(sMissile, 36);
}

void HelloWorld::upGradeL2(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //미사일 이펙트 추가
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("l2.png");
	vMissile.pushBack(sMissile);                                            //백터에 미사일 Sprite 저장
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //플레이어의 위치에서 y축으로 60만큼 앞에서 미사일 발사
	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //미사일이 2초동안 상단으로 이동 후
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //미사일을 제거하는 함수 호출
		NULL));
	this->addChild(sMissile, 37);
}

void HelloWorld::upGradeL3(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //미사일 이펙트 추가
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("l3.png");
	vMissile.pushBack(sMissile);                                            //백터에 미사일 Sprite 저장
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //플레이어의 위치에서 y축으로 60만큼 앞에서 미사일 발사
	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //미사일이 2초동안 상단으로 이동 후
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //미사일을 제거하는 함수 호출
		NULL));
	this->addChild(sMissile, 38);
}

void HelloWorld::upGradeL4(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //미사일 이펙트 추가
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("l4.png");
	vMissile.pushBack(sMissile);                                            //백터에 미사일 Sprite 저장
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //플레이어의 위치에서 y축으로 60만큼 앞에서 미사일 발사
	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //미사일이 2초동안 상단으로 이동 후
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //미사일을 제거하는 함수 호출
		NULL));
	this->addChild(sMissile, 39);
}

void HelloWorld::ChargeMissile(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("charge.png");
	vMissile.pushBack(sMissile);
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 400)));
	sMissile->runAction(Sequence::create(
	MoveBy::create(1.5f, Vec2(0, winSize.width+1000)),                        //미사일이 2초동안 상단으로 이동 후
	CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //미사일을 제거하는 함수 호출
	NULL));
	this->addChild(sMissile, 500);
}
//void HelloWorld::upGradeSub(float fDelta) {
//	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //미사일 이펙트 추가
//	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
//	auto sMissile = Sprite::create("sub2.png");
//	vMissile.pushBack(sMissile);                                            //백터에 미사일 Sprite 저장
//	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //플레이어의 위치에서 y축으로 60만큼 앞에서 미사일 발사
//      //백터 for문
//	for (SpriteEnemy* enemy : vEnemy) {
//		if (enemy->getPositionY() != NULL && enemy->getPositionY() > sPlayer->getPositionY()) {
//			sMissile->runAction(Sequence::create(
//				MoveBy::create(10.0f, Vec2(-5 * (sPlayer->getPosition() - enemy->getPosition()))),                        //미사일이 2초동안 상단으로 이동 후
//				CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //미사일을 제거하는 함수 호출
//				NULL));
//		}
//		else {
//			sMissile->runAction(Sequence::create(
//				MoveBy::create(10.0f, Vec2(0, winSize.width)),                        //미사일이 2초동안 상단으로 이동 후
//				CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //미사일을 제거하는 함수 호출
//				NULL));
//		}
//	}
//	this->addChild(sMissile, 40);
//}

void HelloWorld::resetMissile(Ref* pSender) {
	auto spr = (Sprite*)pSender;
	vMissile.eraseObject(spr);        //백터의 미사일 제거
	this->removeChild(spr);            //발생된 스프라이트 제거
}
