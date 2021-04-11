#include "..\Header Files\Vector3f.h"

using namespace Candlelight::Maths;

Vector3f& Vector3f::operator+=(const Vector3f& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

Vector3f& Vector3f::operator-=(const Vector3f& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

Vector3f& Vector3f::operator*=(const float& rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

Vector3f& Vector3f::operator/=(const float& rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}
