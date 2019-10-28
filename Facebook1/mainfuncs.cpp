#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "mainfuncs.h"

const int MAX_NAME = 50;
const int MAX_STAT = 151;

void AddBuddyToFB(User** &usersarray, int& lsize, int& psize)
{
	char name[MAX_NAME];
	int d, m, y;
	bool exists = false;
	bool validdate = true;
	int index;

	cout << "Please enter buddy name: " << endl;
	cin.ignore(256, '\n');
	cin.getline(name, MAX_NAME);
	

	index = findUser(usersarray, lsize, 2, name);
	if (index != -1)
	{
		exists = true;
		cout << "This name is already taken !" << endl;
	}


	if (exists == false)
	{
		cout << "Please enter the birthdate:" << endl;
		cout << "Enter day: " << endl;
		cin >> d;
		cout << "Enter month: " << endl;
		cin >> m;
		cout << "Enter year: " << endl;
		cin >> y;

		if (d < 1 || d >31 || m < 1 || m>12 || y < 1939 || y > 2012)
		{
			validdate = false;
			cout << "The date you entered is invalid!" << endl;
		}
		

		if (validdate == true)
		{
			if (psize == 0)
			{
				psize = 2;
				usersarray = new User*[psize];
			}
			else if (lsize >= psize)
			{
				psize = psize * 2;
				User** temp = new User*[psize];
				for (int i = 0; i < lsize; i++)
				{
					temp[i] = usersarray[i];
				}

				delete[] usersarray;
				usersarray = temp;
			}

			usersarray[lsize] = new Buddy(name, d, m, y);
			lsize++;

			cout << "The buddy was added successfully to Facebook! " << endl;
		}
	}
}

void AddPageToFB(User** &usersarray, int& lsize, int& psize)
{
	char name[MAX_NAME];
	bool exists = false;
	int index;

	cout << "Please enter page name: " << endl;
	cin.ignore(256, '\n');
	cin.getline(name, MAX_NAME);


	index = findUser(usersarray, lsize, 1, name);
	if (index != -1)
	{
		exists = true;
		cout << "This name is already taken !" << endl;
	}

	if (exists == false)
	{
			if (psize == 0)
			{
				psize = 2;
				usersarray = new User*[psize];
			}
			else if (lsize >= psize)
			{
				psize = psize * 2;
				User** temp = new User*[psize];
				for (int i = 0; i < lsize; i++)
				{
					temp[i] = usersarray[i];
				}

				delete[] usersarray;
				usersarray = temp;
			}

			usersarray[lsize] = new Page(name);
			lsize++;

			cout << "The page was added successfully to Facebook! " << endl;
	}

}

void AddStat(User** usersarray, int lsize)
{
	int pORb;
	char name[MAX_NAME];
	char content[MAX_STAT];
	bool exists=false;
	int index;
	int kindofstat;

	cout << "Please enter 1 to add status to a Page" << endl;
	cout << "Please enter 2 to add status to a Buddy" << endl;
	cin >> pORb;

	while (pORb != 1 && pORb != 2)
	{
		cout << "Invalid choice! Try again" << endl;
		cin >> pORb;
	}

	cout << "Please enter the name of whom you want to add status to: " << endl;
	cin.ignore(256, '\n');
	cin.getline(name, MAX_NAME);

	if (pORb == 1)
	{
		index = findUser(usersarray, lsize, 1, name);

		if (index != -1)
		{
			exists = true;
		}


		if (exists == false)
		{
			cout << "There is no such page ! "<<endl;
		}
		else
		{
			cout << "Please choose what kind of status you want to add:" << endl;
			cout << "1 - Text, 2 - Image, 3 - Video:"<<endl;
			cin >> kindofstat;

			while (kindofstat != 1 && kindofstat != 2 && kindofstat != 3)
			{
				cout << "Invalid option! Try again!" << endl;
				cin >> kindofstat;
			}

			cout << "Please enter the status:  (maximum 150)" << endl;
			cin.ignore(256, '\n');
			cin.getline(content, MAX_STAT);
			usersarray[index]->addStatus(content, kindofstat);

			cout << "Status added successfuly" << endl;
		}
	}

	if (pORb == 2)
	{
		index = findUser(usersarray, lsize, 2, name);

		if (index != -1)
		{
			exists = true;
		}

		if (exists == false)
		{
			cout << "There is no such buddy ! " << endl;
		}
		else
		{
			cout << "Please choose what kind of status you want to add:" << endl;
			cout << "1 - Text, 2 - Image, 3 - Video:" << endl;
			cin >> kindofstat;

			while (kindofstat != 1 && kindofstat != 2 && kindofstat != 3)
			{
				cout << "Invalid option! Try again!" << endl;
				cin >> kindofstat;
			}

			cout << "Please enter the status:  (maximum 150)" << endl;
			cin.ignore(256, '\n');
			cin.getline(content, MAX_STAT);
			usersarray[index]->addStatus(content, kindofstat);
			cout << "Status added successfuly" << endl;
		}
	}
}

