#include "HelloWorldScene.h"
//power overwhelming
void HelloWorld::setEnemy(float fDelta) {

	float randX = rand() % (1280 - TAG_PADDING_WIDTH * 2) + TAG_PADDING_WIDTH;        // ���� x��ǥ���� �¿� ȭ�鳡�� ������
	float randX2 = rand() % (1280 - TAG_PADDING_WIDTH * 2) + TAG_PADDING_WIDTH;
	// 50��ŭ���� �߻����� �ʵ��� ����
	auto sEnemy = SpriteEnemy::create();
	auto sEnemy2 = SpriteEnemy::create();

	sEnemy->setPosition(randX, winSize.height + 100);
	sEnemy->isAttack = false;
	sEnemy2->setPosition(randX2, winSize.height + 100);
	sEnemy2->isAttack = false;

	this->addChild(sEnemy);
	this->addChild(sEnemy2);

	int random = rand() % 100;        //100% Ȯ���� ����
	int random2 = rand() % 100;
	float speed = 4.0f;                    //���� �������� �ӵ��� ����
	if (random < 60) {                //60���� Ȯ���� �߻�
		sEnemy->type = 1;
		sEnemy->hp = 5;
		speed = 5.0f;
	}
	else if (random < 85) {            //20���� Ȯ���� �߻�
		sEnemy->type = 2;
		sEnemy->hp = 7;
		sEnemy->setScaleX(1.7f);
		speed = 9.0f;
	}
	else if (random <70)
	{                            //15���� Ȯ���� �߻�
		sEnemy->type = 3;
		sEnemy->hp = 3;
		sEnemy->setScaleY(1.5f);
		sEnemy->setScaleX(0.7f);
		speed = 7.0f;
	}
	if (random2 < 50)
	{
		sEnemy2->hp = 10;
		speed = 3.0f;
	}

	vEnemy.pushBack(sEnemy);
	vEnemy2.pushBack(sEnemy2);

	auto texture = Director::getInstance()->getTextureCache()->addImage("enemy.png");
	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1f);
	for (int i = 0; i < 4; i++) {
		animation->addSpriteFrameWithTexture(texture, Rect(96 * i, 0, 50, 72));
	}
	auto animate = Animate::create(animation);
	sEnemy->runAction(RepeatForever::create(animate));

	sEnemy->runAction(Sequence::create(
		MoveBy::create(speed, Vec2(0, -winSize.height - 200)),
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetEnemy, this)), NULL));

	auto texture2 = Director::getInstance()->getTextureCache()->addImage("enemy3.png");
	auto animation2 = Animation::create();
	animation2->setDelayPerUnit(0.1f);
	for (int i = 0; i < 4; i++) {
		animation2->addSpriteFrameWithTexture(texture2, Rect(96 * i, 0, 40, 72));
	}
	auto animate2 = Animate::create(animation2);
	sEnemy2->runAction(RepeatForever::create(animate2));

	sEnemy2->runAction(Sequence::create(
		MoveBy::create(speed, Vec2(0, -winSize.height - 200)),
		CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetEnemy2, this)), NULL));
}

void HelloWorld::resetEnemy(Ref* pSender) {
	auto spr = (SpriteEnemy*)pSender;
	vEnemy.eraseObject(spr);
	this->removeChild(spr);
}
void HelloWorld::resetEnemy2(Ref* pSender) {
	auto spr2 = (SpriteEnemy*)pSender;
	vEnemy2.eraseObject(spr2);
	this->removeChild(spr2);
}

