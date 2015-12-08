#include "HelloWorldScene.h"

//test commit

void HelloWorld::setEnemy(float fDelta) {
	if (bosscount == 0){
		float randX = rand() % (1280 - TAG_PADDING_WIDTH * 2) + TAG_PADDING_WIDTH;        // 적의 x좌표값을 좌우 화면끝의 간격을
		float rand2X = rand() % (1280 - TAG_PADDING_WIDTH * 2) + TAG_PADDING_WIDTH;
		// 50만큼씩은 발생하지 않도록 설정
		auto sEnemy = SpriteEnemy::create();
		auto sEnemy2 = SpriteEnemy::create();

		sEnemy->setPosition(randX, winSize.height + 100);
		sEnemy->isAttack = false;
		sEnemy2->setPosition(rand2X, winSize.height + 100);
		sEnemy2->isAttack = false;

		this->addChild(sEnemy);
		this->addChild(sEnemy2);

		//int random = rand() % 100;        //100% 확률을 저장
		//int random2 = rand() % 100;
		float speed = 4.0f;                    //적이 내려오는 속도를 저장
		if (random < 60) {                //60프로 확률로 발생
			sEnemy->type = 1;
			sEnemy->hp = 1;
			speed = 5.0f;
		}
		else if (random < 85) {            //20프로 확률로 발생
			sEnemy->type = 2;
			sEnemy->hp = 1;
			sEnemy->setScaleX(1.7f);
			speed = 9.0f;
		}
		else if (random < 70)
		{                            //15프로 확률로 발생
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
			//////////////////////////이쪽은 스프라이트 이미지 준비되면 애니메이션 적용.

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

		if (enemycount >= 20 && bosscount == 0 && midbosskill==1)
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
			//////////////////////////이쪽은 스프라이트 이미지 준비되면 애니메이션 적용.

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

	for (SpriteEnemy* enemy : vEnemy) {        //백터 for문
		if (enemy->type == 1) {
			if (!enemy->isAttack && enemy->getPositionY() < winSize.height * 3 / 4) {
			   enemy->isAttack = true;
			   attackEnemy_1(enemy->getPosition());
			}
		}
		else if (enemy->type == 2) {                //적
		  if (!enemy->isAttack && enemy->getPositionY() < winSize.height * 3 / 4) {    //false이고, 2/3지점일때 적이 공격
		     enemy->isAttack = true;
		     attackEnemy_2(enemy->getPosition());
		  }
		}
		else if (enemy->type == 3) {
		  if (!enemy->isAttack &&                                            //false일때 적이 플레이어와 만났을때 공격
		     sPlayer->getPositionX() > enemy->getPositionX() - 20 &&        // 적의 공격범위 ±20
		     sPlayer->getPositionX() < enemy->getPositionX() + 20) {
		     enemy->isAttack = true;
		     attackEnemy_2(enemy->getPosition());
		  }
		}
		else if (enemy->type == 4)
		{
			if (!enemy->isAttack &&                                            //false일때 적이 플레이어와 만났을때 공격
				sPlayer->getPositionX() > enemy->getPositionX() - 30 &&        // 적의 공격범위 ±20
				sPlayer->getPositionX() < enemy->getPositionX() + 30) {
				enemy->isAttack = true;
				 attackEnemy_2(enemy->getPosition());
			}
		}
	}//for vEnemy
	for (SpriteEnemy* enemy2 : vEnemy2) {        //백터 for문
	   if (!enemy2->isAttack && enemy2->getPositionY() < winSize.height * 3 / 4) {    //false이고, 2/3지점일때 적이 공격
	      enemy2->isAttack = true;
	      attackEnemy_3(enemy2->getPosition());
	   }
	}

	for (MiddleBoss* enemy3 : vMidBoss) {        //백터 for문
	
		if (!enemy3->isAttack && enemy3->getPositionY() < winSize.height&&shotcount==0)
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
			midbossshotcount=0;
		}

		if (enemy3->isAttack && sPlayer->getPositionX() > enemy3->getPositionX() - 30 
			&&sPlayer->getPositionX() < enemy3->getPositionX() + 30 && midbossshotcount >0){
			attackEnemy_5(enemy3->getPosition());
		}
	}
	for (Boss* enemy4 : vBoss) {        //백터 for문
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

		if (enemy4->isAttack && (sPlayer->getPositionX() < winSize.width && sPlayer->getPositionX() > (winSize.width/(3/4)))
			||(sPlayer->getPositionX() >0&&sPlayer->getPositionX()<winSize.width/8)){
			shotcount++;
			attackBoss1(enemy4->getPosition());
		}
		
	}
	
#ifndef _TEST_DEBUG            //테스트 디버깅용, 해더파일의 #define _TEST_DEBUG를 주석하면 디버깅한다.
   //TODO: 테스트 디버깅
   intersectMissile();        //플레이어 미사일과 적의 충돌체크
   intersectPlayer();        //적 미사일과 플레이어 충돌 체크
   intersectEnemy();
#endif
}

void HelloWorld::attackEnemy_1(Vec2 pos) {
	SimpleAudioEngine::getInstance()->playEffect("enemy_shoot.wav");

	for (int i = 0; i < 3; i++) {
		auto spr = Sprite::create("mis.png");
		spr->setPosition(pos + Vec2(0, -30 * i));
		this->addChild(spr);
		vEMissile.pushBack(spr);                            //백터에 적의 미사일 저장

		spr->runAction(Sequence::create(
			DelayTime::create(0.1f * i),
			MoveBy::create(3.0f, Vec2(-5 * (pos - sPlayer->getPosition()))),
			CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetAttack, this)),        //미사일 제거 함수 호출
			NULL));
	}
}

