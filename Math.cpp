#include "Math.h"

Vector2f Math::GetRectangleCentre(RectangleShape rsSourceShape)

{
	return { rsSourceShape.getSize().x / 2, rsSourceShape.getSize().y / 2 };
}

float Math::asRadians(float fDegrees)
{
	return 3.14159265 / 180 * fDegrees;
}

float Math::asDegrees(float fRadians)
{
	return fRadians * 180 / 3.14159265;
}

Vector2f Math::ExpendVector(float fAngle)
{
	Vector2f vfVector;

	vfVector.x = cos(asRadians(fAngle));
	vfVector.y = sin(asRadians(fAngle));

	return vfVector;
}

float Math::NormoliizeVector(Vector2f vfSourceVector)
{
	return sqrt(pow(vfSourceVector.x, 2) + pow(vfSourceVector.y, 2));
}

float Math::GetAngle(Vector2f vfSourceVector)
{
	float fLength = NormoliizeVector(vfSourceVector);

	return asDegrees(asin(vfSourceVector.y / fLength));
}
