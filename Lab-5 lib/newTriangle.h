#pragma once
class newTriangle
{
public:
	newTriangle(double angleA, double angleB, double angleC, double sideAB, double sideBC, double sideCA);
	newTriangle();
	newTriangle(newTriangle& other);
	~newTriangle();

private:
	double angleA, angleB, angleC;
	double sideAB, sideBC, sideCA;
};

