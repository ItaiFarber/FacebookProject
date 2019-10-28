#pragma once
#ifndef STAT_H
#define STAT_H
#include <ctime>

class Status {
private:
	time_t curtime;
	int id;
	static int counter;
	char* nameofpublisher;

public:

	Status(char* name);
	//should we add =default?!!!!!!
	virtual ~Status()=default;
	virtual void showstatus() const =0;
	int getid() const;
};

class StatusText : public Status {
private:
	char* content;

public:
	StatusText(char* namec, char* content);
	~StatusText();
	virtual void showstatus() const override;

};

class StatusImage : public Status {
private:
	char* content;

public:
	StatusImage(char* namec, char* content);
	~StatusImage();
	virtual void showstatus() const override;
};

class StatusVideo : public Status {
private:
	char* content;

public:
	StatusVideo(char* namec, char* content);
	~StatusVideo();
	virtual void showstatus() const override;
};


#endif