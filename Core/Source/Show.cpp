#include "show.h"
#include "Misc.h"
#include <string>
#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

void Show::addShow()
{
	printf("\n\n");
	if (!ListFiles(getCurrentDir(),CallBackPrintf))
	{
		return;
	}
	cout << "\nChoose in which movie you want to select" << endl;
	string movieName;
	cin >> movieName;
	if (!FindFile(getCurrentDir(), movieName))
	{
		cout << "Movie doesn't exist" << endl;
		Sleep(1000);
		return;
	}
	cout << "Enter show date" << endl;
	Show show;
	string date;
	cin >> date;
	show.setShowDate(date);
	show.setMovieTitle(movieName);
	ticket:
	cout << "Choose seat type, you can choose from: Silver, Gold and Platinum" << endl;
	string type;
	cin >> type;
	if (type == "Silver" || type == "Gold" || type == "Platinum")
		show.setShowSeatType(type);
	else
		goto ticket;
	ofstream fileShow(getCurrentShowDir() + movieName + ".txt");


	show.setMovieTitle(movieName);
	show.setShowDate(date);
	show.setShowSeatType(type);
	
	fileShow << show.getMovieTitle() << endl;
	fileShow << show.getShowDate() << endl;
	fileShow << show.getShowSeatType() << endl;
	
	fileShow.close();
}


bool Show::deleteShow()
{
	if (!ListFiles(getCurrentDir(), CallBackPrintf))
	{
		return false;
	}
	cout << "Choose a movie" << endl;
	string movie;
	cout << "Enter movie name: ";
	cin >> movie;

	if (!FindFile(getCurrentDir(), movie))
	{
		clearscreen();
		cout << "Movie doesn't exist" << endl;
		Sleep(1000);
		return false;
	}
	clearscreen();
	if (!ListFiles(getCurrentShowDir(), CallBackPrintf))
	{
		clearscreen();
		return false;
	}
	clearscreen();
	cout << "Choose a show to delete" << endl;
	if (!ListFiles(getCurrentShowDir(), CallBackPrintf))
	{
		clearscreen();
		return false;
	}

	std::string fileShow;
	cout << "Enter show name to delete: ";
	std::cin >> fileShow;
	fileShow.insert(0, getCurrentShowDir());
	fileShow += ".txt";
	return DeleteFileA(fileShow.c_str());
}
void Show::updateShow()
{
	cout << endl << "Shows" << endl;
	if (!ListFiles(getCurrentShowDir(), CallBackPrintf))
	{
		clearscreen();
		return;
	}
	cout << endl << "Choose which show you want to update" << endl;
	string updatedShow;
	cin >> updatedShow;

	string filePath;

	if (current == 0)
		filePath = dirShowCinemaCity + updatedShow + ".txt";
	else if (current == 1)
		filePath = dirShowCinemaMax + updatedShow + ".txt";

	ifstream inFile(filePath);
	if (!inFile.is_open())
	{
		cout << "Show not found!" << endl;
		return;
	}

	string currentTitle, currentDate, currentSeat;
	getline(inFile, currentTitle);
	getline(inFile, currentDate);
	getline(inFile, currentSeat);
	inFile.close();
	clearscreen();
	cout << "Current information:" << endl;
	cout << "Title: " << currentTitle << endl;
	cout << "Date: " << currentDate << endl;
	cout << "Seat Type: " << currentSeat << endl;

	cout << "Enter new title (or press Enter to keep it): " << endl;
	cin.ignore();
	string updatedTitle;
	getline(cin, updatedTitle);
	if (updatedTitle.empty()) updatedTitle = currentTitle;

	cout << "Enter new date (or press Enter to keep it): ";
	string updatedDate;
	getline(cin, updatedDate);
	if (updatedDate.empty()) updatedDate = currentDate;

	cout << "Enter new seat type (Silver, Gold, Platinum) (or press Enter to keep it): ";
	string updatedSeat;
	getline(cin, updatedSeat);
	if (updatedSeat.empty()) updatedSeat = currentSeat;


	if (updatedTitle != currentTitle)
	{
		remove(filePath.c_str());
		if (current == 0)
			filePath = dirShowCinemaCity + updatedTitle + ".txt";
		else if (current == 1)
			filePath = dirShowCinemaMax + updatedTitle + ".txt";
	}

	ofstream outFile(filePath);
	outFile << updatedTitle << endl;
	outFile << updatedDate << endl;
	outFile << updatedSeat << endl;
	outFile.close();

	cout << "Show updated successfully!" << endl;
}