#include "HelloWorldScene.h"
#include "EndScene.h"
/*
충돌체크
1. 미사일 vs 적 -> 적 죽음
2. 주인공 vs 적미사일 -> 플레이어 죽음
3. 주인공 vs 적 -> 플레이어 죽음
*/

void HelloWorld::intersectMissile() {        //플레이어 미사일 vs 적

	bool isCrash = false;        //미사일과 적이 만나는지 체크

	for (Sprite* missile : vMissile) {
		Rect rectMissile = missile->getBoundingBox();
		for (SpriteEnemy* enemy : vEnemy) {
			Rect rectEnemy = enemy->getBoundingBox();
			if (rectMissile.intersectsRect(rectEnemy)) {
				SimpleAudioEngine::getInstance()->playEffect("boom2.wav");        //적이 미사일에 맞을때 이펙트음
				enemy->hp = (enemy->hp) - damage;
				if (enemy->hp <= 0) {
					enemycount++;
					score += 10;
					__String *tempScore = __String::createWithFormat("%i", score);
					scorelabel->setString(tempScore->getCString());
					SimpleAudioEngine::getInstance()->playEffect("boom2.wav");    //적이 죽을때 이펙트음
					auto particle = ParticleSystemQuad::create("explosion.plist");
					this->addChild(particle, 20);
					int random = rand() % 100;
					if (random > 80)
					{
						item1 = Sprite::create("p.png");
						vItem.pushBack(item1);
						item1->setPosition(enemy->getPosition());
						this->addChild(item1, 21);
						CCActionInterval *move1 = CCMoveBy::create(8.0f, ccp(0, -winSize.height));
						//RemoveSelf::create();
						//item1->runAction(Sequence::create(
						//	RemoveSelf::create(),
						//	move1));
						item1->runAction(move1);
					}
					else if (random > 70)
					{
						item2 = Sprite::create("f.png");
						vItem.pushBack(item2);
						item2->setPosition(enemy->getPosition());
						this->addChild(item2, 22);
						CCActionInterval *move2 = CCMoveBy::create(8.0f, ccp(0, -winSize.height));
						//item2->runAction(Sequence::create(
						//	RemoveSelf::create(),
						//	move2));
						item2->runAction(move2);
					}
					else if (random > 60)
					{
						item3 = Sprite::create("l.png");
						vItem.pushBack(item3);
						item3->setPosition(enemy->getPosition());
						this->addChild(item3, 23);
						CCActionInterval *move3 = CCMoveBy::create(8.0f, ccp(0, -winSize.height));
						//item3->runAction(Sequence::create(
						//	RemoveSelf::create(),
						//	move3));
						item3->runAction(move3);
					}
					particle->setPosition(enemy->getPosition());
					particle->runAction(Sequence::create(        //파티클 생성후 2초후에 삭제
						DelayTime::create(2.0f),
						RemoveSelf::create(),
						NULL));
					vEnemy.eraseObject(enemy);    //백터에서 적 제거
					this->removeChild(enemy);    //적 스프라이트 제거
				}

				vMissile.eraseObject(missile);    //백터에서 미사일 제거
				this->removeChild(missile);        //미사일 스프라이트 제거
				isCrash = true;
				break;
			}
		}

		for (SpriteEnemy* enemy : vEnemy2) {
			Rect rectEnemy = enemy->getBoundingBox();
			if (rectMissile.intersectsRect(rectEnemy)) {
				SimpleAudioEngine::getInstance()->playEffect("boom2.wav");        //적이 미사일에 맞을때 이펙트음
				enemy->hp = (enemy->hp) - damage;
				if (enemy->hp <= 0) {
					enemycount++;
					score += 10;
					__String *tempScore = __String::createWithFormat("%i", score);
					scorelabel->setString(tempScore->getCString());
					SimpleAudioEngine::getInstance()->playEffect("boom2.wav");    //적이 죽을때 이펙트음
					auto particle = ParticleSystemQuad::create("explosion.plist");
					this->addChild(particle, 24);
					int random = rand() % 100;
					if (random > 90)
					{
						item1 = Sprite::create("p.png");
						vItem.pushBack(item1);
						item1->setPosition(enemy->getPosition());
						this->addChild(item1, 21);
						CCActionInterval *move = CCMoveBy::create(8.0f, ccp(0, -winSize.height));
						item1->runAction(move);
					}
					else if (random > 90)
					{
						item2 = Sprite::create("f.png");
						vItem.pushBack(item2);
						item2->setPosition(enemy->getPosition());
						this->addChild(item2, 22);
						CCActionInterval *move = CCMoveBy::create(8.0f, ccp(0, -winSize.height));
						item2->runAction(move);
					}
					else if (random > 90)
					{
						item3 = Sprite::create("l.png");
						vItem.pushBack(item3);
						item3->setPosition(enemy->getPosition());
						this->addChild(item3, 23);
						CCActionInterval *move = CCMoveBy::create(8.0f, ccp(0, -winSize.height));
						item3->runAction(move);
					}
					particle->setPosition(enemy->getPosition());
					particle->runAction(Sequence::create(        //파티클 생성후 2초후에 삭제
						DelayTime::create(2.0f),
						RemoveSelf::create(),
						NULL));
					vEnemy2.eraseObject(enemy);    //백터에서 적 제거
					this->removeChild(enemy);    //적 스프라이트 제거
				}

				vMissile.eraseObject(missile);    //백터에서 미사일 제거
				this->removeChild(missile);        //미사일 스프라이트 제거
				isCrash = true;
				break;
			}
		}

		for (MiddleBoss* enemy : vMidBoss) {
			Rect rectEnemy = enemy->getBoundingBox();
			if (rectMissile.intersectsRect(rectEnemy)) {
				SimpleAudioEngine::getInstance()->playEffect("boom2.wav");        //적이 미사일에 맞을때 이펙트음
				enemy->hp = (enemy->hp) - damage;
				score += 50;
				__String *tempScore = __String::createWithFormat("%i", score);
				scorelabel->setString(tempScore->getCString());
				if (enemy->hp <= 0) {
					midbosskill++;
					enemycount=0;
					score += 1000;
					__String *tempScore = __String::createWithFormat("%i", score);
					scorelabel->setString(tempScore->getCString());
					SimpleAudioEngine::getInstance()->playEffect("boom2.wav");    //적이 죽을때 이펙트음
					auto particle = ParticleSystemQuad::create("explosion.plist");
					this->addChild(particle, 24);

					particle->setPosition(enemy->getPosition());
					particle->runAction(Sequence::create(        //파티클 생성후 2초후에 삭제
						DelayTime::create(2.0f),
						RemoveSelf::create(),
						NULL));
					vMidBoss.eraseObject(enemy);    //백터에서 적 제거
					this->removeChild(enemy);    //적 스프라이트 제거
				}

				vMissile.eraseObject(missile);    //백터에서 미사일 제거
				this->removeChild(missile);        //미사일 스프라이트 제거
				isCrash = true;
				break;
			}
		}

		for (Boss* enemy : vBoss) {
			Rect rectEnemy = enemy->getBoundingBox();
			if (rectMissile.intersectsRect(rectEnemy)) {
				SimpleAudioEngine::getInstance()->playEffect("boom2.wav");        //적이 미사일에 맞을때 이펙트음
				enemy->hp = (enemy->hp) - damage;
				score += 100;
				__String *tempScore = __String::createWithFormat("%i", score);
				scorelabel->setString(tempScore->getCString());
				if (enemy->hp <= 0) {
					bosskill++;
					score += 3000;
					__String *tempScore = __String::createWithFormat("%i", score);
					scorelabel->setString(tempScore->getCString());
					SimpleAudioEngine::getInstance()->playEffect("boom2.wav");    //적이 죽을때 이펙트음
					auto particle = ParticleSystemQuad::create("explosion.plist");
					this->addChild(particle, 25);

					particle->setPosition(enemy->getPosition());
					particle->runAction(Sequence::create(        //파티클 생성후 2초후에 삭제
						DelayTime::create(2.0f),
						RemoveSelf::create(),
						NULL));
					vBoss.eraseObject(enemy);    //백터에서 적 제거
					this->removeChild(enemy);    //적 스프라이트 제거
					auto scene = TransitionFadeBL::create(1.0f, EndScene::createScene());
					Director::getInstance()->replaceScene(scene);
				}

				vMissile.eraseObject(missile);    //백터에서 미사일 제거
				this->removeChild(missile);        //미사일 스프라이트 제거
				isCrash = true;
				break;
			}
		}

		if (isCrash) {
			isCrash = false;
			break;
		}
	}
}

