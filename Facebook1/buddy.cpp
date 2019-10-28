#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "page.h"
#include "buddy.h"

Buddy::Buddy(char* name, int day, int month, int year):User(name)
{
	birthdate = new Date(day,month,year);
	numofBudStat = 0;
	for (int i = 0; i < 10; i++)
	{
		statofbuddarr[i] = NULL;
	}
	lsizeofuserarr = 0;
	psizeofuserarr = 0;
	usersarr = NULL;
}

Buddy::~Buddy()
{
	delete birthdate;
	if (usersarr != NULL)
	{
		delete[] usersarr;
	}
}

void Buddy::showBudStatus() const
/*showing the recent 10 statuses of a friend*/
{
	for (int i = 0; i < numofBudStat; i++)
	{
		statofbuddarr[i]->showstatus();
	}
}

void Buddy::show() const
/*Showing the profile of this buddy*/
{
	cout << "The following buddy is: " << endl;
	cout << "Name: " << name << endl;
	cout << "Birthdate: " << birthdate->getday() << "/" << birthdate->getmonth() << "/" << birthdate->getyear() << endl;
}

void Buddy::showAllBuddies() const
/*Showing the buddies of this buddy*/
{
	for (int i = 0; i < lsizeofuserarr; i++)
	{
		Buddy* tempbud = dynamic_cast<Buddy*>(usersarr[i]);
		if (tempbud)
			tempbud->show();
	}
}

void Buddy::showPages() const
/*Showing pages of this buddy*/
{
	for (int i = 0; i < lsizeofuserarr; i++)
	{
		Page* temppage = dynamic_cast<Page*>(usersarr[i]);
		if (temppage)
			temppage->show();
	}
}

void Buddy::addPage(Page* newpage)
/*Add page to this buddy*/
{
	if (usersarr == NULL)
	{
		psizeofuserarr = 2;
		usersarr = new User*[psizeofuserarr];
	}
	else if (psizeofuserarr <= lsizeofuserarr)
	{
		User** temp;
		psizeofuserarr = psizeofuserarr * 2;
		temp = new User*[psizeofuserarr];
		for (int i = 0; i < lsizeofuserarr; i++)
		{
			temp[i] = usersarr[i];
		}
		delete[] usersarr;
		usersarr = temp;
	}

	usersarr[lsizeofuserarr] = newpage;
	lsizeofuserarr++;
}

void Buddy::addToRecentStatus(Status* stat)
/*Add the status that we get to the array of recent status*/
{
	if (numofBudStat < 10)
	{
		statofbuddarr[numofBudStat] = stat;
		numofBudStat++;
	}
	else
	// the array is full
	{
		for (int i = 1; i < 10; i++)
		{
			statofbuddarr[i - 1] = statofbuddarr[i];
		}
		statofbuddarr[9] = stat;

	}
}


void Buddy::addStatus(char* content, int typeofstatus)
/*Add status of this buddy to his array and update all his buddies*/
{
	User::addStatus(content, typeofstatus);

	//update the status at friends
	for (int i = 0; i < lsizeofuserarr; i++)
	{
		Buddy* temp = dynamic_cast<Buddy*>(usersarr[i]);
		if (temp)
			temp->addToRecentStatus(this->statarr[lsizeofstat-1]);
	}
}

void Buddy::addBuddy(Buddy* newbudd)
/*Add buddy to this buddy 
and update the new buddy's recent statuses to the array of recent status*/
{
	bool exist = false;

	for (int i = 0; i < lsizeofuserarr&&exist == false; i++)
	{
		if (usersarr[i] == newbudd)
		{
			exist = true;
			cout << "They are already friends of each other!" << endl;
		}
	}

	if (exist == false)
	{
		//Add buddy to the users array
		if (usersarr == NULL)
		{
			psizeofuserarr = 2;
			usersarr = new User*[psizeofuserarr];
		}
		else if (psizeofuserarr <= lsizeofuserarr)
		{
			User** temp;
			psizeofuserarr = psizeofuserarr * 2;
			temp = new User*[psizeofuserarr];
			for (int i = 0; i < lsizeofuserarr; i++)
			{
				temp[i] = usersarr[i];
			}
			delete[] usersarr;
			usersarr = temp;
		}

		usersarr[lsizeofuserarr] = newbudd;
		lsizeofuserarr++;

		//Add his statuses
		if (numofBudStat == 0)//if the recent status array of this is empty
		{
			if (newbudd->lsizeofstat > 10)
			{
				int j = 0;
				for (int i = newbudd->lsizeofstat - 10; i < newbudd->lsizeofstat; i++)
				{
					this->statofbuddarr[j] = newbudd->statarr[i];
					j++;
					numofBudStat++;
				}
			}
			else
			{
				for (int i = 0; i < newbudd->lsizeofstat; i++)
				{
					this->statofbuddarr[i] = newbudd->statarr[i];
					numofBudStat++;
				}
			}
		}
		else //if the recent status array of this is not empty
		{
			for (int i = (newbudd->lsizeofstat - 1); i >= 0; i--)//newbudd
			{
				if (numofBudStat == 10)//if recent status array is full
				{
					for (int k = numofBudStat - 1; k >= 0; k--)//this buddy
					{
						if (newbudd->statarr[i]->getid() > this->statofbuddarr[k]->getid())//find the place to replace
						{
							if (k == 0)//if the place is the first in the array
							{
								this->statofbuddarr[k] = newbudd->statarr[i];
							}
							else
							{
								for (int h = 1; h <= k; h++)//move array
								{
									this->statofbuddarr[h - 1] = this->statofbuddarr[h];
								}
								this->statofbuddarr[k] = newbudd->statarr[i];
							}
							break;
						}
					}
				}
				else // if recent status array is not full
				{
					for (int k = numofBudStat - 1; k >= 0; k--)//this buddy
					{
						if (newbudd->statarr[i]->getid() > this->statofbuddarr[k]->getid())//find the place to replace
						{
							if (k == numofBudStat - 1)//if the place is the last in the array
							{
								this->statofbuddarr[numofBudStat] = newbudd->statarr[i];
								numofBudStat++;
							}
							else
							{
								for (int h = numofBudStat - 1; h > k; h--)//move array 
								{
									this->statofbuddarr[h + 1] = this->statofbuddarr[h];
								}
								this->statofbuddarr[k] = newbudd->statarr[i];
								numofBudStat++;

							}
							break;
						}
						//else // added!
						//{
						//	if (k == 0)
						//	{
						//		for (int h = numofBudStat - 1; h > k; h--)
						//		{
						//			this->statofbuddarr[h + 1] = this->statofbuddarr[h];
						//		}
						//		this->statofbuddarr[k] = newbudd->statarr[i];
						//		numofBudStat++;
						//	}
						//	break;
						//}

					}
				}
			}
		}
	}
}


