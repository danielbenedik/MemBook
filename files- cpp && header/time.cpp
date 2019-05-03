#include "time.h"

 date::date(int day, int month, int year)
{

	bool bol = true;
	while (bol)
	{
		if (0 < day && day < 32 && 0 < month && month < 13)
		{
			this->day = day;
			this->month = month;
			this->year = year;
			return;
		}
		cout << "One of the data you typed is incorrect. Please try again in this format- DD MM YY ";
		cin >> day >> month >> year;
	}
}
void date::print() const
{
	cout << day << "." << month << ".";
	if (0 <= year && year <= 18)
		cout << 2000 + year;
	else
		cout << 1900 + year;
}