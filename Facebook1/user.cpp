#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "user.h"
#include "buddy.h"
#include "page.h"
//add copy ctor if needed 
// add addfriend if needed 

User::User(char* name)
{
	this->name = strdup(name);
	//budarr = NULL;
	statarr = NULL;
	lsizeofstat = 0;
	psizeofstat = 0;
	//psizeofbud = 0;
	//lsizeofbud = 0;
}

User::~User()
{
	delete[] name;
	/*if (budarr != NULL)
	{
		delete[] budarr;
	}*/

	if (statarr != NULL)
	{
		for (int i = 0; i < lsizeofstat; i++)
		{
			delete statarr[i];
		}
		delete[] statarr;
	}
}

void User::addStatus(char* content, int typeofstatus)
{
	Status** temparr;

	if (statarr == NULL) // if array is empty
	{
		psizeofstat = 2;
		statarr = new Status*[psizeofstat];
	}
	else if (lsizeofstat >= psizeofstat) //add size to statarr
	{
		psizeofstat = psizeofstat * 2;
		//make bigger temp array
		temparr = new Status*[psizeofstat];
		//copy data to temp array from old array
		for (int i = 0; i < lsizeofstat; i++)
		{
			temparr[i] = statarr[i];
		}
		//delete old array
		delete[] statarr;
		//copy address of temp array to stat array
		statarr = temparr;
	}
	switch (typeofstatus)
	{
	case 1://Text
		statarr[lsizeofstat] = new StatusText(name,content);
		lsizeofstat++;
		break;
	case 2:
		statarr[lsizeofstat] = new StatusImage(name, content);
		lsizeofstat++;
		break;
	case 3:
		statarr[lsizeofstat] = new StatusVideo(name, content);
		lsizeofstat++;
		break;
	default:
		cout << "There is no such type of status" << endl;
		break;
	}
}

void User::showAllStatus() const
{
	for (int i = 0; i < lsizeofstat; i++)
	{
		statarr[i]->showstatus();
	}
}

char* User::getname() const
{
	return name;
}