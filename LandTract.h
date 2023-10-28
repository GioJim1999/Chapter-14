#pragma once
#include"FeetInches.h"
class LandTract
{
private:
	FeetInches length;
	FeetInches width;

public:
	//Constructors:
	LandTract();
	
	//Setters:
	void setLength(int feet, int inches);
	void setWidth(int feet, int inches);

	//Methods:
	FeetInches getArea();

	friend ostream& operator<<(ostream& out, LandTract& obj);
};

