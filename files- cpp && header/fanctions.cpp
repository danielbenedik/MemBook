#include "functions.h"

void instruction()
{
	cout << "what you want to do (press the option that you want)? \n";
	cout << "1. add a member \n" << "2. add a fan page \n" << "3. add a status to member or fan page \n";
	cout << "4. show the statuses of member or fan page \n" << "5. make 2 members friend \n" << "6. add fan page as favorite to a member \n";
	cout << "7. show all members and fan pages in the system \n" << "8. show all friends or fan pages of a member \n" << "9. show 10 update status of the frinds of member \n" << "0. exit\n";
	cout << "enter the option that you want to do: ";
}

void TestsForLinkingMembers(member* member1, page* _page)
{
	if (member1 == _page) // Checks whether I'm trying to add myself as a friend
		cout << " hey, sorry,  you can't be friend of your self " << endl;
	else
	{
		member* temp = dynamic_cast<member*>(_page);
		if (temp)
		{
			if (member1->getArrays()->findMember(_page->getName()))
				cout << "The friend you are trying to add is already on your friends list " << endl;
			else
			{
				*member1 += _page;
				*_page += member1;
			}

		}
		else // if it fan page 
		{
			if (member1->getArrays()->findfanPage(_page->getName()))
				cout << "The fan-page you are trying to add is already on your fan-page list " << endl;
			else
			{
				member1->addpage(_page);
				_page->addpage(member1);
				cout << member1->getName() << " did like to " << _page->getName() << endl;
			}


		}
	}
}

void OptionsInProcess(int x)
{
	faceBook dataBace;
	int option;
	string name1, name2;
	member *member1, *member2;
	fanPage* fan_page;

		while (x != 0)
	{
		cout << "---------------------------------------" << endl;
		switch (x)
		{
		case 1:
			dataBace.addNewMember();
			break;
		case 2:
			dataBace.addNewFanPage();
			break;
		case 3:
			cout << "do you want to add status to: \npress 1 for fan page\npress 2 for member " << endl;
			cin >> option;
			if (option == 1)
			{
				cout << "Type the fan-page name- ";

				cin.ignore(1);
				getline(cin, name1);

				cout << name1;

				fan_page = dataBace.findfanPage(name1);
				if (fan_page)
					fan_page->addNewStatus();
				else
					cout << "Sorry, there are not exist fan-page with this name " << endl;
			}

			else if (option == 2)
			{
				cout << "enter the name member- ";

				cin.ignore(1);
				getline(cin, name1);

				member1 = dataBace.findMember(name1);
				if (member1)
					member1->addNewStatus();
				else
					cout << "Sorry, there are not exist member with this name " << endl;
			}
			break;
		case 4:
			cout << "do you want to show the status to: \npress 1 for fan page\npress 2 for member" << endl;
			cin >> option;
			if (option == 1)
			{
				cout << "Type the fan-page name- ";

				cin.ignore(1);
				getline(cin, name1);


				fan_page = dataBace.findfanPage(name1);
				if (fan_page)
					fan_page->printAllStatus();
				else
					cout << "Sorry, there are not exist fan-page with this name " << endl;
			}
			else if (option == 2)
			{
				cout << "enter your name member- " << endl;

				cin.ignore(1);
				getline(cin, name1);

				member1 = dataBace.findMember(name1);
				if (member1)
					member1->printAllStatus();
				else
					cout << "Sorry, there are not exist member with this name " << endl;
			}
			break;
		case 5:

			cout << "enter your first name member- ";

			cin.ignore(1);
			getline(cin, name1);

			member1 = dataBace.findMember(name1);

			if (member1)
			{
				cout << "enter your second name member- ";

				getline(cin, name2);


				member2 = dataBace.findMember(name2);

				if (member2)
					TestsForLinkingMembers(member1, member2);
				else
					cout << "Sorry, the friend you wanted to add does not exist " << endl;
			}
			else
				cout << "Sorry, there are not exist member with this name " << endl;
			break;
		case 6:

			cout << "enter your name member- ";

			cin.ignore(1);
			getline(cin, name1);

			member1 = dataBace.findMember(name1);

			if (member1)
			{
				cout << "What is the name of the fan-page you want to add?- ";
			

				getline(cin, name2);

				fan_page = dataBace.findfanPage(name2);

				if (fan_page)
				{
					TestsForLinkingMembers(member1, fan_page);
				}
				else
					cout << "Sorry, there are not exist fan-page with this name " << endl;
			}
			else
				cout << "Sorry, there are not exist member with this name " << endl;

			break;
		case 7:
			dataBace.printMember();
			dataBace.printfanPage();
			break;
		case 8:
			cout << "do you want to show the friend of: \npress 1 for fan page\npress 2 for member" << endl;
			cin >> option;

			if (option == 1)
			{
				cout << "Type the fan-page name- " << endl;
				cin.ignore(1);
				getline(cin, name1);


				fan_page = dataBace.findfanPage(name1);

				if (fan_page)
					fan_page->printAllfriends();
				else
					cout << "Sorry, there are not exist fan-page with this name " << endl;
			}
			else if (option == 2)
			{
				cout << "enter the name member- ";

				cin.ignore(1);
				getline(cin, name1);

				member1 = dataBace.findMember(name1);

				if (member1)
					member1->printAllfriends();
				else
					cout << "Sorry, there are not exist member with this name " << endl;

			}
			break;
		case 9:
			cout << "enter the name member- ";


			cin.ignore(1);
			getline(cin, name1);

			member1 = dataBace.findMember(name1);

			if (member1)
			{
				cout << "the Ten status: " << endl << endl;
				member1->printTenNewFriendsStatus();
			}
			else
				cout << "Sorry, there are not exist member with this name " << endl;
			break;
		default:
			cout << "you enter wrong number please try again\n";
			break;
		}
		cout << "---------------------------------------" << endl;
		instruction();
		cin >> x;
	}
	return;
}