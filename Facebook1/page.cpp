#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "page.h"
#include "buddy.h"

Page::Page(char* name):User(name)
{
	budsArray = NULL;
	psizeofBudsArr = 0;
	lsizeofBudsArr = 0;
}

Page::~Page()
{
	if (budsArray != NULL)
	{
		delete[] budsArray;
	}
}

void Page::show() const
{
	cout << "The following page is: " << endl;
	cout << "Name: " << name << endl;
}

void Page::showAllBuddies() const
{
	for (int i = 0; i < lsizeofBudsArr; i++)
	{
		budsArray[i]->show();
	}
}

void Page::addStatus(char* content, int typeofstatus)
{
	User::addStatus(content, typeofstatus);
}

void Page::addBuddy(Buddy* newbudd)
{
	bool exist = false;

	for (int i = 0; i < lsizeofBudsArr && exist == false; i++)
	{
		if (newbudd == budsArray[i])
		{
			exist = true;
			cout << "This buddy is already a fan of the page"<<endl;
		}

	}

	if (exist == false)
	{
		if (budsArray == NULL)
		{
			psizeofBudsArr = 2;
			budsArray = new Buddy*[psizeofBudsArr];
		}
		else if (lsizeofBudsArr >= psizeofBudsArr)
		{
			psizeofBudsArr = psizeofBudsArr * 2;
			Buddy** temp = new Buddy*[psizeofBudsArr];
			for (int i = 0; i < lsizeofBudsArr; i++)
			{
				temp[i] = budsArray[i];
			}

			delete[] budsArray;
			budsArray = temp;
		}
		budsArray[lsizeofBudsArr] = newbudd;
		lsizeofBudsArr++;
		cout << "The buddy is now fan of the page" << endl;
	}
}




