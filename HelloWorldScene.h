#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"            //���� �߰��� ���� ���
#include "Joystick.h"
#include <ctime>

USING_NS_CC;
using namespace CocosDenshion;            //���� �߰��� ���� namespace ����

//#define _TEST_DEBUG                //�׽�Ʈ ������

#define TAG_PADDING_WIDTH            50

#define TAG_LABEL_TITLE                0
#define TAG_SPRITE_PLAYER            1
#define TAG_ACTION_PALYER_MOVE        2
#define    TAG_LABEL_GAMEOVER_1        3
#define    TAG_LABEL_GAMEOVER_2        4

#include "cocos2d.h"

using namespace cocos2d;

class SpriteEnemy : public Sprite        //���� hp�� ������ �����ϱ����� Ŭ���� ����
{
public:
	CREATE_FUNC(SpriteEnemy);
	int type;
	int hp;
	bool isAttack;            //false �϶��� ����
};

class HelloWorld : public cocos2d::Layer
{
public:
	Joystick* mLeftJoystick;
	CCSprite *sPlayer;
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(HelloWorld);
	Sprite* item1;
	Sprite* item2;
	Sprite* item3;

	int damage = 1;
	int count = 0;

	EventListenerTouchOneByOne* listener;
	Size winSize;
	bool isTitle;            //Ÿ��Ʋ�� �����Ǹ� Ŭ�� �Ұ�(true)
	bool isPlayerDie;        //�÷��̾ ������ true
	bool isGameover;        //���ӿ����� �Ǹ� true

	void initBG();            //���� ��� ����
	void initTitle();        //���� Ÿ��Ʋ ����
	void setTitle();        //���� Ÿ��Ʋ 

	void initGameData();    //���� ������ �ʱ�ȭ
	bool onTouchBegan(Touch *touch, Event *unused_event);    //��ġ�� ��ġ�� �÷��̾� �̵�

	void initPlayer();        //�÷��̾� �׸���

	void setItem(float fDelta);
	void resetItem(Ref *pSender);
	Vector<Sprite*> vItem;

	void setMissile(float fDelta);        //�÷��̾� �̹��� �տ� �̻��� �߻� ����
	void resetMissile(Ref* pSender);    //�̻��� ���� ����
	Vector<Sprite*> vMissile;            //�̻��� ������ ����

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

	void setEnemy(float fDelta);        //�� ����
	void resetEnemy(Ref* pSender);        //�� ���� ����
	void resetEnemy2(Ref* pSender);
	Vector<SpriteEnemy*> vEnemy;        //���� hp, type���� �Բ� ������ ����
	Vector<SpriteEnemy*> vEnemy2;
	void update(float fDelta);            //���� type �̻��� ����
	Vector<Sprite*> vEMissile;            //���� �̻����� ���Ϳ� ����

	void attackEnemy_2(Vec2 pos);        //type 2�� �� ����
	void attackEnemy_3(Vec2 pos);        //type 3�� �� ����
	void attackEnemy_4(Vec2 pos);
	void resetAttack(Ref* pSender);        //���� ���� ����

	void intersectMissile();            //���� �÷��̾�̻��� �浹üũ
	void intersectPlayer();                //�÷��̾�� ���̻��� �浹üũ
	void resetPlayer();                    //�÷��̾� ����
	void intersectEnemy();                //���� �÷��̾� �浹üũ

	void initGameover();                //���ӿ��� Ÿ��Ʋ ����
	void setGameover();                    //���ӿ��� Ÿ��Ʋ �۵� ����
	void resetGameover();                //���ӿ��� Ÿ��Ʋ ����

	virtual void onEnter();
	virtual void onExit();
	void reZorder(cocos2d::Sprite* pSender);
};

#endif // __HELLOWORLD_SCENE_H__