void ShowStat(User** usersarray, int lsize)
{
	int pORb;
	char name[MAX_NAME];
	int index;

	cout << "Please enter 1 to show all statuses of a Page" << endl;
	cout << "Please enter 2 to show all statuses of a Buddy" << endl;
	cin >> pORb;

	while (pORb != 1 && pORb != 2)
	{
		cout << "Invalid choice! Try again" << endl;
		cin >> pORb;
	}

	cout << "Please enter the name of whom you want to show status to: " << endl;
	cin.ignore(256, '\n');
	cin.getline(name, MAX_NAME);

	index = findUser(usersarray, lsize, pORb, name);

	if (index == -1)
	{
		cout << "There is no such user!!!" << endl;
	}
	else
	{
		usersarray[index]->showAllStatus();
	}
}

int findUser(User** usersarray, int lsize, int typeofuser, char name[])
{
	int index = -1;

	if (typeofuser == 1) // page 
	{
		for (int i = 0; i < lsize&&index == -1; i++)
		{
			Page* temp = dynamic_cast<Page*>(usersarray[i]);
			if (temp)
			{
				if (strcmp(temp->getname(), name) == 0)
				{
					index = i;
				}
			}

		}
	}

	if (typeofuser == 2) // buddy
	{
		for (int i = 0; i < lsize&&index == -1; i++)
		{
			Buddy* temp = dynamic_cast<Buddy*>(usersarray[i]);
			if (temp)
			{
				if (strcmp(temp->getname(), name) == 0)
				{
					index = i;
				}
			}

		}
	}

	return index;
}

void makeFriends(User** usersarray, int lsize)
{
	char name1[MAX_NAME];
	char name2[MAX_NAME];
	int index1, index2;

	cout << "Enter the first buddy name: " << endl;
	cin.ignore(256, '\n');
	cin.getline(name1, MAX_NAME);

	cout << "Enter the second buddy name: " << endl;
	//cin.ignore(256, '\n');
	cin.getline(name2, MAX_NAME);

	index1 = findUser(usersarray, lsize, 2, name1);
	index2 = findUser(usersarray, lsize, 2, name2);

	if (index1 == -1 || index2 == -1)
	{
		cout << "Error!! one or more of the buddies you entered does not exists in facebook" << endl;
	}
	else
	{
		usersarray[index1]->addBuddy((Buddy*)(usersarray[index2])); //ask Keren
		usersarray[index2]->addBuddy((Buddy*)(usersarray[index1])); //ask Keren
	}
}

void addBuddtoPage(User** usersarray, int lsize)
{
	char nameP[MAX_NAME];
	char nameB[MAX_NAME];
	int indexP, indexB;

	cout << "Enter the buddy name: " << endl;
	cin.ignore(256, '\n');
	cin.getline(nameB, MAX_NAME);

	cout << "Enter the page name: " << endl;
	//cin.ignore(256, '\n');
	cin.getline(nameP, MAX_NAME);

	indexP = findUser(usersarray, lsize, 1, nameP);
	indexB = findUser(usersarray, lsize, 2, nameB);

	if (indexP == -1 || indexB == -1)
	{
		cout << "Error!! one or more of the users you entered does not exists in facebook" << endl;
	}
	else
	{
		Buddy* temp = dynamic_cast<Buddy*>(usersarray[indexB]);
		if (temp)
			temp->addPage((Page*)(usersarray[indexP]));

		usersarray[indexP]->addBuddy(temp);//(Buddy*)(usersarray[indexP]));
	}
}

void showAllusers(User** usersarray, int lsize)
{
	for (int i = 0; i < lsize; i++)
	{
		usersarray[i]->show();
	}
}

void showFriends(User** usersarray, int lsize)
{
	int pORb;
	char name[MAX_NAME];
	int index;

	cout << "Please enter 1 to show friends of a Page" << endl;
	cout << "Please enter 2 to show friends of a Buddy" << endl;
	cin >> pORb;

	while (pORb != 1 && pORb != 2)
	{
		cout << "Invalid choice! Try again" << endl;
		cin >> pORb;
	}

	cout << "Please enter the name of whom you want to show friends: " << endl;
	cin.ignore(256, '\n');
	cin.getline(name, MAX_NAME);

	index = findUser(usersarray, lsize, pORb, name);

	if (index == -1)
	{
		cout << "There is no such a page or a buddy" << endl;
	}
	else
	{
		usersarray[index]->showAllBuddies();
	}	
}

void showRecentStatus(User** usersarray, int lsize)
{
	int index;
	char name[MAX_NAME];

	cout << "Please enter the buddy name: " << endl;
	cin.ignore(256, '\n');
	cin.getline(name, MAX_NAME);

	index = findUser(usersarray, lsize, 2, name);
	if (index == -1)
	{
		cout << "There is no such buddy!" << endl;
	}
	else
	{
		Buddy* temp = dynamic_cast<Buddy*>(usersarray[index]);
		if (temp)
			temp->showBudStatus();
	}
}

void deleteFacebook(User** usersarray, int lsize)
{
	for (int i = 0; i < lsize; i++)
	{
		delete usersarray[i];
	}

	delete[] usersarray;
}

