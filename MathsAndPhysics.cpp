#include "MathsAndPhysics.h"

bool GetCrossPoint(const Vec2& A1, const Vec2& A2, const Vec2& B1, const Vec2& B2, Vec2* out)
{
	float t, s;
	float under = (B2.y - B1.y)*(A2.x - A1.x) - (B2.x - B1.x)*(A2.y - A1.y);

	if (under == 0) return false;

	float _t = (B2.x - B1.x)*(A1.y - B1.y) - (B2.y - B1.y)*(A1.x - B1.x);
	float _s = (A2.x - A1.x)*(A1.y - B1.y) - (A2.y - A1.y)*(A1.x - B1.x);

	t = _t / under;
	s = _s / under;

	if (t<0.0 || t>1.0 || s<0.0 || s>1.0) return false;
	if (_t == 0 && _s == 0) return false;

	out->x = A1.x + t * (A2.x - A1.x);
	out->y = A1.y + t * (A2.y - A1.y);

	return true;
}

bool GetCrossPoint(const Vec2& A1, const Vec2& A2, const Vec2& B1, const Vec2& B2, Vec2* out, float& outT)
{
	float t, s;
	float under = (B2.y - B1.y)*(A2.x - A1.x) - (B2.x - B1.x)*(A2.y - A1.y);

	if (under == 0) return false;

	float _t = (B2.x - B1.x)*(A1.y - B1.y) - (B2.y - B1.y)*(A1.x - B1.x);
	float _s = (A2.x - A1.x)*(A1.y - B1.y) - (A2.y - A1.y)*(A1.x - B1.x);

	t = _t / under;
	s = _s / under;

	if (t<0.0 || t>1.0 || s<0.0 || s>1.0) return false;
	if (_t == 0 && _s == 0) return false;

	out->x = A1.x + t * (A2.x - A1.x);
	out->y = A1.y + t * (A2.y - A1.y);
	outT = s;

	return true;
}

float CalAngleFromZeroPoint(const Vec2& p)
{
	float angle = 0.f;
	if (p.y < 0)
	{
		angle = acosf(p.dot(Vec2(1.f, 0.f)));
		angle = 6.283184 - angle;
	}
	else
	{
		angle = acosf(p.dot(Vec2(1.f, 0.f)));
	}

	return angle;
}

float CalAngleBetweenTwoPoint(const Vec2& ptPoint2)
{
	Vec2 ptRotated90Point1 = { 0, 0 };
	Vec2 ptPoint1(0.f, -1.f);

	ptRotated90Point1.x = ptPoint1.y;
	ptRotated90Point1.y = -ptPoint1.x;

	float fAng = acos((ptRotated90Point1.x * ptPoint2.x + ptRotated90Point1.y * ptPoint2.y) /
		(sqrt(ptRotated90Point1.x * ptRotated90Point1.x + ptRotated90Point1.y * ptRotated90Point1.y) *
		sqrt(ptPoint2.x * ptPoint2.x + ptPoint2.y * ptPoint2.y)))
		* 180 / 3.141592f;

	if (fAng > 90)
		return 360 - acos((ptPoint1.x * ptPoint2.x + ptPoint1.y * ptPoint2.y) /
		(sqrt(ptPoint1.x * ptPoint1.x + ptPoint1.y * ptPoint1.y) *
		sqrt(ptPoint2.x * ptPoint2.x + ptPoint2.y * ptPoint2.y)))
		* 180 / 3.141592f;

	else
		return acos((ptPoint1.x * ptPoint2.x + ptPoint1.y * ptPoint2.y) /
		(sqrt(ptPoint1.x * ptPoint1.x + ptPoint1.y * ptPoint1.y) *
		sqrt(ptPoint2.x * ptPoint2.x + ptPoint2.y * ptPoint2.y)))
		* 180 / 3.141592f;
}

bool IsCollisionCircleXLine(const Vec2& startLine, const Vec2& endLine, const Circle& src)
{
	Vec2 d = endLine - startLine;
	Vec2 f = startLine - src.mid;

	double a = d.getLengthSq();
	double b = 2 * f.dot(d);
	double c = f.getLengthSq() - (src.rad * src.rad);

	double discriminant = b * b - 4 * a*c;
	if (discriminant < 0)
	{
		return false;
	}
	else
	{
		discriminant = sqrt(discriminant);
		double t1 = (-b - discriminant) / (2 * a);
		double t2 = (-b + discriminant) / (2 * a);

		if (t1 >= 0 && t1 <= 1)
		{
			return true;
		}

		if (t2 >= 0 && t2 <= 1)
		{
			return true;
		}

		return false;
	}
}

Vec2 GetCrossCircleXLine(const Vec2& startLine, const Vec2& endLine, const Circle& src)
{
	Vec2 d = endLine - startLine;
	Vec2 f = startLine - src.mid;

	double a = d.getLengthSq();
	double b = 2 * f.dot(d);
	double c = f.getLengthSq() - (src.rad * src.rad);

	double discriminant = b * b - 4 * a*c;

	discriminant = sqrt(discriminant);
	double t1 = (-b - discriminant) / (2 * a);

	return Vec2(startLine.x + t1 * d.x, startLine.y + t1*d.y);
}

bool isCollisionCircleXCircle(const Circle& src, const Circle& dest)
{
	float len = (dest.mid - src.mid).getLengthSq();

	if ((dest.rad * dest.rad) + (src.rad * src.rad) + (2 * src.rad * dest.rad) < len)
		return false;
	return true;
}

Vec2 GetFrontCirclePostion(const Vec2& src, const Vec2& dir, float len)
{
	return Vec2(src.x + (dir.x * len), src.y + (dir.y * len));
}

bool IsCollisionEllipseXCircle(const Vec2& s1, const Vec2& s2, const Circle& dest, Vec2& out1, Vec2& out2)
{
	Vec2 p3, p4;
	p3 = GetCrossCircleXLine(s1, dest.mid, dest);
	p4 = GetCrossCircleXLine(s2, dest.mid, dest);

	out1 = p3;
	out2 = p4;

	if ((p3 - s1).length() + (p4 - s2).length() <= 380)
	{
		return true;
	}

	return false;
}

bool IsCollisionEllipseXCircle(const Vec2& s1, const Vec2& s2, const Circle& dest)
{
	Vec2 p3, p4;
	p3 = GetCrossCircleXLine(s1, dest.mid, dest);
	p4 = GetCrossCircleXLine(s2, dest.mid, dest);

	if ((p3 - s1).length() + (p4 - s2).length() <= 380)
	{
		return true;
	}

	return false;
}

double RandFloat()
{
	std::mt19937_64 mt;
	std::uniform_real_distribution<double> rd(0.0, 1.0);
	return rd(mt);
}

Vec2 GetClosestRayIntersectPoint(std::list<std::pair<float, Vec2>> l)
{
	if (l.empty()) return Vec2::ZERO;
	auto iter = std::min_element(l.begin(), l.end());
	return (*iter).second;
}