void HelloWorld::intersectPlayer() {
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	Rect rPlayer = Rect(sPlayer->getPositionX() - 10, sPlayer->getPositionY() - 20, 20, 40);    //주인공의 충돌박스 설정

	for (Sprite* emissile : vEMissile) {
		Rect rmissile = emissile->getBoundingBox();        //적 미사일 충돌박스
		if (rPlayer.intersectsRect(rmissile)) {
			vEMissile.eraseObject(emissile);
			this->removeChild(emissile);
			if (score >= 300) {
				score -= 300;
			} else {
				score = 0;
			}
			__String *tempScore = __String::createWithFormat("%i", score);
			scorelabel->setString(tempScore->getCString());
			resetPlayer();            //플레이어가 죽을때 호출
			return;
		}
	}

	for (Sprite* eitem : vItem) {
		Rect ritem = eitem->getBoundingBox();
		if (rPlayer.intersectsRect(ritem)) {
			SimpleAudioEngine::getInstance()->playEffect("ok2.wav");
			if (eitem == item1)
			{
				if (count == 0) {
					this->unschedule(schedule_selector(HelloWorld::setMissile));
					this->schedule(schedule_selector(HelloWorld::upGradeP2), 0.15f);
					damage = 2;
					count = 1;
				}
				else if (count == 1) {
					this->unschedule(schedule_selector(HelloWorld::upGradeP2));
					this->unschedule(schedule_selector(HelloWorld::upGradeF2));
					this->unschedule(schedule_selector(HelloWorld::upGradeL2));
					this->schedule(schedule_selector(HelloWorld::upGradeP3), 0.15f);
					damage = 3;
					count = 2;
				}
				else if (count == 2) {
					this->unschedule(schedule_selector(HelloWorld::upGradeP3));
					this->unschedule(schedule_selector(HelloWorld::upGradeF3));
					this->unschedule(schedule_selector(HelloWorld::upGradeL3));
					this->unschedule(schedule_selector(HelloWorld::upGradeF4));
					this->unschedule(schedule_selector(HelloWorld::upGradeL4));
					this->schedule(schedule_selector(HelloWorld::upGradeP4), 0.15f);
					damage = 4;
					count = 2;
					score += 100;
					__String *tempScore = __String::createWithFormat("%i", score);
					scorelabel->setString(tempScore->getCString());
				}
			}
			else if (eitem == item2)
			{
				if (count == 0) {
					this->unschedule(schedule_selector(HelloWorld::setMissile));
					this->schedule(schedule_selector(HelloWorld::upGradeF2), 0.15f);
					damage = 2;
					count = 1;
				}
				else if (count == 1) {
					this->unschedule(schedule_selector(HelloWorld::upGradeP2));
					this->unschedule(schedule_selector(HelloWorld::upGradeF2));
					this->unschedule(schedule_selector(HelloWorld::upGradeL2));
					this->schedule(schedule_selector(HelloWorld::upGradeF3), 0.15f);
					damage = 3;
					count = 2;
				}
				else if (count == 2) {
					this->unschedule(schedule_selector(HelloWorld::upGradeP3));
					this->unschedule(schedule_selector(HelloWorld::upGradeF3));
					this->unschedule(schedule_selector(HelloWorld::upGradeL3));
					this->unschedule(schedule_selector(HelloWorld::upGradeP4));
					this->unschedule(schedule_selector(HelloWorld::upGradeL4));
					this->schedule(schedule_selector(HelloWorld::upGradeF4), 0.15f);
					damage = 4;
					count = 2;
					score += 100;
					__String *tempScore = __String::createWithFormat("%i", score);
					scorelabel->setString(tempScore->getCString());
				}
			}
			else if (eitem == item3)
			{
				if (count == 0) {
					this->unschedule(schedule_selector(HelloWorld::setMissile));
					this->schedule(schedule_selector(HelloWorld::upGradeL2), 0.15f);
					damage = 2;
					count = 1;
				}
				else if (count == 1) {
					this->unschedule(schedule_selector(HelloWorld::upGradeP2));
					this->unschedule(schedule_selector(HelloWorld::upGradeF2));
					this->unschedule(schedule_selector(HelloWorld::upGradeL2));
					this->schedule(schedule_selector(HelloWorld::upGradeL3), 0.15f);
					damage = 3;
					count = 2;
				}
				else if (count == 2) {
					this->unschedule(schedule_selector(HelloWorld::upGradeP3));
					this->unschedule(schedule_selector(HelloWorld::upGradeF3));
					this->unschedule(schedule_selector(HelloWorld::upGradeL3));
					this->unschedule(schedule_selector(HelloWorld::upGradeP4));
					this->unschedule(schedule_selector(HelloWorld::upGradeF4));
					this->schedule(schedule_selector(HelloWorld::upGradeL4), 0.15f);
					damage = 4;
					count = 2;
					score += 100;
					__String *tempScore = __String::createWithFormat("%i", score);
					scorelabel->setString(tempScore->getCString());
				}
			}

			vItem.eraseObject(eitem);
			this->removeChild(eitem);
			return;
		}
	}
}


