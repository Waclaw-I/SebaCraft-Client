#pragma once

class MathMethods
{
public:
	static MathMethods & getMathMethods();
	double degToRad(double rotation);
private:
	MathMethods();
	MathMethods(const MathMethods &);
};