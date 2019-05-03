#include "classMember.h"
#include "arrysdata.h"
#include "page.h"

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

page::page() :arrays(new(dataArray))
{
	cout << "please enter NAME- ";
	cin.ignore(1);
	getline(cin, name);

}

void page::print()
{
	cout << name;
}

void page::addpage(page* new_page)
{
	arrays->addPage(new_page);
}

const string& page::getName()
{
	return name;
}

void page::addNewStatus()
{
	arrays->addstatus();
}

void page::printAllfriends()const
{
	arrays->printAllMember();
}

void page::printAllStatus()const
{
	arrays->printAllstatus();
}

page::~page()
{
	delete arrays;
}

void page::operator+=(page* _page)
{
	this->addpage(_page);
}


dataArray* page::getArrays()
{
	return arrays;
}