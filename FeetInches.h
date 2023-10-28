#pragma once
#include<iostream>
#include<cmath>
using namespace std;

class FeetInches
{
private:
	int feet;
	int inches;
	void simplify();

public:
	//Constructors:
	FeetInches();
	FeetInches(int f, int i);
	//Copy Constructor for challange 11
	FeetInches(const FeetInches&);

	//Setters:
	void setFeet(int f);
	void setInches(int i);

	//Getters:
	int getFeet() const;
	int getInches()	const;

	//Operators:
	friend ostream& operator<<(ostream& out, const FeetInches& obj);
	FeetInches operator+(const FeetInches&);
	FeetInches operator-(const FeetInches&);
	bool operator>=(const FeetInches&);
	bool operator<=(const FeetInches&);
	bool operator!=(const  FeetInches&);

	//Multiplicaton operator for Challenge 11
	FeetInches operator*(const FeetInches&);

};

