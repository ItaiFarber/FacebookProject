#pragma once
#ifndef MAINFUNC_H
#define MAINFUNC_H
#include "user.h"
#include "buddy.h"
#include "page.h"

void AddBuddyToFB(User** &usersarray, int& lsize, int& psize);
void AddPageToFB(User** &usersarray, int& lsize, int& psize);
void AddStat(User** usersarray, int lsize);
void ShowStat(User** usersarray, int lsize);
int findUser(User** usersarray, int lsize, int typeofuser, char name[]);
void makeFriends(User** usersarray, int lsize);
void addBuddtoPage(User** usersarray, int lsize);
void showAllusers(User** usersarray, int lsize);
void showFriends(User** usersarray, int lsize);
void showRecentStatus(User** usersarray, int lsize);
void deleteFacebook(User** usersarray, int lsize);


#endif
