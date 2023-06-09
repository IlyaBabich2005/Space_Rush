#include "Math.h"

using namespace MATH;

Vector2f Math::GetRectangleCentre(RectangleShape rsSourceShape)
{
	return { rsSourceShape.getSize().x / 2, rsSourceShape.getSize().y / 2 };
}

float Math::asRadians(float fDegrees)
{
	return PI_rad / PI_ang * fDegrees;
}

float Math::asDegrees(float fRadians)
{
	return fRadians * PI_ang / PI_rad;
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

float Math::VecotrAnlge(Vector2f vfSourceVector)
{
	if (float VECTORS_LENGTH = NormoliizeVector(vfSourceVector))
		return asDegrees(asin(vfSourceVector.y / VECTORS_LENGTH));
}

float MATH::Math::dot(Vector2f vfFirstVector, Vector2f vfSecondVector)
{
	return vfFirstVector.x * vfSecondVector.x + vfFirstVector.y * vfSecondVector.y;
}

float MATH::Math::AngleBetwenVectors(Vector2f vfFirstVector, Vector2f vfSecondVector)
{
	const float FIRST_VECTOR_LENGTH = NormoliizeVector(vfFirstVector);
	const float SECOND_VECTOR_LENGTH = NormoliizeVector(vfSecondVector);

	if (FIRST_VECTOR_LENGTH && SECOND_VECTOR_LENGTH)
		return asDegrees(acos(dot(vfFirstVector, vfSecondVector) / FIRST_VECTOR_LENGTH * SECOND_VECTOR_LENGTH));
}
