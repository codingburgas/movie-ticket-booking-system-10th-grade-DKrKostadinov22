#include "../Include/Menu.h"	
#include "Misc.h"
#include "Movie.h"
#include "show.h"
#include "Booking.h"
string currentUser;
namespace Admin 
{
	void adminLogIn()
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

	void adminMenu()
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
namespace Customer
{
	void customerMenu()
	{
		clearscreen();
		cout << "You have chosen customer menu!";
		customerLogin();
		chooseCinema();
		cout << "1 to make a booking \n 2 to delete a booking" << endl; 
		string choice;
		cin >> choice;
		Booking booking;
		switch (stoi(choice))
		{
		case 1:
		{
			booking.makeBooking();
			break;
		}
		case 2:
		{
			booking.cancelBooking();
			break;
		}
		default:
			break;
		}
	}

	string chooseShow()
	{
		cout << endl << "Choose which show you want to watch" << endl;
		if (!ListFiles(getCurrentDir(showDir), CallBackPrintf))
		{
			return string("");
		}

		cout << endl << "Enter show name:";
		string choice;
		cin >> choice;

		string filePath;

		filePath = getCurrentDir(showDir) + choice + ".txt";

		ifstream inFile(filePath);
		if (!inFile.is_open())
		{
			cout << "Show not found!" << endl;
			return string("");
		}

		string currentTitle, currentDate, currentSeat;
		getline(inFile, currentTitle);
		getline(inFile, currentDate);
		getline(inFile, currentSeat);
		inFile.close();
		clearscreen();
		cout << "Show information:" << endl;
		cout << "Title: " << currentTitle << endl;
		cout << "Date: " << currentDate << endl;
		cout << "Seat Type: " << currentSeat << endl;
		return choice;
	}

	void customerLogin()
	{
		cout << "You have chosen customer menu!" << endl;
		cout << "1 for Register" << endl << "2 for Login" << endl;
		int choice;
		cin >> choice;
		string userRegister, passRegister;
		string userLogIn, passLogIn;

		switch (choice)
		{
		case 1: clearscreen();
		{
			ifstream customer("Users\\Customer" + userRegister + ".txt");
			if (!customer.is_open())
			{
				cout << "You chose to register" << endl;
				cout << "Username:";
				cin >> userRegister;
				currentUser = userRegister;
				ofstream createFile("Users\\Customer" + userRegister + ".txt");
				createFile << userRegister << endl;
				cout << "Password:";
				cin >> passRegister;
				createFile << passRegister << endl;
				createFile.close();
			}
			else
			{
				customer.close();
			}
			break;
		}
		case 2: clearscreen();
			cout << "You chose to logIn" << endl;
			cout << "Username:";
			string userUsername;
			string userPassword;



			cin >> userLogIn;
			ifstream file("Users\\Customer" + userLogIn + ".txt");

			getline(file, userUsername);
			getline(file, userPassword);
			currentUser = userLogIn;
			if (userLogIn == userUsername)
			{
				cout << "Password:";
				cin >> passLogIn;
				if (passLogIn == userPassword)
				{
					cout << "You successfully logged in";
				}
				else
				{
					exit(1);
				}
			}
			else
			{
				exit(1);
			}
			break;
		}
	}
}

void menuChoice()
{


	cout << "Select menu" << endl << "1 for custumers" << endl << "2 for admin" << endl;

	int menuChoose;
	cin >> menuChoose;

	switch (menuChoose)
	{
	case 1:
		Customer::customerMenu();
		break;
	case 2:
		Admin::adminMenu();
		break;
	default:
		clearscreen();
		cout << "Incorrect input!";
		
	}
}
