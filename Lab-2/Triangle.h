#pragma once
class Triangle
{
public:
	void Init(double angleA, double angleB, double angleC, double sideAB, double sideBC, double sideAC);
	void Read();
	void Display();
	void toString();
private:
	double angleA, angleB, angleC, sideAB, sideBC, sideAC;
};