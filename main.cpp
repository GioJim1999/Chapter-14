//Giovanni Jimenez
//Chapter 14 - Assignment
//10-26-2023
//CMPR 121

#include<iostream>
#include"input.h"
#include"Month.h"
#include"Date.h"
#include"FeetInches.h"
#include"LandTract.h"
using namespace std;

//function prototypes:
int menuOption();
void Challenge7();
void Challenge8();
void Challenge9();
void Challenge11();
void Challenge12();
int getAmountOfDays(int month, int limit);
FeetInches getFeetInches();

//Main Function
int main()
{
	do
	{
		system("cls");
		switch (menuOption())
		{
		case 0:
			exit(1); break;
		case 7:
			Challenge7(); break;
		case 8:
			Challenge8(); break;
		case 9:
			Challenge9(); break;
		case 11:
			Challenge11(); break;
		case 12:
			Challenge12(); break;
		}
	} while (true);
}

//Menu Options function
int menuOption()
{
	cout << "\n\tChapter 14 - Assignment Giovanni Jimenez";
	cout << "\n\t______________________________________________________________________";
	cout << "\n\t7. Challenge 7 - Month Class";
	cout << "\n\t8. Challenge 8 - Date Class Modification";
	cout << "\n\t9. Challenge 9 - FeetInches Modification";
	cout << "\n\t11. Challenge 11 - FeetInches Copy Constructor and Multiply Function";
	cout << "\n\t12. Challenge 12 - LandTract Class";
	cout << "\n\t______________________________________________________________________";
	cout << "\n\t0. Exit Program";
	cout << "\n\t______________________________________________________________________";


	return inputInteger("\n\tOption: ",0,12);
}

//Challenge 7 Code
void Challenge7()
{
	system("cls");
	int monthNum = 0;

	cout << "\n\tChallenge 7 - Month Class";
	cout << "\n\t______________________________________________________________________";
	monthNum = inputInteger("\n\tEnter a month number (1...12): ", 1, 12);

	Month test(monthNum);

	cout << "\n\tCurrent Month:	" << test;
	cout << "\n\tPrefix ++ Month: " << ++test;
	cout << "\n\tPostfix ++ Month (before increment): " << test++;
	cout << "\n\tPost incrememted Month: " << test;
	cout << "\n\tPrefix -- Month: " << --test;
	cout << "\n\tPostfix -- Month (before decrement): " << test--;
	cout << "\n\tPost decrement Month: " << test;

	cout << "\n";

	system("pause");
}

//TODO REWORK SUBTRACTION OPERATOR TO USE THE ++ POST FIX OPERATOR
//REWORK ++ -- OPERATORS TO ACCOUNT FOR LEAP YEARS AND DAYS PER MONTH (28 FOR FEBRUARY ETC.) DONE
void Challenge8()
{
	system("cls");
	cout << "\n\tChallenge 8 - Date Class Modification";
	cout << "\n\t______________________________________________________________________";

	//Variable initliazation
	int year1, year2, month1, month2, day1, day2;
	
	//Ask user input, limit the year you cannot put a year lower than the start year.
	year1 = inputInteger("\n\tEnter your staring year (1...9999): ", 1, 9999);

	//ask for months next if the years are the same cannot put a month lower than the starting month 
	month1 = inputInteger("\n\tEnter your starting month (1...12): ", 1, 12);


	//Get the starting day.
	day1 = getAmountOfDays(month1,1);

	//Get the ending year limit the year to not be able to be lower than the starting year
	year2 = inputInteger("\n\tEnter your ending year (cannot be less than your starting year): ", year1, 9999);

	//Make sure the years are the same if they are limit the user's choices to not be able to choose a month below the starting
	//date
	if (year1 == year2)
		month2 = inputInteger("\n\tEnter your ending month (cannot be less than your starting month): ", month1, 12);
	else
		month2 = inputInteger("\n\tEnter your ending month (1...12): ", 1, 12);

	//Check to make sure the month and years are the same if they are 
	//Limit the user on what day they can choose and don't allow them to choose a day below the starting day.
	if (month1 == month2 && year1 == year2)
		day2 = getAmountOfDays(month2, day1);
	else
		day2 = getAmountOfDays(month2, 1);

	//Date Objects
	Date date1(day1, month1, year1);
	Date date2(day2, month2, year2);
	Date date3;

	//Subtraction operator
	date3 = date1 - date2;

	//Data output
	cout << "\n\t" << date1 << " is " << date3.getDay() << " days from " << date2;


	cout << '\n';

	system("pause");
}

//Precondition: month (int), limit (int)
//Postcondition: returns the calendar day the user chose limits the days they can choose depending on the current month they 
//selected limits them on what days they can choose depending on starting date.
int getAmountOfDays(int month, int limit)
{
	if (month == 2)
		return inputInteger("\n\tEnter the day (1...28): ", limit, 28);
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return inputInteger("\n\tEnter the day (1...31): ", limit, 31);
	else
		return inputInteger("\n\tEnter the day (1...30): ", limit, 30);
}

//Challenge 9 Code
void Challenge9()
{
	system("cls");
	cout << "\n\tChallenge 9 - Feet Inches Modification";
	cout << "\n\t______________________________________________________________________\n";
	//Feet inches object
	FeetInches test = getFeetInches();
	FeetInches test2 = getFeetInches();

	//Operator overloading code
	if (test <= test2)
		cout << "\n\t" << test << " is less than or equal to " << test2;
	else
		cout << "\n\t" << test << " is NOT less than or equal to " << test2;

	if (test >= test2)
		cout << "\n\t" << test << " is greater than or equal to " << test2;
	else
		cout << "\n\t" << test << " is NOT greater than or equal to " << test2;

	if (test != test2)
		cout << "\n\t" << test << " is NOT equal to " << test2;
	else
		cout << "\n\t" << test << " is equal to " << test2;

	cout << '\n';
	system("pause");
}

//Precondition: nothing
//Postcondition: asks the user for input to return a FeetInches Object.
FeetInches getFeetInches()
{
	int feet, inches;
	feet = inputInteger("\n\tEnter number of feet: ", true);
	inches = inputInteger("\n\tEnter number of inches: ", 0, 12);
	FeetInches object(feet, inches);
	return object;
}

//Challenge 11 code
void Challenge11()
{
	system("cls");
	cout << "\n\tChallenge 11 - FeetInches Copy Constructor and Multiply Function";
	cout << "\n\t______________________________________________________________________";
	
	//Feet inches objects
	FeetInches test = getFeetInches();
	FeetInches test2 = getFeetInches();

	//Feet inches object for multiplication overload
	FeetInches test3 = test * test2;

	cout << "Multiplication result: ";
	cout << test3 << "\n";

	system("pause");
}

//Code for Challenge12
void Challenge12()
{
	system("cls");
	cout << "\n\tChallenge 12 - LandTract Class";
	cout << "\n\t______________________________________________________________________\n";
	
	//LandTract object
	LandTract land;

	//Setters for length and width
	land.setLength(5, 3);
	land.setWidth(5, 2);

	cout << "\n\tLand dimensions: " << land;

	cout << "\n\tThe land's area is: " << land.getArea() << " squared\n";

	system("pause");
}