#include "../Include/Menu.h"	
#include "Misc.h"
#include "Movie.h"
#include "show.h"
void Admin::adminLogIn()
{
	string username, password;
	string fileUsername, filePassword;


	ifstream file("Users\\admin_credentials.txt");

	getline(file, fileUsername);
	getline(file, filePassword);

	file.close();

	cout << setw(50) << "You have chosen admin menu!" << endl;
	cout << "You have to log in to use admin menu!" << endl << "Username: ";
	cin >> username;

	if (username == fileUsername)
	{
		cout << "Password: ";
		cin >> password;

		if (password == filePassword)
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

void Admin::adminMenu()
{
	Movie movie;
	Show show;
	clearscreen();
	adminLogIn();
	chooseCinema();
	int choice;
	cout << "1 for adding a show" << endl << "2 for deleting a show" << endl << "3 for updating a show" << endl << "4 for adding a movie" << endl << "5 for deleting a movie" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		show.addShow();
		break;
	case 2:
		show.deleteShow();
		break;
	case 3:
		show.updateShow();
		break;
	case 4:
		movie.addMovie();
		break;	
	case 5:
		movie.deleteMovie();
		break;

	}

}

void Customer::customerMenu()
{
	clearscreen();
	cout << "You have chosen customer menu!";
}

void chooseCinema()
{
	clearscreen();
	cout << "Choose in which cinema you want to go" << endl << "1 for cinemaCity" << endl << "2 for cinemaMax" << endl;
	int cinema;
	cin >> cinema;
	switch (cinema)
	{
	case 1: clearscreen();
		cout << setw(50) << "You have entered cinemaCity";
		current = cinemaCity;
		break;
	case 2: clearscreen();
		cout << setw(50) << "You have entered cinemaMax";;
		current = cinemaMax;
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
