#ifndef USER_H
#define USER_H
#include <string.h>
#include "status.h"

class Buddy;
class Page;

class User {
protected:
	char* name;
	//Buddy** budarr;
	Status** statarr;
	//int psizeofbud;
	//int lsizeofbud;
	int psizeofstat;
	int lsizeofstat;


public:

	User(char* name);
	virtual ~User();

	virtual void addStatus(char* content, int typeofstatus) =0;
	void showAllStatus() const;
	virtual void showAllBuddies() const =0;
	virtual void addBuddy(Buddy* newbudd) =0;
	virtual void show() const = 0;
	char* getname() const;
};



#endif 

