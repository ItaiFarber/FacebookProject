#ifndef DATE_H
#define DATE_H

class Date{
private:
	int day;
	int month;
	int year;

public:
	Date(int d, int m, int y); // to be change
	int getyear();
	int getmonth();
	int getday();
	void show();
};


#endif