void HelloWorld::update(float fDelta) {
	if (isPlayerDie)return;

	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);

	for (SpriteEnemy* enemy : vEnemy) {        //���� for��
		if (enemy->type == 2) {                //��
			if (!enemy->isAttack && enemy->getPositionY() < winSize.height * 3 / 4) {    //false�̰�, 2/3�����϶� ���� ����
				enemy->isAttack = true;
				attackEnemy_2(enemy->getPosition());
			}
		}
		else if (enemy->type == 3) {
			if (!enemy->isAttack &&                                            //false�϶� ���� �÷��̾��� �������� ����
				sPlayer->getPositionX() > enemy->getPositionX() - 20 &&        // ���� ���ݹ��� ��20
				sPlayer->getPositionX() < enemy->getPositionX() + 20) {
				enemy->isAttack = true;
				attackEnemy_2(enemy->getPosition());
			}
		}
		else if (enemy->type == 4)
		{
			if (!enemy->isAttack &&                                            //false�϶� ���� �÷��̾��� �������� ����
				sPlayer->getPositionX() > enemy->getPositionX() - 30 &&        // ���� ���ݹ��� ��20
				sPlayer->getPositionX() < enemy->getPositionX() + 30) {
				enemy->isAttack = true;
				attackEnemy_2(enemy->getPosition());
			}
		}

	}//for vEnemy
	for (SpriteEnemy* enemy2 : vEnemy2) {        //���� for��
		if (!enemy2->isAttack && enemy2->getPositionY() < winSize.height * 3 / 4) {    //false�̰�, 2/3�����϶� ���� ����
			enemy2->isAttack = true;
			attackEnemy_3(enemy2->getPosition());
		}
	}

#ifndef _TEST_DEBUG            //�׽�Ʈ ��������, �ش������� #define _TEST_DEBUG�� �ּ��ϸ� �������Ѵ�.
	//TODO: �׽�Ʈ ������
	intersectMissile();        //�÷��̾� �̻��ϰ� ���� �浹üũ
	intersectPlayer();        //�� �̻��ϰ� �÷��̾� �浹 üũ
	intersectEnemy();
#endif
}

void HelloWorld::attackEnemy_2(Vec2 pos) {
	SimpleAudioEngine::getInstance()->playEffect("enemy_shoot.wav");
	for (int i = 0; i < 5; i++) {                            //5���� �̻����� ���������� ����
		auto spr = Sprite::create("fire_1.png");
		spr->setPosition(pos);
		this->addChild(spr);
		vEMissile.pushBack(spr);                            //���Ϳ� ���� �̻��� ����

		spr->runAction(Sequence::create(
			MoveBy::create(3.0f, Vec2(-400 + i * 200, -winSize.height)),
			CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetAttack, this)),        //�̻��� ���� �Լ� ȣ��
			NULL));
	}
}

void HelloWorld::attackEnemy_3(Vec2 pos) {
	SimpleAudioEngine::getInstance()->playEffect("enemy_shoot.wav");
	for (int i = 0; i < 3; i++) {
		auto spr = Sprite::create("fire_1.png");
		spr->setPosition(pos + Vec2(0, -30 * i));
		this->addChild(spr);
		vEMissile.pushBack(spr);                            //���Ϳ� ���� �̻��� ����

		spr->runAction(Sequence::create(
			DelayTime::create(0.1f * i),
			MoveBy::create(1.5f, Vec2(0, -winSize.height)),
			CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetAttack, this)),        //�̻��� ���� �Լ� ȣ��
			NULL));
	}
}

void HelloWorld::attackEnemy_4(Vec2 pos) {
	SimpleAudioEngine::getInstance()->playEffect("enemy_shoot.wav");
	for (int i = 0; i < 10; i++) {                            //5���� �̻����� ���������� ����
		auto spr = Sprite::create("fire_1.png");
		spr->setPosition(pos + Vec2(0, -30 * i));
		this->addChild(spr);
		vEMissile.pushBack(spr);                            //���Ϳ� ���� �̻��� ����

		spr->runAction(Sequence::create(
			DelayTime::create(0.1f * i),
			MoveBy::create(1.5f, Vec2(0, -winSize.height)),
			CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetAttack, this)),        //�̻��� ���� �Լ� ȣ��
			NULL));
	}
}
void HelloWorld::resetAttack(Ref* pSender) {
	auto spr = (Sprite*)pSender;
	vEMissile.eraseObject(spr);        //���Ϳ��� �̻��� ����
	this->removeChild(spr);            //ȭ�鿡�� �̻��� ����


}
