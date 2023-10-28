#include "Date.h"

//Month names array
string monthNames[] = {"unknown", "January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November" ,"December" };

//Constructors:
Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(int newDay, int newMonth, int newYear)
{
    day = newDay;
    month = newMonth;
    year = newYear;
}

Date::Date(const Date& obj)
{
    day = obj.getDay();
    month = obj.getMonth();
    year = obj.getYear();
}

//Day setter and getter
void Date::setDay(int newDay)
{
    day = newDay;
}

int Date::getDay() const
{
    return day;
}

//Month setter and getter
void Date::setMonth(int newMonth)
{
    month = newMonth;
}

int Date::getMonth() const
{
    return month;
}

//Year setter and getter
void Date::setYear(int newYear)
{
    year = newYear;
}

int Date::getYear() const
{
    return year;
}

//Member functions 
string Date::dateFormat1()
{
    return to_string(getMonth()) + "/" + to_string(getDay()) + "/" + to_string(getYear());
}

string Date::dateFormat2()
{
    return monthNames[getMonth()] + " " + to_string(getDay()) + ", " + to_string(getYear());
}

string Date::dateFormat3()
{
    return to_string(getDay()) + " " + monthNames[getMonth()] + " " + to_string(getYear());
}

//Operators:
//Precondition: out& (ostream), obj& (Date)
//Postcondition: returns the output for the date object.
ostream& operator<<(ostream& out, Date& obj)
{
    out << obj.dateFormat2();

    return out;
}

//Overloaded but I'm not using this lol can't write code for input validation here using input.h
istream& operator>>(istream& in, Date& obj)
{
    //make sure the user doesn't enter a day thats out of bounds
    int tempDay = 0;
    cout << "Day: ";
    in >> tempDay;
    if (tempDay >= 1 && tempDay <= 31)
        obj.setDay(tempDay);
    else
        obj.setDay(0);

    //makes sure the user doesn't enter a month thats out of bounds
    int tempMonth = 0;
    cout << "Month: ";
    in >> tempMonth;
    if (tempMonth >= 1 && tempMonth <= 12)
        obj.setMonth(tempMonth);
    else
        obj.setMonth(0);

    //Makes sure the user doesn't enter a year thats out of bounds
    int tempYear = 0;
    cout << "Year: ";
    in >> tempYear;
    if (tempYear >= 1 && tempYear <= 9999)
        obj.setYear(tempYear);
    else
        obj.setYear(0);

    return in;
}


Date Date::operator++()
{
    //increment variable
    day++;
    
    //check what month is currently selected then set day depending on the month set day to 1 after 28 days for feb to 1 after jan etc...
    if (month == 2)
    {
        if (day > 28)
        {
            setDay(1);
            month++;
            setMonth(month);
        }
    }
    //Reset day after 31 for months ending in 31 days
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day > 31)
        {
            setDay(1);
            month++;
            //makes sure if the month goes above 12 to reset to 1 and increment the year
            if (month > 12)
            {
                setMonth(1);
                year++;
                setYear(year);
            }
            else
                setMonth(month);
        }
    }
    //sets the day to one for months ending in 30 days
    else
    {
        if (day > 30)
        {
            setDay(1);
            month++;
            setMonth(month);
        }
    }
    return *this;
}

//Same thing as previous operator but for post fix ++ operator.
Date Date::operator++(int)
{
    Date temp(*this);
    day++;
    if (month == 2)
    {
        if (day > 28)
        {
            setDay(1);
            month++;
            setMonth(month);
        }
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day > 31)
        {
            setDay(1);
            month++;
            if (month > 12)
            {
                setMonth(1);
                year++;
                setYear(year);
            }
            else
                setMonth(month);
        }
    }
    else
    {
        if (day > 30)
        {
            setDay(1);
            month++;
            setMonth(month);
        }
    }
    return temp;
}

//prefix -- opeartor
Date Date::operator--()
{
    day--;
    if (day < 1)
    {
        setDay(31);
        month--;
        setMonth(month);
        if (month < 1)
        {
            setMonth(12);
            year--;
            setYear(year);
        }
    }
    return *this;
}

//postfix -- operator
Date Date::operator--(int)
{
    Date temp(*this);
    day--;
    if (day < 1)
    {
        setDay(31);
        month--;
        setMonth(month);
        if (month < 1)
        {
            setMonth(12);
            year--;
            setYear(year);
        }
    }
    return temp;
}

//Subtraction operator
//Precondition: obj& ( const Date) 
//Post condition: Loops until the two date objects are equal counting how many times it had to loop using the ++ operator
//sets the amount of days it took to reach the end date to temp.days to be accessed later, every loop is assumed to be a day more.
Date Date::operator-(const Date& obj)
{
    Date temp(*this);
    
    int days = 0;

    while (true)
    {
        if (temp == obj)
        {
            temp.setDay(days);
            break;
        }
        days++;
        temp++;
    }
    temp.setDay(days);

    return temp;
}

//Equality operator ==
//Precondition: obj& (const Date)
//Postcondition: returns a true if the two objects are the same day == day, month == month, year == year. false if they are not equal
bool Date::operator==(const Date& obj)
{
    Date temp(*this);

    if ((temp.getDay() == obj.getDay()) && (temp.getMonth() == obj.getMonth()) && (temp.getYear() == obj.getYear()))
        return true;
    else
        return false;
}