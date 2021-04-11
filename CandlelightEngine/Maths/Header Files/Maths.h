#pragma once
#include "Vector3f.h"

namespace Candlelight
{
	namespace Maths
	{
		const float PI = 3.141592653589793238463f;

		static float DegreesToRadians(const float& degrees)
		{
			return (degrees * PI) / 180.0f;
		}

		static float RadiansToDegrees(const float& radians)
		{
			return (radians * 180.0f) / PI;
		}
	}
}