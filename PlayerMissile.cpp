#include "HelloWorldScene.h"

void HelloWorld::setMissile(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //�̻��� ����Ʈ �߰�
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("p1.png");
	vMissile.pushBack(sMissile);                                            //���Ϳ� �̻��� Sprite ����
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //�÷��̾��� ��ġ���� y������ 60��ŭ �տ��� �̻��� �߻�
	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //�̻����� 2�ʵ��� ������� �̵� ��
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //�̻����� �����ϴ� �Լ� ȣ��
		NULL));
	this->addChild(sMissile);
}
void HelloWorld::upGradeP2(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //�̻��� ����Ʈ �߰�
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("p2.png");
	vMissile.pushBack(sMissile);                                            //���Ϳ� �̻��� Sprite ����
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //�÷��̾��� ��ġ���� y������ 60��ŭ �տ��� �̻��� �߻�
	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //�̻����� 2�ʵ��� ������� �̵� ��
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //�̻����� �����ϴ� �Լ� ȣ��
		NULL));
	this->addChild(sMissile);
}

void HelloWorld::upGradeP3(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //�̻��� ����Ʈ �߰�
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("p3.png");
	vMissile.pushBack(sMissile);                                            //���Ϳ� �̻��� Sprite ����
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //�÷��̾��� ��ġ���� y������ 60��ŭ �տ��� �̻��� �߻�
	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //�̻����� 2�ʵ��� ������� �̵� ��
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //�̻����� �����ϴ� �Լ� ȣ��
		NULL));
	this->addChild(sMissile);
}

void HelloWorld::upGradeP4(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //�̻��� ����Ʈ �߰�
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("p4.png");
	vMissile.pushBack(sMissile);                                            //���Ϳ� �̻��� Sprite ����
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //�÷��̾��� ��ġ���� y������ 60��ŭ �տ��� �̻��� �߻�
	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //�̻����� 2�ʵ��� ������� �̵� ��
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //�̻����� �����ϴ� �Լ� ȣ��
		NULL));
	this->addChild(sMissile);
}

void HelloWorld::upGradeF2(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //�̻��� ����Ʈ �߰�
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("f2.png");
	vMissile.pushBack(sMissile);                                            //���Ϳ� �̻��� Sprite ����
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //�÷��̾��� ��ġ���� y������ 60��ŭ �տ��� �̻��� �߻�
	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //�̻����� 2�ʵ��� ������� �̵� ��
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //�̻����� �����ϴ� �Լ� ȣ��
		NULL));
	this->addChild(sMissile);
}

void HelloWorld::upGradeF3(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //�̻��� ����Ʈ �߰�
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("f3.png");
	vMissile.pushBack(sMissile);                                            //���Ϳ� �̻��� Sprite ����
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //�÷��̾��� ��ġ���� y������ 60��ŭ �տ��� �̻��� �߻�
	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //�̻����� 2�ʵ��� ������� �̵� ��
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //�̻����� �����ϴ� �Լ� ȣ��
		NULL));
	this->addChild(sMissile);
}

void HelloWorld::upGradeF4(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //�̻��� ����Ʈ �߰�
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("f4.png");
	vMissile.pushBack(sMissile);                                            //���Ϳ� �̻��� Sprite ����
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //�÷��̾��� ��ġ���� y������ 60��ŭ �տ��� �̻��� �߻�
	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //�̻����� 2�ʵ��� ������� �̵� ��
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //�̻����� �����ϴ� �Լ� ȣ��
		NULL));
	this->addChild(sMissile);
}

void HelloWorld::upGradeL2(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //�̻��� ����Ʈ �߰�
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("l2.png");
	vMissile.pushBack(sMissile);                                            //���Ϳ� �̻��� Sprite ����
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //�÷��̾��� ��ġ���� y������ 60��ŭ �տ��� �̻��� �߻�
	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //�̻����� 2�ʵ��� ������� �̵� ��
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //�̻����� �����ϴ� �Լ� ȣ��
		NULL));
	this->addChild(sMissile);
}

void HelloWorld::upGradeL3(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //�̻��� ����Ʈ �߰�
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("l3.png");
	vMissile.pushBack(sMissile);                                            //���Ϳ� �̻��� Sprite ����
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //�÷��̾��� ��ġ���� y������ 60��ŭ �տ��� �̻��� �߻�
	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //�̻����� 2�ʵ��� ������� �̵� ��
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //�̻����� �����ϴ� �Լ� ȣ��
		NULL));
	this->addChild(sMissile);
}

