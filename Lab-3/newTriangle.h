#pragma once
#include <iostream>
class newTriangle
{
public:
	newTriangle(double angleA, double angleB, double angleC, double sideAB, double sideBC, double sideCA);
	newTriangle();
	newTriangle(newTriangle& other);
	~newTriangle();

	double getAngleA() const;
	double getAngleB() const;
	double getAngleC() const;
	double getSideAB() const;
	double getSideBC() const;
	double getSideCA() const;
private:
	double angleA, angleB, angleC;
	double sideAB, sideBC, sideCA;
};