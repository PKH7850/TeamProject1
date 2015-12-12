#include "HelloWorldScene.h"

//test commit

void HelloWorld::setEnemy(float fDelta) {
	if (bosscount == 0){
		float randX = rand() % (1280 - TAG_PADDING_WIDTH * 2) + TAG_PADDING_WIDTH;        // ���� x��ǥ���� �¿� ȭ�鳡�� ������
		float rand2X = rand() % (1280 - TAG_PADDING_WIDTH * 2) + TAG_PADDING_WIDTH;
		// 50��ŭ���� �߻����� �ʵ��� ����
		auto sEnemy = SpriteEnemy::create();
		auto sEnemy2 = SpriteEnemy::create();

		sEnemy->setPosition(randX, winSize.height + 100);
		sEnemy->isAttack = false;
		sEnemy2->setPosition(rand2X, winSize.height + 100);
		sEnemy2->isAttack = false;

		this->addChild(sEnemy);
		this->addChild(sEnemy2);

		//int random = rand() % 100;        //100% Ȯ���� ����
		//int random2 = rand() % 100;
		float speed = 4.0f;                    //���� �������� �ӵ��� ����
		if (random < 60) {                //60���� Ȯ���� �߻�
			sEnemy->type = 1;
			sEnemy->hp = 1;
			speed = 5.0f;
		}
		else if (random < 85) {            //20���� Ȯ���� �߻�
			sEnemy->type = 2;
			sEnemy->hp = 1;
			sEnemy->setScaleX(1.7f);
			speed = 9.0f;
		}
		else if (random < 70)
		{                            //15���� Ȯ���� �߻�
			sEnemy->type = 3;
			sEnemy->hp = 1;
			sEnemy->setScaleY(1.5f);
			sEnemy->setScaleX(0.7f);
			speed = 7.0f;
		}
		if (random2 < 50)
		{
			sEnemy2->hp = 1;
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
			animation2->addSpriteFrameWithTexture(texture2, Rect(96 * i, 0, 50, 72));
		}
		auto animate2 = Animate::create(animation2);
		sEnemy2->runAction(RepeatForever::create(animate2));

		sEnemy2->runAction(Sequence::create(
			MoveBy::create(speed, Vec2(0, -winSize.height - 200)),
			CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetEnemy2, this)), NULL));

		if (enemycount >= 3 && midbosscount == 0)
		{
			midbosscount++;
			speed = 0;
			auto midBoss = MiddleBoss::create();
			midBoss->hp = 100;
			midBoss->setPosition(winSize.width / 2, winSize.height - 100);
			midBoss->isAttack = false;

			this->addChild(midBoss);

			vMidBoss.pushBack(midBoss);

			auto texture3 = Director::getInstance()->getTextureCache()->addImage("midboss.png");
			//////////////////////////������ ��������Ʈ �̹��� �غ�Ǹ� �ִϸ��̼� ����.

			auto animation3 = Animation::create();
			animation3->setDelayPerUnit(0.15f);
			for (int i = 0; i < 11; i++) {
				animation3->addSpriteFrameWithTexture(texture3, Rect(276 * i, 0, 276, 174));
			}
			auto animate3 = Animate::create(animation3);
			midBoss->runAction(RepeatForever::create(animate3));

			//sEnemy->runAction(Sequence::create(
			// MoveBy::create(speed, Vec2(0, -winSize.height - 200)),
			//CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetEnemy, this)), NULL));

		}

		if (enemycount >= 20 && bosscount == 0 && midbosskill == 1)
		{
			//SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
			//SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3", true);
			bosscount++;
			speed = 0;
			auto boss = Boss::create();
			boss->hp = 100;
			boss->setPosition(winSize.width / 2, winSize.height - 100);
			boss->isAttack = false;

			this->addChild(boss);

			vBoss.pushBack(boss);

			auto texture4 = Director::getInstance()->getTextureCache()->addImage("midboss.png");
			//////////////////////////������ ��������Ʈ �̹��� �غ�Ǹ� �ִϸ��̼� ����.

			auto animation4 = Animation::create();
			animation4->setDelayPerUnit(0.15f);
			for (int i = 0; i < 11; i++) {
				animation4->addSpriteFrameWithTexture(texture4, Rect(276 * i, 0, 276, 174));
			}
			auto animate4 = Animate::create(animation4);
			boss->runAction(RepeatForever::create(animate4));

			//sEnemy->runAction(Sequence::create(
			// MoveBy::create(speed, Vec2(0, -winSize.height - 200)),
			//CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetEnemy, this)), NULL));

		}
	}
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
		if (enemy->type == 1) {
			if (!enemy->isAttack && enemy->getPositionY() < winSize.height * 3 / 4) {
				enemy->isAttack = true;
				attackEnemy_1(enemy->getPosition());
			}
		}
		else if (enemy->type == 2) {                //��
			if (!enemy->isAttack && enemy->getPositionY() < winSize.height * 3 / 4) {    //false�̰�, 2/3�����϶� ���� ����
				enemy->isAttack = true;
				attackEnemy_2(enemy->getPosition());
			}
		}
		else if (enemy->type == 3) {
			if (!enemy->isAttack &&                                            //false�϶� ���� �÷��̾�� �������� ����
				sPlayer->getPositionX() > enemy->getPositionX() - 20 &&        // ���� ���ݹ��� ��20
				sPlayer->getPositionX() < enemy->getPositionX() + 20) {
				enemy->isAttack = true;
				attackEnemy_2(enemy->getPosition());
			}
		}
		else if (enemy->type == 4)
		{
			if (!enemy->isAttack &&                                            //false�϶� ���� �÷��̾�� �������� ����
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

	for (MiddleBoss* enemy3 : vMidBoss) {        //���� for��

		if (!enemy3->isAttack && enemy3->getPositionY() < winSize.height&&shotcount == 0)
		{
			shotcount++;
			auto act = DelayTime::create(3.0f);
			auto action1 = MoveTo::create(10.0f, Vec2(0, winSize.height - 100));
			auto action2 = MoveTo::create(20.0f, Vec2(winSize.width, winSize.height - 100));
			auto seq = Sequence::create(action1, action2, NULL);
			auto rep1 = RepeatForever::create(seq);
			enemy3->runAction(rep1);
			attackEnemy_5(enemy3->getPosition());
			enemy3->isAttack = true;
			midbossshotcount = 0;
		}

		if (enemy3->isAttack && sPlayer->getPositionX() > enemy3->getPositionX() - 30
			&& sPlayer->getPositionX() < enemy3->getPositionX() + 30 && midbossshotcount >0){
			attackEnemy_5(enemy3->getPosition());
		}
	}
	for (Boss* enemy4 : vBoss) {        //���� for��
		shotcount--;
		if (!enemy4->isAttack && enemy4->getPositionY() < winSize.height&&shotcount == 0)
		{
			shotcount++;
			attackEnemy_5(enemy4->getPosition());
			enemy4->isAttack = true;
		}

		if (enemy4->isAttack && sPlayer->getPositionX() > enemy4->getPositionX() - 30
			&& sPlayer->getPositionX() < enemy4->getPositionX() + 30){
			attackEnemy_5(enemy4->getPosition());
		}

		if (enemy4->isAttack && (sPlayer->getPositionX() < winSize.width && sPlayer->getPositionX() > (winSize.width / (3 / 4)))
			|| (sPlayer->getPositionX() >0 && sPlayer->getPositionX()<winSize.width / 8)){
			shotcount++;
			attackBoss1(enemy4->getPosition());
		}

	}

#ifndef _TEST_DEBUG            //�׽�Ʈ ������, �ش������� #define _TEST_DEBUG�� �ּ��ϸ� ������Ѵ�.
	//TODO: �׽�Ʈ �����
	intersectMissile();        //�÷��̾� �̻��ϰ� ���� �浹üũ
	intersectPlayer();        //�� �̻��ϰ� �÷��̾� �浹 üũ
	intersectEnemy();
#endif
}

void HelloWorld::attackEnemy_1(Vec2 pos) {
	SimpleAudioEngine::getInstance()->playEffect("enemy_shoot.wav");

	for (int i = 0; i < 3; i++) {
		auto spr = Sprite::create("mis.png");
		spr->setPosition(pos + Vec2(0, -30 * i));
		this->addChild(spr);
		vEMissile.pushBack(spr);                            //���Ϳ� ���� �̻��� ����

		spr->runAction(Sequence::create(
			DelayTime::create(0.1f * i),
			MoveBy::create(3.0f, Vec2(-5 * (pos - sPlayer->getPosition()))),
			CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetAttack, this)),        //�̻��� ���� �Լ� ȣ��
			NULL));
	}
}

