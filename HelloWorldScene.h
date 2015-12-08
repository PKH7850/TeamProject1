#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"            //사운드 추가를 위한 헤더
#include <ctime>
#include <time.h>

USING_NS_CC;
using namespace CocosDenshion;            //사운드 추가를 위한 namespace 선언

//#define _TEST_DEBUG                //테스트 디버깅용

#define TAG_PADDING_WIDTH            50

#define TAG_LABEL_TITLE                0
#define TAG_SPRITE_PLAYER            1
#define TAG_ACTION_PALYER_MOVE        2
#define    TAG_LABEL_GAMEOVER_1        3
#define    TAG_LABEL_GAMEOVER_2        4
#define TAG_LABEL_SCORE              5
#include "cocos2d.h"

using namespace cocos2d;
class Boss : public Sprite
{
public:
	CREATE_FUNC(Boss);
	int hp;
	bool isAttack;
};

class MiddleBoss : public Sprite
{
public:
	CREATE_FUNC(MiddleBoss);
	int hp;
	bool isAttack;
};

class SpriteEnemy : public Sprite        //적의 hp와 종류를 설정하기위한 클래스 선언
{
public:
	CREATE_FUNC(SpriteEnemy);
	int type;
	int hp;
	bool isAttack;            //false 일때만 공격
};


class HelloWorld : public cocos2d::Layer
{
public:
	CCSprite *sPlayer;
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(HelloWorld);
	Sprite* item1;
	Sprite* item2;
	Sprite* item3;
	int score = 0;
	char szTEMP[100];

	time_t start_time, end_time;
	clock_t clk;
	float missiletime = 0;

	int enemycount = 0;
	int midbosscount = 0;
	int midbosskill = 0;
	int midbossshotcount = 0;
	int bosscount = 0;
	int bosskill = 0;
	int bossattack1 = 0;
	int bossattack2 = 0;
	int random = rand() % 100;        //100% 확률을 저장
	int random2 = rand() % 100;

	int damage = 1;
	int count = 0;
	int shotcount = 0;
	EventListenerTouchOneByOne* listener;
	Size winSize;
	bool isTitle;            //타이틀이 생성되면 클릭 불가(true)
	bool isPlayerDie;        //플레이어가 죽으면 true
	bool isGameover;        //게임오버가 되면 true

	void initBG();            //게임 배경 생성
	void initTitle();        //게임 타이틀 생성
	void setTitle();        //게임 타이틀 

	void initGameData();    //게임 데이터 초기화
	bool onTouchBegan(Touch *touch, Event *unused_event);    //터치한 위치로 플레이어 이동

	void initPlayer();        //플레이어 그리기

	void setItem(float fDelta);
	void resetItem(Ref *pSender);
	Vector<Sprite*> vItem;

	void setMissile(float fDelta);        //플레이어 이미지 앞에 미사일 발사 구현
	void resetMissile(Ref* pSender);    //미사일 제거 구현
	Vector<Sprite*> vMissile;            //미사일 저장할 백터

	void upGradeP2(float fDelta);
	void upGradeP3(float fDelta);
	void upGradeP4(float fDelta);

	void upGradeF2(float fDelta);
	void upGradeF3(float fDelta);
	void upGradeF4(float fDelta);

	void upGradeL2(float fDelta);
	void upGradeL3(float fDelta);
	void upGradeL4(float fDelta);

	void upGradeSub(float fDelta);

	void setEnemy(float fDelta);        //적 구현
	void resetEnemy(Ref* pSender);        //적 제거 구현
	void resetEnemy2(Ref* pSender);

	Vector<SpriteEnemy*> vEnemy;        //적의 hp, type등을 함께 저장할 백터
	Vector<SpriteEnemy*> vEnemy2;
	Vector<MiddleBoss*> vMidBoss;
	Vector<Boss*> vBoss;

	void update(float fDelta);            //적의 type 미사일 구현
	Vector<Sprite*> vEMissile;            //적의 미사일을 백터에 저장

	void attackEnemy_1(Vec2 pos);		 //type 1의 적 공격
	void attackEnemy_2(Vec2 pos);        //type 2의 적 공격
	void attackEnemy_3(Vec2 pos);        //type 3의 적 공격
	void attackEnemy_4(Vec2 pos);
	void attackEnemy_5(Vec2 pos);
	void attackBoss1(Vec2 pos);
	void attackBoss2(Vec2 pos);
	void resetAttack(Ref* pSender);        //적의 공격 제거

	void intersectMissile();            //적과 플레이어미사일 충돌체크
	void intersectPlayer();                //플레이어와 적미사일 충돌체크
	void resetPlayer();                    //플레이어 죽음
	void intersectEnemy();                //적과 플레이어 충돌체크

	void initGameover();                //게임오버 타이틀 생성
	void setGameover();                    //게임오버 타이틀 작동 구현
	void resetGameover();                //게임오버 타이틀 리셋

	virtual void onEnter();
	virtual void onExit();
	void reZorder(cocos2d::Sprite* pSender);
	void goBack();

	void scoreboard(int enemycount);
	void setScore();

	void setMissileInterface();
};

#endif // __HELLOWORLD_SCENE_H__