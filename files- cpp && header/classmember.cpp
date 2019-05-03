#include "classMember.h"
#include "arrysdata.h"

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

member::member(int  day, int month, int year) :date_member(day, month, year){}

void member::print()
{
	cout << "name of the member- " ;
	page::print(); // the 'father' print

	cout <<endl <<"the birth is- "; date_member.print(); cout << endl;
}

bool member::operator>(const member& other)const
{
	int me_count = this->arrays->getCountMember();
	int other_count = other.arrays->getCountMember();

	return (me_count > other_count);
}

void member::printTenNewFriendsStatus()const
{
	int count_friends, count_status = 0;
	vector <page*> friends = this->arrays->getPageArray(&count_friends); // here we get the friend array of the member and get the number of his friends

	vector <status*> temp_friendsStatus; // make temporary array in the size of 10 for each friend this array will get 10 statuses from each friend
	vector<status*> temp_status; // this will contain the pointer for the statuses of each friend in the loop
	int i = 0, index_friends = 0, index_status, index_temp_status = 0;

	temp_friendsStatus.resize(10 * count_friends);


	while (i < ((count_friends) * 10) && index_friends<count_friends) // loop that run over the friends and get their statuses
	{
		member* temp = dynamic_cast<member*>(friends[index_friends]);
		if (temp)
		{
			temp_status = friends[index_friends]->getArrays()->getStatusArray(&count_status); //get the status array of the current friend and the number of statuses in the array
			index_status = count_status - 1;
			if (count_status > 10) // in case that there are more then 10 statuses it copy the last 10
			{
				for (int j = count_status - 1; j > count_status - 11; j--)
				{
					temp_friendsStatus[index_temp_status] = temp_status[j];
					index_temp_status++;
				}
			}
			else //in case that there are less then 10 statuses it copy all of them
			{
				for (int j = 0; j < count_status; j++)
				{
					temp_friendsStatus[index_temp_status] = temp_status[j];
					index_temp_status++;
				}
			}
			index_friends++;
		}
		i++;
	}

	if (index_temp_status != 0)
		mergeSort(temp_friendsStatus, 0, index_temp_status - 1);// this will sort the array of statuses and return the 10 new statuses

	if (index_temp_status == 0) // in case that there is no statuses in his friends status it print that there is no statuses
		cout << "there is no statuses to his friends\n";
	else if (index_temp_status>10) //in case that there are more then 10 statuses of all his friends print only the 10 last of them

		for (int j = 10; j > 0; j--)
		{
			temp_friendsStatus[j - 1]->print();
		}
	else//in case that there are less then 10 statuses of all his friends print all of them
		for (int j = index_temp_status; j > 0; j--)
		{
			temp_friendsStatus[j - 1]->print();
		}

	
}


void merge(vector<status*>& arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int id1, id2;

	// create temp arrays 
	vector <status*> Left;
	vector <status*> Right;

	Left.resize(n1 + 1);
	Right.resize(n2 + 1);

	// Copy data to temp arrays
	for (i = 0; i < n1; i++)
		Left[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		Right[j] = arr[m + 1 + j];

	// Merge the temp arrays back into arr and initial the index of subarray
	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2)
	{
		id1 = Left[i]->getStatusId();
		id2 = Right[j]->getStatusId();
		if (id1 < id2)
		{
			arr[k] = Left[i];
			i++;
		}
		else
		{
			arr[k] = Right[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of Left
	while (i < n1)
	{
		arr[k] = Left[i];
		i++;
		k++;
	}

	//* Copy the remaining elements of Right
	while (j < n2)
	{
		arr[k] = Right[j];
		j++;
		k++;
	}
}


void mergeSort(vector<status*>& arr, int left, int right)
{
	if (left < right)
	{

		int mid = left + (right - left) / 2;

		// Sort first and second halves 
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}
