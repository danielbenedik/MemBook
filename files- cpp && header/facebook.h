#ifndef _FACEBOOK_H // אם קראו לי כבר לקובץ כלשהו והוסיפו אותי. אל תוסיף אותי שוב.
#define _FACEBOOK_H

#include <stdio.h>
#include <iostream>
#include <string>
#include "classMember.h"
#include "fanpage.h"
#include "arrysdata.h"

// the big-data of our program

class faceBook
{
	dataArray arrys; // faceBook have class of 3 personal array- 1.members 2.fan-page 3.status- that all the time nullptr

public:

	faceBook(){};

	void addNewMember(); 
	void printMember()const; // print all the array


	void addNewFanPage();
	void printfanPage()const; // print all the array

	//        Search functions     //
	member* findMember(const string& name)const;
	fanPage*  findfanPage(const string& name)const;
};


#endif
