#include "Month.h"

//Constructors:
//Postcondition: Creates a new object with default values January, 1
Month::Month()
{
	name = "January";
	monthNumber = 1;
}

//Precondition: newName (string)
//Postcondition: creates a new object with the newName
Month::Month(string newName)
{
	setName(newName);
}

//Precondition: newMonthNumber (int)
//Postcondition: creates a new object with the newMonthNumber
Month::Month(int newMonthNumber)
{
	setMonthNumber(newMonthNumber);
}

//Copy Constructor
//Precondition: ojb& (const Month)
//Postcondition: creates a copy of the passed in object.
Month::Month(const Month& obj)
{
	monthNumber = obj.getMonthNumber();
	name = obj.getMonthName();
}

//Setters:
//Precondition: newName (string)
//Postcondition: sets the objects name to the newName also sets the month number depending on the passed in name
void Month::setName(string newName)
{
	for (int i = 0; i <= 12; i++)
	{
		if (newName == months[i])
		{
			monthNumber = i;
			name = months[monthNumber];
			return;
		}
	}
	monthNumber = 0;
	name = months[monthNumber];
}

//Precondition: newMonthNumber (int)
//Postcondition: sets the monthNumber to newMonthNumber and sets the new month name depeding on the month number
void Month::setMonthNumber(int newMonthNumber)
{
	if (newMonthNumber >= 1 && newMonthNumber <= 12)
		monthNumber = newMonthNumber;
	else
		monthNumber = 0;

	name = months[monthNumber];
}

//Getters:
string Month::getMonthName() const
{
	return name;
}

int Month::getMonthNumber() const
{
	return monthNumber;
}

//Operators:
ostream& operator<<(ostream& out, const Month& obj)
{
	out << "Number: " << obj.getMonthNumber() << " - " << obj.getMonthName();
	return out;
}

//Stream in operator
istream& operator>>(istream& in, Month& obj)
{
	int temp = 0;
	cout << "Month Number: ";
	cin >> temp;

	if (temp >= 0 && temp <= 12)
		obj.monthNumber = temp;
	else
		obj.monthNumber = 0;

	obj.setMonthNumber(obj.getMonthNumber());

	return in;
}

Month Month::operator++()
{
	monthNumber++;
	if (monthNumber > 12)
		setMonthNumber(1);
	else
		setMonthNumber(monthNumber);
	return *this;
}

Month Month::operator++(int)
{
	Month temp(*this);
	
	monthNumber++;

	if (monthNumber > 12)
		setMonthNumber(1);
	else
		setMonthNumber(monthNumber);

	return temp;
}

Month Month::operator--()
{
	monthNumber--;
	if (monthNumber < 1)
		setMonthNumber(12);
	else
		setMonthNumber(monthNumber);

	return *this;
}

Month Month::operator--(int)
{
	Month temp(*this);

	monthNumber--;

	if (monthNumber < 1)
		setMonthNumber(12);
	else
		setMonthNumber(monthNumber);

	return temp;
}