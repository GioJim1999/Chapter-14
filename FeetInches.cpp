#include "FeetInches.h"

//Constructors:
//Default
FeetInches::FeetInches()
{
	feet = 0;
	inches = 0;
}

//Precondition: f (int), i (int)
//Postcondition: sets feet to f and inches to i
FeetInches::FeetInches(int f, int i)
{
	feet = f;
	inches = i;
}


//Copy Constructor for Challenge 11
FeetInches::FeetInches(const FeetInches& obj)
{
	feet = obj.getFeet();
	inches = obj.getInches();
}

//Simplify function adds feet if the inches are greater than 12 
//then sets the inches to the remainder inches.
void FeetInches::simplify()
{
	if (inches >= 12)
	{
		feet += (inches / 12);
		inches = inches % 12;
	}
	else if (inches < 0)
	{
		feet -= (abs(inches) / 12 + 1);
		inches = 12 - (abs(inches) % 12);
	}
}

//Setters:
void FeetInches::setFeet(int f)
{
	feet = f;
}

void FeetInches::setInches(int i)
{
	inches = i;
}

//Getters:
int FeetInches::getFeet() const
{
	return feet;
}

int FeetInches::getInches() const
{
	return inches;
}

//Operators:
//Precondition: obj& (const FeetInches)
//Postcondition: adds two FeetInches objects and returns the sum as a new object
FeetInches FeetInches::operator+(const FeetInches& obj)
{
	FeetInches temp;

	temp.inches = inches + obj.inches;
	temp.feet = feet + obj.feet;
	temp.simplify();
	return temp;
}

//Precondition: obj& (const FeetInches)
//Postcondition: Returns the difference between two FeetInches objects as a new object
FeetInches FeetInches::operator-(const FeetInches& obj)
{
	FeetInches temp;

	temp.inches = inches - obj.inches;
	temp.feet = feet - obj.feet;
	temp.simplify();

	return temp;
}

//Precondition: obj& (const FeetInches)
//Postcondition: returns true if the object is less than or equal to obj false if the object is greater than obj
bool FeetInches::operator<=(const FeetInches& obj)
{
	bool status;
	if (feet == obj.feet)
	{
		if (inches <= obj.inches)
			status = true;
		else
			status = false;
	}
	else
	{
		if (feet <= obj.feet)
			status = true;
		else
			status = false;
	}

	return status;
}


//Precondition: obj& (const FeetInches)
//Postcondition: Returns true of the object is greater than or equal to obj, false if its less than.
bool FeetInches::operator>= (const FeetInches & obj)
{
	bool status;
	if (feet == obj.feet)
	{
		if (inches >= obj.inches)
			status = true;
		else
			status = false;
	}
	else
	{
		if (feet >= obj.feet)
			status = true;
		else
			status = false;
	}

	return status;
}

//Precondition: obj& (const FeetInches)
//Postcondtion: returns true if the objects are not equal false if they are
bool FeetInches::operator!=(const FeetInches& obj)
{
	bool status;
	if (feet == obj.feet && inches == obj.inches)
		status = false;
	else
		status = true;

	return status;
}

//Multiplication operator for challange 11
//Precondtion: obj& (const FeetInches)
//Postcondition: returns the multiplication product of the two objects as a new object.
FeetInches FeetInches::operator*(const FeetInches& obj)
{
	FeetInches temp(*this);

	temp.inches = this->inches * obj.inches;
	temp.feet = this->feet * obj.feet;

	temp.simplify();

	return temp;
}

//Precondition: out& (ostream), obj& (const FeetInches)
//Postcondition: returns the output for the FeetInches object.
ostream& operator<<(ostream& out, const FeetInches& obj)
{
	out << obj.getFeet() << " Feet " << obj.getInches() << " inches";
	return out;
}