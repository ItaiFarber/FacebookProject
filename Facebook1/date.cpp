#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "date.h"

Date::Date(int d, int m, int y) :day(d), month(m), year(y) // to be change
/*ctor*/
{

}

int Date::getday()
{
	return day;
}

int Date::getmonth()
{
	return month;
}

int Date::getyear()
{
	return year;
}

void Date::show()
/*show date*/
{
	cout << "The date is " << day << "/" << month << "/" << year << endl;
}