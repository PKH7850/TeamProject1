#include "cocos2d.h"

using namespace cocos2d;

class Joystick : public Sprite
{

private:

	Vec2                mAxisWeight;
	Vec2                mHandlerOldPosition;
	bool                mIsClicked;
	float               mMinPadRadius;
	float               mMaxPadRadius;

	float               mAccumulatedTime;
	float               mIdleTime;
	GLubyte             mMaxOpacity;
	GLubyte             mCurrOpacity;

	Sprite*             mPad;
	Sprite*             mHandler;

	Joystick() = delete;
	Joystick(const Joystick&) = delete;
	Joystick& operator=(const Joystick&) = delete;

	Joystick(std::string padImagePath,
		std::string handlerImagePath,
		float minPadRadius,
		float maxPadRadius) :
		mAccumulatedTime(0.0f),
		mAxisWeight(Vec2::ZERO),
		mHandlerOldPosition(Vec2::ZERO),
		mIsClicked(false),
		mIdleTime(2.0f)
	{
		mPad = Sprite::create(padImagePath);
		mHandler = Sprite::create(handlerImagePath);

		minPadRadius == 0.0f ? (mMinPadRadius = mPad->getContentSize().width / 2.0f) : (mMinPadRadius = minPadRadius);
		mMaxPadRadius = maxPadRadius;

		mPad->setOpacity(0);
		mHandler->setOpacity(0);

		addChild(mPad, 0);
		addChild(mHandler, 1);

		mMaxOpacity = 100;
		mCurrOpacity = 0;

		this->scheduleUpdate();
	}

	bool IsTouchContainJoystickPad(const Vec2& pos);
	bool IsCurrentJoystick(const Vec2& pos);
	void UpdateAxisWeight(const Vec2& touchPos);
	void ClampHandlerPosition(const Vec2& handlePos);
	void update(float dt);

public:

	static Joystick* create(std::string padImagePath,
		std::string handlerImagePath,
		float minPadRadius = 0.0f,
		float maxPadRadius = 200.f);

	virtual ~Joystick()
	{}

	void Began(const Vec2& touchPos);
	void Moved(const Vec2& touchPos);
	void Ended(const Vec2& touchPos);

	Vec2 GetAxisWeight() const;
	Vec2 GetAxisDir() const;

	void SetMaxOpacity(GLubyte opacity);
	void SetIdleTime(float time);
	bool IsClicked() const { return mIsClicked; }


};