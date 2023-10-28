#include "LandTract.h"

//Constructors:
LandTract::LandTract()
{
	length.setFeet(0);
	length.setInches(0);

	width.setFeet(0);
	width.setInches(0);
}

//Setters:
void LandTract::setLength(int feet, int inches)
{
	length.setFeet(feet);
	length.setInches(inches);
}

void LandTract::setWidth(int feet, int inches)
{
	width.setFeet(feet);
	width.setInches(inches);
}

//Postcondition: returns a new object with the dimensions of the product of length * width.
FeetInches LandTract::getArea()
{
	FeetInches temp = length * width;

	return temp;
}

//Operators:
ostream& operator<<(ostream& out, LandTract& obj)
{
	out << "\n\tLength: " << obj.length << " \n\tWidth: " << obj.width;
	return out;
}