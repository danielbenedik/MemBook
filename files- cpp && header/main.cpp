
// DANIEL BENEDIK ~ I.D- 203914510 //
// TZACHI MITELMAN ~ I.D- 305164162 //


#include "facebook.h"
#include "classMember.h"
#include "functions.h"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

void main()
{
	int x;

	cout << "     ///////////////////////////////////\n";
	cout << "         welcome to 'parzuf sefer'\n";
	cout << "     /////////////////////////////////// \n\n";

	instruction();
	cin >> x; // get the answer of "enter the option that you want to do: " 
		
	OptionsInProcess(x);

	cout << "\n///////////////////////////////////\n";
	cout << "  Hope you enjoyed 'parzuf sefer', see you soon :) \n";
	cout << "/////////////////////////////////// \n\n";


	//system("pause");

}