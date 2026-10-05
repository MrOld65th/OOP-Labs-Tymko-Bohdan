#include "newTriangle.h"
#include <iostream>
#include <math.h>
using namespace std;

newTriangle::newTriangle(double angleA, double angleB, double angleC, double sideAB, double sideBC, double sideCA)
{
	this->angleA = angleA;
	this->angleB = angleB;
	this->angleC = angleC;
	this->sideAB = sideAB;
	this->sideBC = sideBC;
	this->sideCA = sideCA;
}

newTriangle::newTriangle()
{
	int SrA;
againSrA:
	cout << "Enter side or angle (0 or 1)" << endl;
	cin >> SrA;
	cout << endl;

	if (SrA == 0) {


	againAB:
		cout << "Enter AB" << endl;
		cin >> this->sideAB;
		cout << endl;
		if (this->sideAB == 0 || this->sideAB < 0) { cout << "Enter positive value" << endl; goto againAB; }

	againBC:
		cout << "Enter BC" << endl;
		cin >> this->sideBC;
		cout << endl;
		if (this->sideBC == 0 || this->sideBC < 0) { cout << "Enter positive value" << endl; goto againBC; }

	againAC:
		cout << "Enter AC" << endl;
		cin >> this->sideCA;
		cout << endl;
		if (this->sideCA == 0 || this->sideCA < 0) { cout << "Enter positive value" << endl; goto againAC; }

		this->angleA = acos((pow(this->sideAB, 2) + pow(this->sideCA, 2) - pow(this->sideBC, 2)) / (2 * this->sideAB * this->sideCA)) * (180 / 3.14);
		this->angleB = acos((pow(this->sideAB, 2) + pow(this->sideBC, 2) - pow(this->sideCA, 2)) / (2 * this->sideAB * this->sideBC)) * (180 / 3.14);
		this->angleC = acos((pow(this->sideBC, 2) + pow(this->sideCA, 2) - pow(this->sideAB, 2)) / (2 * this->sideBC * this->sideCA)) * (180 / 3.14);
	}
	if (SrA == 1) {
	no180:
	againA:
		cout << "Enter angle A in DEG" << endl;
		cin >> this->angleA;
		cout << endl;
		if (this->angleA == 0 || this->angleA < 0) { cout << "Enter positive value" << endl; goto againA; }
		this->angleA = this->angleA / (180 / 3.14);

	againB:
		cout << "Enter angle B in DEG" << endl;
		cin >> this->angleB;
		cout << endl;
		if (this->angleB == 0 || this->angleB < 0) { cout << "Enter positive value" << endl; goto againB; }
		this->angleB = this->angleB / (180 / 3.14);

	againC:
		cout << "Enter angle C in DEG" << endl;
		cin >> this->angleC;
		cout << endl;
		if (this->angleC == 0 || this->angleC < 0) { cout << "Enter positive value" << endl; goto againC; }
		this->angleC = this->angleC / (180 / 3.14);

		if (((this->angleA * (180 / 3.14)) + (this->angleB * (180 / 3.14)) + (this->angleC * (180 / 3.14))) != 180) {
			cout << "Enter value totaling 180deg" << endl;
			goto no180;
		}
	againABA:
		cout << "Enter AB" << endl;
		cin >> this->sideAB;
		cout << endl;
		if (this->sideAB == 0 || this->sideAB < 0) { cout << "Enter positive value" << endl; goto againABA; }

		this->sideCA = this->sideAB * sin(this->angleB) / sin(this->angleC);
		this->sideBC = this->sideAB * sin(this->angleA) / sin(this->angleC);
		this->angleA = this->angleA * (180 / 3.14);
		this->angleB = this->angleB * (180 / 3.14);
		this->angleC = this->angleC * (180 / 3.14);
	}
	if (SrA != 0 && SrA != 1) goto againSrA;
}

newTriangle::newTriangle(newTriangle& other)
{
	this->angleA = other.angleA;
	this->angleB = other.angleB;
	this->angleC = other.angleC;
	this->sideAB = other.sideAB;
	this->sideBC = other.sideBC;
	this->sideCA = other.sideCA;
}

newTriangle::~newTriangle()
{
	std::string typeT;
	double P = sideAB + sideBC + sideCA;
	double S = sqrt((P / 2) * ((P / 2) - sideAB) * ((P / 2) - sideBC) * ((P / 2) - sideCA));
	if (this->sideAB == this->sideCA && this->sideCA == this->sideBC) typeT = "Equilateral";

	if (this->sideAB == this->sideCA && this->sideCA != this->sideBC ||
		this->sideAB != this->sideCA && this->sideCA == this->sideBC ||
		this->sideAB == this->sideBC && this->sideBC != this->sideCA) typeT = "Isosceles";

	if (this->angleA == 90 || this->angleB == 90 || this->angleC == 90) typeT = "Right-angled";

	if (this->sideAB != this->sideCA && this->sideBC != this->sideAB
		&& this->sideCA != this->sideBC && this->angleA != 90 && this->angleB != 90 && this->angleC != 90) typeT = "Scalene";

	cout << typeT << " Triangle with angles A: " << this->angleA
		<< "deg B: " << this->angleB
		<< "deg C: " << this->angleC
		<< "deg\n Sides AB: " << this->sideAB
		<< " BC: " << this->sideBC
		<< " CA: " << this->sideCA
		<< " and P: " << P
		<< " and S: " << S
		<< endl;
}

double newTriangle::getAngleA() const
{
	return angleA;
}

double newTriangle::getAngleB() const
{
	return angleB;
}

double newTriangle::getAngleC() const
{
	return angleC;
}

double newTriangle::getSideAB() const
{
	return sideAB;
}

double newTriangle::getSideBC() const
{
	return sideBC;
}

double newTriangle::getSideCA() const
{
	return sideCA;
}
