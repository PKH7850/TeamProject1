
#include "cocos2d.h"
using namespace cocos2d;

struct Circle{
	Vec2 mid;
	float rad;

	Circle()
	{}

	Circle(const Vec2& _mid, float _rad)
	{
		mid = _mid;
		rad = _rad;
	}

	Circle(const Circle& other)
	{
		mid = other.mid;
		rad = other.rad;
	}

	Circle& operator=(const Circle& other)
	{
		if (&other == this)
			return *this;
		this->mid = other.mid;
		this->rad = other.rad;
		return *this;
	}
};

struct Segment
{
	Vec2 start;
	Vec2 end;

	Segment(const Vec2& newStart, const Vec2& newEnd) :
		start(newStart),
		end(newEnd)
	{}

	Segment(const Segment& other) :
		start(other.start),
		end(other.end)
	{}

	Segment& operator=(const Segment& other)
	{
		if (&other == this)
			return *this;
		this->start = other.start;
		this->end = other.end;
		return *this;
	}
};

struct Ray
{
	Vec2 start;
	Vec2 dir;

	Ray(const Vec2& newStart, const Vec2& newDir) :
		start(newStart),
		dir(newDir)
	{}

	Ray(const Ray& other) :
		start(other.start),
		dir(other.dir)
	{}

	Ray& operator=(const Ray& other)
	{
		if (&other == this)
			return *this;
		this->start = other.start;
		this->dir = other.dir;
		return *this;
	}
};

bool GetCrossPoint(const Vec2& A1, const Vec2& A2, const Vec2& B1, const Vec2& B2, Vec2* out);
bool GetCrossPoint(const Vec2& A1, const Vec2& A2, const Vec2& B1, const Vec2& B2, Vec2* out, float& outT);
float CalAngleFromZeroPoint(const Vec2& p);
bool IsCollisionCircleXLine(const Vec2& startLine, const Vec2& endLine, const Circle& src);
Vec2 GetCrossCircleXLine(const Vec2& startLine, const Vec2& endLine, const Circle& src);
bool isCollisionCircleXCircle(const Circle& src, const Circle& dest);
Vec2 GetFrontCirclePostion(const Vec2& src, const Vec2& dir, float len);
bool IsCollisionEllipseXCircle(const Vec2& s1, const Vec2& s2, const Circle& dest, Vec2& out, Vec2& out2);
bool IsCollisionEllipseXCircle(const Vec2& s1, const Vec2& s2, const Circle& dest);
double RandFloat();
bool GetLineRayintersection(float p0_x, float p0_y, float p1_x, float p1_y,
	float p2_x, float p2_y, float p3_x, float p3_y, float *i_x, float *i_y);
Vec2 GetClosestRayIntersectPoint(std::list<std::pair<float, Vec2>> l);
float CalAngleBetweenTwoPoint(const Vec2& ptPoint2);






