#include "Menu.h"
#include "Booking.h"
#include "misc.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
static const double silverTicket = 8;
static const double goldTicket = 10;
static const double platinumTicket = 12;
static char seats[10][10];
static string bookedShow;
static vector<std::pair<string, string>> bookedSeats;
static void InitSeats(char);

static bool callBackMarkSeats(const std::string& fname)
{
	string tmpFname = getCurrentDir(bookingDir) + fname + ".txt";
	if (tmpFname.find(currentUser) != string::npos)
	{
		ifstream file(tmpFname);
		std::pair<string, string> seat; //first = x second = y
		getline(file, seat.first);
		getline(file, seat.second);
		string readShow;
		getline(file, readShow);

		if (readShow == bookedShow)
		{
			bookedSeats.push_back(seat);	
		}
		file.close();
	}
	return true;
}
void Booking::makeBooking()
{
	InitSeats('O');

	showName = bookedShow = Customer::chooseShow(); 	
	ListFiles(getCurrentDir(bookingDir), callBackMarkSeats);
 	
	for (const auto& seat : bookedSeats)
	{
		seats[std::stoi(seat.first) - 1][std::stoi(seat.second) - 1] = 'X';
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << seats[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Choose place row: " << endl;
	cout << "From 1 to 3 - silver ticket (8lv)" << endl << "From 4 to 6 - gold ticket (10lv)" << endl << "From 7 to 10 - platinum ticket (12lv)" << endl;
	cin >> seatX;
	if (stoi(seatX) >= 0 && stoi(seatX) <= 2)
		price = silverTicket;
	else if (stoi(seatX) >= 3 && stoi(seatX) <= 5)
		price = goldTicket;
	else
		price = platinumTicket;

	cout << "Choose place col: ";
	cin >> seatY;
	seats[std::stoi(seatX) - 1][stoi(seatY) - 1] = 'X';

	ofstream bookingFile(getCurrentDir(bookingDir) + currentUser + seatX + "_" + seatY + ".txt");
	bookingFile << seatX << endl;
	bookingFile << seatY << endl;
	bookingFile << showName << endl;
	bookingFile << price << endl;
	clearscreen();
}


bool CallBackPrintfBookings(const std::string& fname)
{
	//fname -> Dani1_1
	const char* p = fname.c_str();
	while (*p && ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z'))) p++;
	int len = p - fname.c_str();
	string userNameFile = fname.substr(0, len);

	if (userNameFile == currentUser)
	{
		string fileName = fname + ".txt";
		ifstream file(getCurrentDir(bookingDir) + fileName);
		string lineBuffer;//x,y,show_name,seatval

		int i = 0;
		const std::string fields[] = { "Seat Row","Seat Column","Show Name","Price" };
		cout << string(30, '-') << endl;
		while (getline(file, lineBuffer))
		{
			cout << fields[i++] << ": " <<  lineBuffer << endl;
		}
		cout << string(30, '-') << endl;
		i = 0;
	}
	return true;
}

void Booking::cancelBooking()
{
	clearscreen();
	ListFiles(getCurrentDir(bookingDir), CallBackPrintfBookings);
}
static void InitSeats(char c)
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			seats[i][j] = c;
}