void HelloWorld::attackEnemy_2(Vec2 pos) {
	SimpleAudioEngine::getInstance()->playEffect("enemy_shoot.wav");
	for (int i = 0; i < 5; i++) {                            //5���� �̻����� ��������� ���
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
	for (int i = 0; i < 10; i++) {                            //5���� �̻����� ��������� ���
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


void HelloWorld::attackEnemy_5(Vec2 pos) {
	SimpleAudioEngine::getInstance()->playEffect("enemy_shoot.wav");
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 5; i++) {                            //5���� �̻����� ��������� ���
			auto spr = Sprite::create("fire_1.png");
			spr->setPosition(pos + Vec2(0, -30 * i));
			this->addChild(spr);
			vEMissile.pushBack(spr);                            //���Ϳ� ���� �̻��� ����
			auto seq = Sequence::create(
				DelayTime::create(0.1f * i),
				MoveBy::create(1.5f, Vec2(-400 + i * 200, -winSize.height)),
				CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetAttack, this)),        //�̻��� ���� �Լ� ȣ��
				NULL);
			spr->runAction(seq);
		}

	}
	midbossshotcount = 0;
}

void HelloWorld::attackBoss1(Vec2 pos) {
	SimpleAudioEngine::getInstance()->playEffect("enemy_shoot.wav");
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 1; i++) {                            //5���� �̻����� ��������� ���
			auto spr = Sprite::create("fire_1.png");
			spr->setPosition(pos + Vec2(0, -30 * i));
			this->addChild(spr);
			vEMissile.pushBack(spr);                            //���Ϳ� ���� �̻��� ����
			auto seq = Sequence::create(
				DelayTime::create(1.0f * i),
				MoveBy::create(5.0f, Vec2(-5 * (pos - sPlayer->getPosition()))),
				CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetAttack, this)),        //�̻��� ���� �Լ� ȣ��
				NULL);
			spr->runAction(seq);
		}
	}
	while (clk + 1 * 1000 > clock());
}
void HelloWorld::attackBoss2(Vec2 pos) {
	SimpleAudioEngine::getInstance()->playEffect("enemy_shoot.wav");
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 10; i++) {                            //10���� �̻����� ��������� ���
			auto spr = Sprite::create("fire_1.png");
			spr->setPosition(pos + Vec2(0, -30 * i));
			this->addChild(spr);
			vEMissile.pushBack(spr);                            //���Ϳ� ���� �̻��� ����
			auto seq = Sequence::create(
				DelayTime::create(0.01f * i),
				MoveBy::create(1.5f, Vec2(-400 + i * 100, -winSize.height)),
				CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetAttack, this)),        //�̻��� ���� �Լ� ȣ��
				NULL);
			spr->runAction(seq);
		}
		for (int i = 0; i < 10; i++) {                            //10���� �̻����� ��������� ���
			auto spr = Sprite::create("fire_1.png");
			spr->setPosition(pos + Vec2(0, -30 * i));
			this->addChild(spr);
			vEMissile.pushBack(spr);                            //���Ϳ� ���� �̻��� ����
			auto seq = Sequence::create(
				DelayTime::create(0.01f * i),
				MoveBy::create(1.5f, Vec2(400 + i * -100, winSize.height)),
				CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetAttack, this)),        //�̻��� ���� �Լ� ȣ��
				NULL);
			spr->runAction(seq);
		}
	}

}

void HelloWorld::resetAttack(Ref* pSender) {
	auto spr = (Sprite*)pSender;
	vEMissile.eraseObject(spr);        //���Ϳ��� �̻��� ����
	this->removeChild(spr);            //ȭ�鿡�� �̻��� ����
}

