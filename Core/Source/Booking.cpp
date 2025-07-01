#include "Menu.h"
#include "Booking.h"
#include "misc.h"
#include <windows.h>
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

bool isDigitsOnly(const string& str) {
	for (char ch : str) 
	{
		if (!isdigit(ch)) return false;
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
	cout << "From 1 to 3 - silver ticket (8lv)" << endl << "From 4 to 6 - gold ticket (10lv)" << endl << "From 7 to 10 - platinum ticket (12lv)" << endl;
	cout << "Choose place row: ";
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

	ofstream bookingFile(getCurrentDir(bookingDir) + currentUser + seatX + "_" + seatY + showName + ".txt");
	bookingFile << seatX << endl;
	bookingFile << seatY << endl;
	bookingFile << showName << endl;
	bookingFile << price << endl;
	clearscreen();
	string cardNumber;
	string cardHolderFirstName;
	string cardHolderLastName;
	string expiryDate;
	string cvv;

	cout << "You hace to pay: " << price << "lv" << endl;
	do {
		cout << "Enter your 16-digit credit card number: ";
		cin >> cardNumber;

		if (cardNumber.length() != 16 || !isDigitsOnly(cardNumber)) 
			cout << "Invalid card number! Please enter exactly 16 digits." << endl;

	} while (cardNumber.length() != 16 || !isDigitsOnly(cardNumber));

	cout << "Enter the name on the card: ";
	cin >> cardHolderFirstName >> cardHolderLastName;
	cout << "Enter expiry date (MM/YY): ";
	cin >> expiryDate;
	do {
		cout << "Enter the 3-digit CVV: ";
		cin >> cvv;

		if (cvv.length() != 3 || !isDigitsOnly(cvv)) 
			cout << "Invalid CVV! Please enter exactly 3 digits." << endl;

	} while (cvv.length() != 3 || !isDigitsOnly(cvv));

}


bool CallBackPrintfBookings(const std::string& fname)
{
	const char* p = fname.c_str();
	while (*p && ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z'))) p++;
	int len = p - fname.c_str();
	string userNameFile = fname.substr(0, len);

	if (userNameFile == currentUser)
	{
		string fileName = fname + ".txt";
		ifstream file(getCurrentDir(bookingDir) + fileName);
		string lineBuffer;//x,y,show_name,price

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
 
bool Booking::cancelBooking()
{
	clearscreen();
	ListFiles(getCurrentDir(bookingDir), CallBackPrintfBookings);
	std::string fileRow;
	std::string fileCol;
	std::string fileShow;
	std::string filePath;
	std::string fileDir;
	cout << "Enter row, col and show name to delete: " << endl;
	cout << "Enter show name: "; cin >> fileShow;
	cout << "Enter row: "; cin >> fileRow;
	cout << "Enter col: "; cin >> fileCol;
	fileDir.insert(0, getCurrentDir(bookingDir));
	filePath = fileDir + currentUser + fileRow + "_" + fileCol + fileShow + ".txt";
	return DeleteFileA(filePath.c_str());
}

static void InitSeats(char c)
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			seats[i][j] = c;
}

