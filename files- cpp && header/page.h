#ifndef _CLASSPAGE_H // אם קראו לי כבר לקובץ כלשהו והוסיפו אותי. אל תוסיף אותי שוב.
#define _CLASSPAGE_H

#include "string.h"
#include "time.h"
#include "status.h"

#include <stdio.h>
#include <iostream>
#include <string>

class dataArray;
class fanPage;

class page
{
protected:
	string name;
	dataArray* arrays; // Each member have a class of 3 personal array- 1.members 2.fan-page 3.status

public:

	page();
	
	virtual void print();

	void addpage(page* new_page);

	void addNewStatus();

	const string& getName();

	void printAllfriends()const;

	void printAllStatus()const;

	dataArray* getArrays();

	void operator+=(page* _page);

	virtual ~page();

};



#endif