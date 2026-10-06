#pragma once
#include <math.h>

class newTriangleA
{
public:
	newTriangleA(double angleA, double angleB, double angleC, double sideAB, double sideBC, double sideCA);
	newTriangleA();
	newTriangleA(newTriangleA& other);
	~newTriangleA();

	newTriangleA operator+(newTriangleA& other) const {
		return newTriangleA(angleA, angleB, angleC, sideAB+other.sideAB, sideBC+other.sideBC, sideCA+other.sideCA);
	}
	newTriangleA operator*(newTriangleA& other) const {
		double P1 = sideAB + sideBC + sideCA;
		double P2 = other.sideAB + other.sideBC + other.sideCA;
		double S1 = sqrt((P1 / 2) * ((P1 / 2) - sideAB) * ((P1 / 2) - sideBC) * ((P1 / 2) - sideCA));
		double S2 = sqrt((P2 / 2) * ((P2 / 2) - other.sideAB) * ((P2 / 2) - other.sideBC) * ((P2 / 2) - other.sideCA));

		double SS = S2 / S1;

		return newTriangleA(angleA, angleB, angleC, sideAB*SS, sideBC*SS, sideCA*SS);
	}
	newTriangleA operator^(newTriangleA& other) const {
		return newTriangleA(angleA, angleB, angleC, sideAB*other.sideAB, sideBC*other.sideBC, sideCA*other.sideCA);
	}
private:
	double angleA, angleB, angleC;
	double sideAB, sideBC, sideCA;
};