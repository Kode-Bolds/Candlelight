#pragma once
#include <cmath>

namespace Candlelight
{
	namespace Maths
	{
		struct Vector3f
		{
			float x;
			float y;
			float z;

			Vector3f& operator+=(const Vector3f& rhs);
			Vector3f& operator-=(const Vector3f& rhs);
			Vector3f& operator*=(const float& rhs);
			Vector3f& operator/= (const float& rhs);
		};

		inline Vector3f operator+(Vector3f lhs, const Vector3f& rhs) { lhs += rhs; return lhs; }
		inline Vector3f operator-(Vector3f lhs, const Vector3f& rhs) { lhs -= rhs;	return lhs; }
		inline Vector3f operator*(Vector3f lhs, const float& rhs) { lhs *= rhs;	return lhs; }
		inline Vector3f operator/(Vector3f lhs, const float& rhs) { lhs /= rhs; return lhs; }

		static float SqrMagnitude(const Vector3f& v)
		{
			return (v.x * v.x) + (v.y * v.y) + (v.z * v.z);
		}

		static float Magnitude(const Vector3f& v)
		{
			return sqrt(SqrMagnitude(v));
		}

		static Vector3f Clamp(const Vector3f& v, float max)
		{
			float magnitude = Magnitude(v);
			if (magnitude > max)
			{
				return v * (max / magnitude);
			}
			return v;
		}

		static Vector3f Normalise(const Vector3f& v)
		{
			return Clamp(v, 1.0f);
		}

		static float Dot(const Vector3f& a, const Vector3f& b)
		{
			return (a.x * a.x) + (a.y * a.y) + (a.z * a.z);
		}

		static Vector3f Cross(const Vector3f& a, const Vector3f& b)
		{
			return Vector3f
			{
				(a.y * b.z) - (a.z * b.y),
				(a.z * b.x) - (a.x * b.z),
				(a.x * b.y) - (a.y * b.x)
			};
		}
	}
}