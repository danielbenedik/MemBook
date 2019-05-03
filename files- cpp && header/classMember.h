#ifndef _CLASSMEMBER_H // אם קראו לי כבר לקובץ כלשהו והוסיפו אותי. אל תוסיף אותי שוב.
#define _CLASSMEMBER_H

#include "string.h"
#include "time.h"
#include "status.h"
#include "page.h"
#include <string>


#include <stdio.h>
#include <iostream>
#include <string>
#include<vector>

class dataArray;
class fanPage;

class member : public page
{
	date date_member; 

public:

	member(int  day, int month, int year);

	virtual void print();
	
	void printTenNewFriendsStatus()const;

	friend void mergeSort(vector<status*>& arr, int l, int r); // Sorting the top 10 most recent statuses

	friend void merge(vector<status*>& arr, int l, int m, int r);

	bool operator>(const member& other)const;


};



#endif