void HelloWorld::attackEnemy_2(Vec2 pos) {
   SimpleAudioEngine::getInstance()->playEffect("enemy_shoot.wav");
   for (int i = 0; i < 5; i++) {                            //5개의 미사일을 방사형으로 쏜다
      auto spr = Sprite::create("fire_1.png");
      spr->setPosition(pos);
      this->addChild(spr);
      vEMissile.pushBack(spr);                            //백터에 적의 미사일 저장

      spr->runAction(Sequence::create(
         MoveBy::create(3.0f, Vec2(-400 + i * 200, -winSize.height)),
         CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetAttack, this)),        //미사일 제거 함수 호출
         NULL));
   }
}

void HelloWorld::attackEnemy_3(Vec2 pos) {
   SimpleAudioEngine::getInstance()->playEffect("enemy_shoot.wav");
   for (int i = 0; i < 3; i++) {                            
      auto spr = Sprite::create("fire_1.png");
      spr->setPosition(pos + Vec2(0, -30 * i));
      this->addChild(spr);
      vEMissile.pushBack(spr);                            //백터에 적의 미사일 저장

      spr->runAction(Sequence::create(
         DelayTime::create(0.1f * i),
         MoveBy::create(1.5f, Vec2(0, -winSize.height)),
         CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetAttack, this)),        //미사일 제거 함수 호출
         NULL));
   }
}

void HelloWorld::attackEnemy_4(Vec2 pos) {
   SimpleAudioEngine::getInstance()->playEffect("enemy_shoot.wav");
   for (int i = 0; i < 10; i++) {                            //5개의 미사일을 방사형으로 쏜다
      auto spr = Sprite::create("fire_1.png");
      spr->setPosition(pos + Vec2(0, -30 * i));
      this->addChild(spr);
      vEMissile.pushBack(spr);                            //백터에 적의 미사일 저장

      spr->runAction(Sequence::create(
         DelayTime::create(0.1f * i),
         MoveBy::create(1.5f, Vec2(0, -winSize.height)),
         CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetAttack, this)),        //미사일 제거 함수 호출
         NULL));
   }
}


void HelloWorld::attackEnemy_5(Vec2 pos) {
	SimpleAudioEngine::getInstance()->playEffect("enemy_shoot.wav");
	for (int j = 0; j < 3;j++)
	{ 
		for (int i = 0; i < 5; i++) {                            //5개의 미사일을 방사형으로 쏜다
			auto spr = Sprite::create("fire_1.png");
			spr->setPosition(pos + Vec2(0, -30 * i));
			this->addChild(spr);
			vEMissile.pushBack(spr);                            //백터에 적의 미사일 저장
			auto seq = Sequence::create(
				DelayTime::create(0.1f * i),
				MoveBy::create(1.5f, Vec2(-400 + i * 200, -winSize.height)),
				CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetAttack, this)),        //미사일 제거 함수 호출
				NULL);
			spr->runAction(seq);
		}
		
	}
	midbossshotcount=0;
}

void HelloWorld::attackBoss1(Vec2 pos) {
	SimpleAudioEngine::getInstance()->playEffect("enemy_shoot.wav");
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 1; i++) {                            //5개의 미사일을 방사형으로 쏜다
			auto spr = Sprite::create("fire_1.png");
			spr->setPosition(pos + Vec2(0, -30 * i));
			this->addChild(spr);
			vEMissile.pushBack(spr);                            //백터에 적의 미사일 저장
			auto seq = Sequence::create(
				DelayTime::create(1.0f * i),
				MoveBy::create(5.0f, Vec2(-5 * (pos - sPlayer->getPosition()))),
				CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetAttack, this)),        //미사일 제거 함수 호출
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
		for (int i = 0; i < 10; i++) {                            //10개의 미사일을 방사형으로 쏜다
			auto spr = Sprite::create("fire_1.png");
			spr->setPosition(pos + Vec2(0, -30 * i));
			this->addChild(spr);
			vEMissile.pushBack(spr);                            //백터에 적의 미사일 저장
			auto seq = Sequence::create(
				DelayTime::create(0.01f * i),
				MoveBy::create(1.5f, Vec2(-400 + i * 100, -winSize.height)),
				CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetAttack, this)),        //미사일 제거 함수 호출
				NULL);
			spr->runAction(seq);
		}
		for (int i = 0; i < 10; i++) {                            //10개의 미사일을 방사형으로 쏜다
			auto spr = Sprite::create("fire_1.png");
			spr->setPosition(pos + Vec2(0, -30 * i));
			this->addChild(spr);
			vEMissile.pushBack(spr);                            //백터에 적의 미사일 저장
			auto seq = Sequence::create(
				DelayTime::create(0.01f * i),
				MoveBy::create(1.5f, Vec2(400 + i * -100, winSize.height)),
				CallFuncN::create(CC_CALLBACK_1(HelloWorld::resetAttack, this)),        //미사일 제거 함수 호출
				NULL);
			spr->runAction(seq);
		}
	}

}

void HelloWorld::resetAttack(Ref* pSender) {
   auto spr = (Sprite*)pSender;
   vEMissile.eraseObject(spr);        //백터에서 미사일 제거
   this->removeChild(spr);            //화면에서 미사일 제거
}

