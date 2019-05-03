
#ifndef _TIME_H // אם קראו לי כבר לקובץ כלשהו והוסיפו אותי. אל תוסיף אותי שוב.
#define _TIME_H
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class date
{
	int year;
	int month;
	int day;

public:
	date(int day, int month, int year);
	void print() const;

};
#endif