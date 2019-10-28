#pragma once
#ifndef BUDD_H
#define BUDD_H
#include "user.h"
#include "date.h"

class Page;

class Buddy:public User{
private:
	Date* birthdate;
	Status* statofbuddarr[10];
	int numofBudStat;
	User** usersarr;
	int lsizeofuserarr;
	int psizeofuserarr;

public:
	Buddy(char* name,int day, int month, int year);
	~Buddy();

	void showBudStatus() const;
	virtual void addBuddy(Buddy* newbudd);
	void addPage(Page* newpage);
	void showPages() const;
	void addToRecentStatus(Status* stat);
	virtual void show() const;
	virtual void showAllBuddies() const;
	virtual void addStatus(char* content, int typeofstatus);

};

#endif
