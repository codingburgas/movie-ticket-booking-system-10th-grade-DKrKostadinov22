#include "Menu.h"

void Admin::adminMenu()
{
	clearscreen();
	cout << "                               You have choose admin menu!" << endl;
	
	/*   DA DOBAVQ SLED KATO DOBAVQ RAZLICHNITE KINA
	
	cout << "Choose what you wnat to do" << endl << "1 for adding a new movie" << endl << "2 for deleting an existing movie" << endl;
	int inAdminMenuChoice;
	cin >> inAdminMenuChoice;
	switch (inAdminMenuChoice)
	{
	case 1:
		clearscreen();
		cout << "You have chose to add a film!";
		break;
	case 2:
		clearscreen();
		cout << "You have chose to delete an existing film!";
		break;
	default:
		clearscreen();
		cout << "Incorrect input";
		break;
	}
	*/
	
}
void Customer::customerMenu()
{
	clearscreen();
	cout << "You have chose customer menu!";
}

void clearscreen()
{
	system("cls");
}



void menuChoice()
{
	Customer* customerPtr = new Customer;
	Admin* adminPtr = new Admin; 

	cout << "Select menu" << endl << "1 for custumers" << endl << "2 for admin" << endl;

	int menuChoose;
	cin >> menuChoose;

	switch (menuChoose)
	{
	case 1:
		customerPtr->customerMenu();
		
		break;
	case 2:
		adminPtr->adminMenu();
		
		break;
	default:
		clearscreen();
		cout << "Incorrect input!";
		
	}

	delete customerPtr;
	delete adminPtr;
}