void HelloWorld::intersectEnemy() {        //플레이어와 적이 충돌
	auto sPlayer = (Sprite*)this->getChildByTag(TAG_SPRITE_PLAYER);
	Rect rPlayer = Rect(sPlayer->getPositionX() - 10, sPlayer->getPositionY() - 20, 20, 40);    //주인공의 충돌박스 설정

	for (Sprite* enemy : vEnemy) {
		Rect renemy = enemy->getBoundingBox();        //적 충돌박스
		if (rPlayer.intersectsRect(renemy)) {
			SimpleAudioEngine::getInstance()->playEffect("explosion.wav");

			auto particle = ParticleSystemQuad::create("explosion.plist");
			particle->setPosition(enemy->getPosition());
			this->addChild(particle);

			particle->runAction(Sequence::create(
				DelayTime::create(2.0f),
				RemoveSelf::create(),
				NULL));

			vEMissile.eraseObject(enemy);            //적의 미사일을 지운다.
			this->removeChild(enemy);

			resetPlayer();                            //플레이어가 죽을때 호출
			return;
		}
	}
	for (Sprite* enemy2 : vEnemy2) {
		Rect renemy = enemy2->getBoundingBox();        //적 충돌박스
		if (rPlayer.intersectsRect(renemy)) {
			SimpleAudioEngine::getInstance()->playEffect("explosion.wav");

			auto particle = ParticleSystemQuad::create("explosion.plist");
			particle->setPosition(enemy2->getPosition());
			this->addChild(particle);

			particle->runAction(Sequence::create(
				DelayTime::create(2.0f),
				RemoveSelf::create(),
				NULL));

			vEMissile.eraseObject(enemy2);            //적의 미사일을 지운다.
			this->removeChild(enemy2);

			resetPlayer();                            //플레이어가 죽을때 호출
			return;
		}
	}

	for (Sprite* enemy3 : vMidBoss) {
		Rect renemy = enemy3->getBoundingBox();        //적 충돌박스
		if (rPlayer.intersectsRect(renemy)) {
			SimpleAudioEngine::getInstance()->playEffect("explosion.wav");

			auto particle = ParticleSystemQuad::create("explosion.plist");
			particle->setPosition(enemy3->getPosition());
			this->addChild(particle);

			particle->runAction(Sequence::create(
				DelayTime::create(2.0f),
				RemoveSelf::create(),
				NULL));

			vEMissile.eraseObject(enemy3);            //적의 미사일을 지운다.
			this->removeChild(enemy3);
			resetPlayer();                            //플레이어가 죽을때 호출
			return;
		}
	}

	for (Sprite* enemy4 : vBoss) {
		Rect renemy = enemy4->getBoundingBox();        //적 충돌박스
		if (rPlayer.intersectsRect(renemy)) {
			SimpleAudioEngine::getInstance()->playEffect("explosion.wav");

			auto particle = ParticleSystemQuad::create("explosion.plist");
			particle->setPosition(enemy4->getPosition());
			this->addChild(particle);

			particle->runAction(Sequence::create(
				DelayTime::create(2.0f),
				RemoveSelf::create(),
				NULL));

			vEMissile.eraseObject(enemy4);            //적의 미사일을 지운다.
			this->removeChild(enemy4);
			resetPlayer();                            //플레이어가 죽을때 호출
			return;
		}
	}
}
