#include "../Include/Menu.h"	

void clearscreen()
{
	system("cls");
}

void Admin::adminLogIn()
{
	string adminUsername, adminPassword;


	ifstream file("Users\\admin_credentials.txt");

	getline(file, adminUsername);
	getline(file, adminPassword);

	file.close();

	cout << setw(50) << "You have chosen admin menu!" << endl;
	cout << "You have to log in to use admin menu!" << endl << "Username: ";
	cin >> username;

	if (username == adminUsername)
	{
		cout << "Password: ";
		cin >> password;

		if (password == adminPassword)
		{
			clearscreen();
			cout << setw(50) << "You have logged in successfully!" << endl;
		}
		else
		{
			cout << "Incorrect password!" << endl;
			exit(0);
		}
	}
	else
	{
		cout << "Incorrect username!" << endl;
		exit(0);
	}
}

void Admin::createOrDeleteMovie()
{
	cout << "Choose what you wnat to do" << endl << "1 for adding a new movie" << endl << "2 for deleting an existing movie" << endl;
	int inAdminMenuChoice;
	cin >> inAdminMenuChoice;
	switch (inAdminMenuChoice)
	{
	case 1:
		clearscreen();
		cout << setw(50) << "You have chosen to add a film!";
		break;
	case 2:
		clearscreen();
		cout << "You have chosen to delete an existing film!";
		break;
	default:
		clearscreen();
		cout << "Incorrect input";
		break;
	}
}
void Admin::adminMenu()
{
	clearscreen();
	adminLogIn();
	chooseCinema();
	createOrDeleteMovie();
}

void Customer::customerMenu()
{
	clearscreen();
	cout << "You have chosen customer menu!";
}

void chooseCinema()
{
	clearscreen();
	int cinema;
	cout << "Choose in which cinema you want to go" << endl << "1 for cinemaCity" << endl << "2 for cinemaMax" << endl;
	cin >> cinema;
	switch (cinema)
	{
	case 1: clearscreen();
		cout << setw(50) << "You have entered cinemaCity";
		break;
	case 2: clearscreen();
		cout << setw(50) << "You have entered cinemaMax";;
		break;
	default: clearscreen();
		cout << "Incorrect input";
	}
	cout << endl;
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
