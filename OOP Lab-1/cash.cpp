#include "cash.h"
#include <iostream>
using namespace std;

void cash::init(int f, int s)
{
	this->first = f;
	this->second = s;
}

void cash::Read() 
{
	int f, s;
	cout << "Denomination" << endl;
	nom:
	cin >> f;
	cout << endl;
	if (f != 1 && f != 2 && f != 5 && f != 10 && f != 20 && f != 50 && f != 100 && f != 500 && f != 1000) {
		cout << "Enter an existing denomination: 1, 2, 5, 10, 20, 50, 100, 500, 1000;" << endl;
		goto nom;
	}
	this->first = f;
	cout << "Amount" << endl;
	cin >> s;
	cout << endl;
	this->second = s;
}

void cash::Display()
{
	cout << this->second << " banknotes with a face value of " << this->first << endl;
}

void cash::Sum()
{
	cout << "Monetary amount:" << this->first * this->second << endl;
}
