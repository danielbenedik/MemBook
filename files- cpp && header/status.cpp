#define _CRT_SECURE_NO_WARNINGS

#include "status.h"

int status::counter_status = 0;

status::status() :status_id(++counter_status), date_time(time(NULL)) {}

void status::print() // this is not const because we use the function ctime for printing the current time of status
{
	cout << endl;
	current_time = ctime(&date_time);
	cout << "the upload time of the status is: " << current_time; //this is for print the time
	cout << "ID: " << this->status_id << endl << endl;
}

int status::getStatusId() const
{
	return status_id;
}


Text_status::Text_status() :status() {}


Picture_status::Picture_status() : status() {}


Video_status::Video_status() : status() {}


Video_Text_status::Video_Text_status() : status() {}

Picture_Text_status::Picture_Text_status() : status() {}
//

void Text_status::print()
{
	cout << "show text in text window";
	status::print();
}

void Picture_status::print()
{
	cout << "show picture in text window";
	status::print();
}

void Video_status::print()
{
	cout << "show video in text window";
	status::print();
}

void Video_Text_status::print()
{
	cout << "show video and text in text window";
	status::print();
}

void Picture_Text_status::print()
{
	cout << "show picture and text in text window";
	status::print();
}

bool status::operator==(status& status1)
{
	if (strcmp(typeid(status1).name(), typeid(*this).name()) == 0)
	{
		return true;
	}
	else
		return false;
}

bool status::operator!= (status& status1)
{

	if (strcmp(typeid(status1).name(), typeid(*this).name()) == 0)
	{
		return false;
	}
	else
		return true;
}