#ifndef _STATUS_H
#define _STATUS_H

#include <ctime>
#include <stdio.h>
#include <iostream>
#include <string>


using namespace std;


class status
{
protected:
	static int counter_status;
	int status_id;
	time_t date_time;
	char* current_time;

public:
	status();
	virtual void print();
	int getStatusId() const;
	status(const status& other);
	bool operator==(status& status2);
	bool operator!= (status& status1);


};

class Text_status : virtual public status
{

public:
	Text_status();
	virtual void print();
};

class Picture_status : virtual public status
{

public:
	Picture_status();
	virtual void print();
};

class Video_status : virtual public status
{

public:
	Video_status();
	virtual void print();
};

class Video_Text_status : public Video_status, public Text_status
{

public:
	Video_Text_status();
	virtual void print();
};

class Picture_Text_status : public Picture_status, public Text_status
{

public:
	Picture_Text_status();
	virtual void print();
};

#endif // !_FAN_PAGE_H