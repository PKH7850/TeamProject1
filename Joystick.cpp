#include "Joystick.h"
#include "MathsAndPhysics.h"

Joystick* Joystick::create(std::string padImagePath, std::string handlerImagePath, float minPadRadius, float maxPadRadius)
{
	Joystick *pRet = new(std::nothrow) Joystick(padImagePath, handlerImagePath, minPadRadius, maxPadRadius);
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

void Joystick::Began(const Vec2& touchPos)
{
	if (IsTouchContainJoystickPad(touchPos))
	{
		mIsClicked = true;
		ClampHandlerPosition(touchPos - this->getPosition());
		UpdateAxisWeight(touchPos);
		mAccumulatedTime = 0.0f;
	}
}

void Joystick::Moved(const Vec2& touchPos)
{
	if (IsCurrentJoystick(touchPos) && mIsClicked == true)
	{
		ClampHandlerPosition(touchPos - this->getPosition());
		UpdateAxisWeight(touchPos);
		mAccumulatedTime = 0.0f;
	}
}

void Joystick::Ended(const Vec2& touchPos)
{
	if (IsCurrentJoystick(touchPos))
	{
		mHandler->setPosition(Vec2::ZERO);
		mHandlerOldPosition = Vec2::ZERO;
		UpdateAxisWeight(touchPos);
		mIsClicked = false;
	}
}

void Joystick::ClampHandlerPosition(const Vec2& handlePos)
{
	if (mMinPadRadius * mMinPadRadius > handlePos.getLengthSq())
	{
		mHandler->setPosition(handlePos);
	}
	else
	{
		Vec2 dir = handlePos.getNormalized();
		Vec2 col = GetCrossCircleXLine(Vec2::ZERO, dir * mMaxPadRadius, Circle(Vec2::ZERO, mMinPadRadius));
		mHandler->setPosition(-col);
	}

	mHandlerOldPosition = handlePos;
}

bool Joystick::IsCurrentJoystick(const Vec2& pos)
{
	if (isCollisionCircleXCircle(Circle(mHandlerOldPosition + this->getPosition(), 60), Circle(pos, 60)))
	{
		return true;
	}
	return false;
}

bool Joystick::IsTouchContainJoystickPad(const Vec2& pos)
{
	if (isCollisionCircleXCircle(Circle(pos, 15), Circle(this->getPosition(), mMaxPadRadius)))
	{
		return true;
	}
	return false;
}


void Joystick::UpdateAxisWeight(const Vec2& touchPos)
{
	mAxisWeight.x = clampf((mHandler->getPosition().x / mMinPadRadius), -1.0f, 1.0f);
	mAxisWeight.y = clampf((mHandler->getPosition().y / mMinPadRadius), -1.0f, 1.0f);
}

Vec2 Joystick::GetAxisWeight() const
{
	return mAxisWeight;
}

Vec2 Joystick::GetAxisDir() const
{
	return mAxisWeight.getNormalized();
}

void Joystick::update(float dt)
{
	if (mAccumulatedTime < mIdleTime)
	{
		mAccumulatedTime += dt;
		if (mCurrOpacity != mMaxOpacity)
		{
			mPad->setOpacity(mCurrOpacity + 1);
			mHandler->setOpacity(mCurrOpacity + 1);
			mCurrOpacity++;
		}
	}
	else
	{
		if (mCurrOpacity != 0)
		{
			mPad->setOpacity(mCurrOpacity - 1);
			mHandler->setOpacity(mCurrOpacity - 1);
			mCurrOpacity--;
		}
	}

}

void Joystick::SetMaxOpacity(GLubyte opacity)
{
	mMaxOpacity = opacity;
}

void Joystick::SetIdleTime(float time)
{
	mIdleTime = time;
}