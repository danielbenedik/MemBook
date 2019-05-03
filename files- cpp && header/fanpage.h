#ifndef _FANPAGE_H // אם קראו לי כבר לקובץ כלשהו והוסיפו אותי. אל תוסיף אותי שוב.
#define _FANPAGE_H

#include "string.h"
#include "time.h"
#include "status.h"
#include "classMember.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "page.h"

using namespace std;

class fanPage :public page
{

public:
	virtual void print();
};


#endif