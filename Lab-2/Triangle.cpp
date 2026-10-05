#include "Triangle.h"
#include <iostream>
#include <math.h>
using namespace std;

void Triangle::Init(double angleA, double angleB, double angleC, double sideAB, double sideBC, double sideAC)
{
	this->angleA = angleA;
	this->angleB = angleB;
	this->angleC = angleC;
	this->sideAB = sideAB;
	this->sideBC = sideBC;
	this->sideAC = sideAC;
}

void Triangle::Read()
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
			cin >> this->sideAC;
			cout << endl;
		if (this->sideAC == 0 || this->sideAC < 0) { cout << "Enter positive value" << endl; goto againAC; }

		this->angleA = acos((pow(this->sideAB, 2) + pow(this->sideAC, 2) - pow(this->sideBC, 2)) / (2 * this->sideAB * this->sideAC)) * (180 / 3.14);
		this->angleB = acos((pow(this->sideAB, 2) + pow(this->sideBC, 2) - pow(this->sideAC, 2)) / (2 * this->sideAB * this->sideBC)) * (180 / 3.14);
		this->angleC = acos((pow(this->sideBC, 2) + pow(this->sideAC, 2) - pow(this->sideAB, 2)) / (2 * this->sideBC * this->sideAC)) * (180 / 3.14);
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

		this->sideAC = this->sideAB * sin(this->angleB) / sin(this->angleC);
		this->sideBC = this->sideAB * sin(this->angleA) / sin(this->angleC);
		this->angleA = this->angleA * (180 / 3.14);
		this->angleB = this->angleB * (180 / 3.14);
		this->angleC = this->angleC * (180 / 3.14);
	}
	if (SrA != 0 && SrA != 1) goto againSrA;
}

void Triangle::Display()
{
	if (this->sideAB == this->sideAC == this->sideBC) 
		cout << "Equilateral Triangle with angles A: " << this->angleA 
		<< "deg B: " << this->angleB 
		<< "deg C: " << this->angleC 
		<< "deg\n Sides AB: " << this->sideAB 
		<< " BC: " << this->sideBC 
		<< " AC: " << this->sideAC 
		<< endl;

	if (this->sideAB == this->sideAC && this->sideAC != this->sideBC ||
		this->sideAB != this->sideAC && this->sideAC == this->sideBC || 
		this->sideAB == this->sideBC && this->sideBC != this->sideAC)
		cout << "Isosceles Triangle with angles A: " << this->angleA 
		<< "deg B: " << this->angleB 
		<< "deg C: " << this->angleC 
		<< "deg\n Sides AB: " << this->sideAB 
		<< " BC: " << this->sideBC 
		<< " AC: " << this->sideAC
		<< endl;

	if (this->angleA == 90 || this->angleB == 90 || this->angleC == 90)
		cout << "Right - angled Triangle with angles A: " << this->angleA
		<< "deg B: " << this->angleB
		<< "deg C: " << this->angleC
		<< "deg\n Sides AB: " << this->sideAB
		<< " BC: " << this->sideBC
		<< " AC: " << this->sideAC
		<< endl;

	if (this->sideAB != this->sideAC && this->sideBC != this->sideAB 
		&& this->sideAC != this->sideBC && this->angleA != 90 && this->angleB != 90 && this->angleC != 90)
		cout << "Scalene Triangle with angles A: " << this->angleA
		<< "deg B: " << this->angleB
		<< "deg C: " << this->angleC
		<< "deg\n Sides AB: " << this->sideAB
		<< " BC: " << this->sideBC
		<< " AC: " << this->sideAC
		<< endl;
}

void Triangle::toString()
{
}