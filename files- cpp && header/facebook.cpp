#include "facebook.h"

//   memebers  function      //
void faceBook::addNewMember()
{
	int day, month, year;
	cout << "Please enter your date of birth (DD MM YY)- ";
	cin >> day >> month >> year;
	member* new_member = new member(day, month, year);

	if (this->arrys.findMember(new_member->getName())) // Checks whether it exists in the system
	{
		cout << "Hi friend, you already exist in the system" << endl;
		delete(new_member);
	}
	else
		arrys.addPage(new_member); // add to array page
}

void faceBook::printMember()const
{
	arrys.printAllMember();
}

member* faceBook::findMember(const string& name)const
{
	return arrys.findMember(name);
}

//   fun-page  function      //
void faceBook::addNewFanPage()
{
	fanPage* new_fan_page = new(fanPage);

	if (this->arrys.findfanPage(new_fan_page->getName())) // Checks whether it exists in the system
	{
		cout << "Hey, there already exists Fan-Page with this name in the faceBooke " << endl;
		delete(new_fan_page);
	}
	else
		arrys.addPage(new_fan_page); // add to array page}
}

void faceBook::printfanPage()const
{
	arrys.printAllfanPage();
}

fanPage* faceBook::findfanPage(const string& name)const
{
	return arrys.findfanPage(name);
}