void HelloWorld::upGradeL4(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //�̻��� ����Ʈ �߰�
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("l4.png");
	vMissile.pushBack(sMissile);                                            //���Ϳ� �̻��� Sprite ����
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //�÷��̾��� ��ġ���� y������ 60��ŭ �տ��� �̻��� �߻�
	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //�̻����� 2�ʵ��� ������� �̵� ��
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //�̻����� �����ϴ� �Լ� ȣ��
		NULL));
	this->addChild(sMissile);
}

void HelloWorld::missile(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //�̻��� ����Ʈ �߰�
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("Explosion1.jpg");
	vMissile.pushBack(sMissile);                                            //���Ϳ� �̻��� Sprite ����
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //�÷��̾��� ��ġ���� y������ 60��ŭ �տ��� �̻��� �߻�

	CCSpriteFrame* sprite_frame1 = CCSpriteFrame::create("Explosion2.jpg", CCRect(0, 0, 85, 121));
	CCSpriteFrame* sprite_frame2 = CCSpriteFrame::create("Explosion3.jpg", CCRect(0, 0, 85, 121));
	CCSpriteFrame* sprite_frame3 = CCSpriteFrame::create("Explosion4.jpg", CCRect(0, 0, 85, 121));
	CCSpriteFrame* sprite_frame4 = CCSpriteFrame::create("Explosion5.jpg", CCRect(0, 0, 85, 121));
	CCSpriteFrame* sprite_frame5 = CCSpriteFrame::create("Explosion6.jpg", CCRect(0, 0, 85, 121));
	CCSpriteFrame* sprite_frame6 = CCSpriteFrame::create("Explosion7.jpg", CCRect(0, 0, 85, 121));
	CCSpriteFrame* sprite_frame7 = CCSpriteFrame::create("Explosion8.jpg", CCRect(0, 0, 85, 121));
	CCSpriteFrame* sprite_frame8 = CCSpriteFrame::create("Explosion9.jpg", CCRect(0, 0, 85, 121));
	CCSpriteFrame* sprite_frame9 = CCSpriteFrame::create("Explosion10.jpg", CCRect(0, 0, 85, 121));
	Animation* animation = Animation::create();
	animation->setDelayPerUnit(0.5f);
	animation->addSpriteFrame(sprite_frame1);
	animation->addSpriteFrame(sprite_frame2);
	animation->addSpriteFrame(sprite_frame3);
	animation->addSpriteFrame(sprite_frame4);
	animation->addSpriteFrame(sprite_frame5);
	animation->addSpriteFrame(sprite_frame6);
	animation->addSpriteFrame(sprite_frame7);
	animation->addSpriteFrame(sprite_frame8);
	animation->addSpriteFrame(sprite_frame9);

	sMissile->runAction(Sequence::create(
		MoveBy::create(2.0f, Vec2(0, winSize.width)),                        //�̻����� 2�ʵ��� ������� �̵� ��
		CCAnimate::create(animation),
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //�̻����� �����ϴ� �Լ� ȣ��
		NULL));
	this->addChild(sMissile);
}

void HelloWorld::upGradeSub(float fDelta) {
	SimpleAudioEngine::getInstance()->playEffect("shoot.wav");        //�̻��� ����Ʈ �߰�
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	auto sMissile = Sprite::create("sub2.png");
	vMissile.pushBack(sMissile);                                            //���Ϳ� �̻��� Sprite ����
	sMissile->setPosition(Vec2(sPlayer->getPosition() + Vec2(0, 60)));        //�÷��̾��� ��ġ���� y������ 60��ŭ �տ��� �̻��� �߻�
	//���� for��
	for (SpriteEnemy* enemy : vEnemy) {
		if (enemy->getPositionY() != NULL && enemy->getPositionY() > sPlayer->getPositionY()) {
			sMissile->runAction(Sequence::create(
				MoveBy::create(10.0f, Vec2(-5 * (sPlayer->getPosition() - enemy->getPosition()))),                        //�̻����� 2�ʵ��� ������� �̵� ��
				CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //�̻����� �����ϴ� �Լ� ȣ��
				NULL));
		}
		else {
			sMissile->runAction(Sequence::create(
				MoveBy::create(10.0f, Vec2(0, winSize.width)),                        //�̻����� 2�ʵ��� ������� �̵� ��
				CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetMissile, this)),    //�̻����� �����ϴ� �Լ� ȣ��
				NULL));
		}
	}
	this->addChild(sMissile);
}

void HelloWorld::resetMissile(Ref* pSender) {
	auto spr = (Sprite*)pSender;
	vMissile.eraseObject(spr);        //������ �̻��� ����
	this->removeChild(spr);            //�߻��� ��������Ʈ ����
}