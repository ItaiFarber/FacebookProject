#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "status.h"

//status parent

int Status::counter = 0;

Status::Status(char* name)
{
	nameofpublisher = name;
	curtime = time(0);
	id = ++counter;
}


void Status::showstatus() const
{
	cout << "The publisher name is: " << nameofpublisher << endl;
	cout << "The status was published on: " << ctime(&curtime) << endl;
}

int Status::getid() const
{
	return id;
}

//Status text

StatusText::StatusText(char* namec, char* content): Status::Status(namec)
{
	this->content = strdup(content);

}

StatusText::~StatusText()
{
	delete[] content;
}

void StatusText::showstatus() const 
{
	Status::showstatus();
	cout << "This is a text status:" << endl;
	cout << "the status is: " << content << endl;
}

//status image
StatusImage::~StatusImage()
{
	delete[] content;
}

StatusImage::StatusImage(char* namec, char* content) : Status::Status(namec)
{
	this->content = strdup(content);

}

void StatusImage::showstatus() const 
{
	Status::showstatus();
	cout << "This is an image status:" << endl;
	cout << "the status is: " << content << endl;
}

//status video
StatusVideo::StatusVideo(char* namec, char* content) : Status::Status(namec)
{
	this->content = strdup(content);

}

StatusVideo::~StatusVideo()
{
	delete[] content;
}

void StatusVideo::showstatus() const
{
	Status::showstatus();
	cout << "This is an video status:" << endl;
	cout << "the status is: " << content << endl;
}


