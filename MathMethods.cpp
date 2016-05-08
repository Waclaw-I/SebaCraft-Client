#include "MathMethods.h"

MathMethods & MathMethods::getMathMethods()
{
	static MathMethods math;
	return math;
}

MathMethods::MathMethods() {}
MathMethods::MathMethods(const MathMethods & math) {}

double MathMethods::degToRad(double rotation)
{
	return (rotation * (3.14 / 180));
}