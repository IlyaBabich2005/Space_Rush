#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

namespace MATH
{
	static const float PI_rad = 3.14159265;
	static const int   PI_ang = 180;

	static class Math
	{
	public:
		static Vector2f GetRectangleCentre(RectangleShape rsSourceShape);
		static float	asRadians(float fDegrees);
		static float	asDegrees(float fRadians);
		static Vector2f ExpendVector(float fAngle);
		static float	NormoliizeVector(Vector2f vfSourceVector);
		static float	VecotrAnlge(Vector2f vfSourceVector);
		static float	dot(Vector2f vfFirstVector, Vector2f vfSecondVector);
		static float	AngleBetwenVectors(Vector2f vfFirstVector, Vector2f vfSecondVector);
	};
}

