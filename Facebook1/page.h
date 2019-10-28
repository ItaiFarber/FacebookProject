#pragma once
#ifndef PAGE_H
#define PAGE_H
#include "user.h"

class Buddy;

class Page:public User {
private:
	Buddy** budsArray;
	int lsizeofBudsArr;
	int psizeofBudsArr;

public:
	Page(char* name);
	~Page();

	virtual void addBuddy(Buddy* newbudd);
	virtual void show() const;
	virtual void showAllBuddies() const;
	virtual void addStatus(char* content, int typeofstatus);
};


#endif
