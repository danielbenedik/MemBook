#ifndef _ARRYSDATA_H
#define _ARRYSDATA_H

#include "classMember.h"
#include "fanpage.h"
#include <vector>
#include <string>


class dataArray
{
	// the arrays
	vector <status*> status_array;
	vector <page*> facebookPage;

	// size of the arrays
	int facebookPage_arr_size, status_arr_size;
	int count_page, count_status, count_member, count_fan_page, count_facebookPage;

public:
	dataArray();
	
	void addstatus();
	
	void addPage(page* new_status);

	void printAllMember()const;

	void printAllstatus()const;

	void printAllfanPage()const;
	
	vector <page*> getPageArray(int* counter) const;

	int getCountStatus()const;

	int getCountMember()const;

	int getCountFanPage()const;

	fanPage* findfanPage(const string& name)const;

	member* findMember(const string& name)const; 

	vector<status*> getStatusArray(int* counter)const;
	
	~dataArray();

};




#endif