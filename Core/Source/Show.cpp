#include "show.h"
#include "Misc.h"
#include <string>
#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

void Show::addShow()
{
	//1. list movies
	//2. ask which movie they would like to add a show to
	//3. enter movie name
	//4. enter show data
	//5. add show for specific movie
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
	
}