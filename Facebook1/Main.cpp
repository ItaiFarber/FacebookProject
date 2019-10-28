#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string.h>
#include "mainfuncs.h"


void main()
{
	User** allUsersArr=NULL;
	int lsizeusers=0, psizeusers=0;
	cout << "Welcome to FACEBOOK!" << endl;
	int command;
	bool exit = false;

	cout << "Please select one of the options below:" << endl;
	cout << "1 - Add buddy to Facebook"<<endl;
	cout << "2 - Add fan page to Facebook" << endl;
	cout << "3 - Add status to buddy or fan page" << endl;
	cout << "4 - Show all statuses of a buddy or a fan page" << endl;
	cout << "5 - Make friendship between two buddies" << endl;
	cout << "6 - Add buddy to a fan page" << endl;
	cout << "7 - Show all buddies and fan pages in Facebook" << endl;
	cout << "8 - Show all buddies of a certain buddy or a fan page" << endl;
	cout << "9 - Show 10 most recent statuses of a buddy's buddies" << endl;
	cout << "10 - Exit Facebook" << endl;

	cout << ">> ";
	cin >> command;
	cout << endl;

	while (command <1 || command > 10)
	{
		cout << "Error: Invalid option! Try again." << endl;
		cout << ">> ";
		cin >> command;
		cout << endl;
	}


	while (command >= 1 && command <= 10 && exit== false)
	{
		switch (command)
		{
		case 1:
			AddBuddyToFB(allUsersArr, lsizeusers, psizeusers);
			break;
		case 2:
			AddPageToFB(allUsersArr, lsizeusers, psizeusers);
			break;
		case 3:
			AddStat(allUsersArr, lsizeusers);
			break;
		case 4:
			ShowStat(allUsersArr, lsizeusers);
			break;
		case 5:
			makeFriends(allUsersArr, lsizeusers);
			break;
		case 6:
			addBuddtoPage(allUsersArr, lsizeusers);
			break;
		case 7:
			showAllusers(allUsersArr, lsizeusers);
			break;
		case 8:
			showFriends(allUsersArr,lsizeusers);
			break;
		case 9:
			showRecentStatus(allUsersArr, lsizeusers);
			break;
		case 10:
			exit = true;
			cout << "Bye bye!" << endl;
			break;
		default:
			break;
		}
		
		if (exit == false)
		{
			cout << ">> ";
			cin >> command;
			cout << endl;

			while (command < 1 || command > 10)
			{
				cout << "Error: Invalid option! Try again." << endl;
				cout << ">> ";
				cin >> command;
				cout << endl;
			}
		}
	}

	deleteFacebook(allUsersArr, lsizeusers);
}