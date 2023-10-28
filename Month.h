#pragma once
#include<string>
#include<iostream>
using namespace std;
class Month
{
	const string months[13] = { "unknown", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

private:
	string name;
	int monthNumber;

public:
	//Constructors:
	Month();
	Month(string newName);
	Month(int newMonthNumber);
	Month(const Month& obj);

	//Setters:
	void setName(string newName);
	void setMonthNumber(int newMonthNumber);

	//Getters:
	string getMonthName() const;
	int getMonthNumber() const;

	//Operators:
	friend ostream& operator<<(ostream& out, const Month& obj);
	friend istream& operator>>(istream& in, Month& obj);

	Month operator++(); //prefix(++)
	Month operator++(int); //postfix(++)

	Month operator--(); //prefix(--)
	Month operator--(int); //postfix(--)
};

