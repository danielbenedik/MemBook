#include"arrysdata.h"

dataArray::dataArray()
{
	facebookPage_arr_size = 1, status_arr_size = 1;
	count_member = 0, count_status = 0, count_fan_page = 0, count_facebookPage=0;
}

void dataArray::addPage(page* new_page)
{

	facebookPage.push_back(new_page);

	count_facebookPage++;

	//   decide which count to increase
	member* temp = dynamic_cast<member*>(new_page); 
	if (temp)
		count_member++;
	else
		count_fan_page++;

}

void dataArray::addstatus()
{
	int x;
	status* new_status;
	cout << "which type of status u want?\n1) text\n2) picture\n3) video\n4) picture with text\n5) video with text\n";
	cin >> x;
	switch (x)
	{
		case 1:
			new_status = new Text_status;
			break;
		case 2:
			new_status = new Picture_status;
			break;
		case 3:
			new_status = new Video_status;
			break;
		case 4:
			new_status = new Picture_Text_status;
			break;
		case 5:
			new_status = new Video_Text_status;
			break;
		default:
			new_status = new status;
			break;
	}
	

	status_array.push_back(new_status);

	count_status++;
}


void dataArray::printAllMember()const
{
	cout << endl << "the friends are: " << endl;
	for (int i = 0; i < count_facebookPage; i++)
	{
		member* temp = dynamic_cast<member*>(facebookPage[i]);
		if (temp)
		{
			temp->print();
			cout << endl;
		}
		
	}
}

void dataArray::printAllstatus()const
{
	if (count_status == 0)
	{
		cout << "there are no status to show " << endl;
		return;
	}
	for (int i = 0; i < count_status; i++)
		status_array[i]->print();
}

void dataArray::printAllfanPage()const
{
		
	for (int i = 0; i < count_facebookPage; i++)
	{
		fanPage* temp = dynamic_cast<fanPage*>(facebookPage[i]);
		if (temp)
		{
			temp->print();
			cout << endl;
		}
	}	
}

vector <page*> dataArray::getPageArray(int* counter) const
{
	*counter = count_facebookPage;
	return facebookPage;
}

vector<status*> dataArray::getStatusArray(int* counter)const
{
	*counter = count_status;
	return status_array;
}

int dataArray::getCountStatus() const
{
	return count_status;
}

int dataArray::getCountMember()const
{
	return count_member;
}

int dataArray::getCountFanPage()const
{
	return count_fan_page;
}

fanPage* dataArray::findfanPage(const string& name)const
{
	for (int i = 0; i < count_facebookPage; i++)
	{
		fanPage* temp_fan_page = dynamic_cast<fanPage*>(facebookPage[i]);

		if (temp_fan_page)
		{
			const string& temp = facebookPage[i]->getName();
		if ((temp.compare(name)) == 0)
			return  temp_fan_page;
		}
	}
	return nullptr;
}

member* dataArray::findMember(const string& name)const
{
	for (int i = 0; i < count_facebookPage; i++)
	{
		member* temp_member = dynamic_cast<member*>(facebookPage[i]);

		if (temp_member)
		{
			const string& temp = facebookPage[i]->getName();
			if ((temp.compare(name)) == 0)
				return  temp_member;
		}
	}
	return nullptr;

}

dataArray::~dataArray()
{
	//      clean and delete the 2 arrays       //

	for (int i = 0; i < count_status; i++)
		delete(status_array[i]);
	

	for (int i = 0; i < count_facebookPage; i++)
		delete(facebookPage[i]);
	

}