#include "Menu.h"
#include "Booking.h"
#include "misc.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
static char seats[10][10] =
{
	{'O','O','O','O','O','O','O','O','O','O'},
	{'O','O','O','O','O','O','O','O','O','O'},
	{'O','O','O','O','O','O','O','O','O','O'},
	{'O','O','O','O','O','O','O','O','O','O'},
	{'O','O','O','O','O','O','O','O','O','O'},
	{'O','O','O','O','O','O','O','O','O','O'},
	{'O','O','O','O','O','O','O','O','O','O'},
	{'O','O','O','O','O','O','O','O','O','O'},
	{'O','O','O','O','O','O','O','O','O','O'},
	{'O','O','O','O','O','O','O','O','O','O'}
};
static string bookedShow;
static vector<std::pair<string, string>> bookedSeats;

static bool callBackMarkSeats(const std::string& fname)
{
	if (fname.find(currentUser) != string::npos)
	{
		ifstream file(fname);
		std::pair<string, string> seat; //first = x second = y
		getline(file, seat.first);
		getline(file, seat.second);
		string currentShow;
		getline(file, currentShow);
		if (currentShow == bookedShow)
		{
			bookedSeats.push_back(seat);
			cout << seat.first << " " << seat.second << endl;
		}
	}
	return true;
}
void Booking::makeBooking()
{
	showName = bookedShow = Customer::chooseShow(); 
	/*ofstream bookingFile(getCurrentDir(bookingDir) + currentUser + seatX + "_" + seatY + ".txt");*/
	ListFiles(getCurrentDir(bookingDir), callBackMarkSeats);

	for (const auto& seat : bookedSeats)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if(stoi(seat.first) == i && stoi(seat.second) == j)
				{
					seats[i][j] = 'X';
				}
				else
				{
					seats[i][j] = 'O';
				}
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << seats[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Choose place row: ";
	cin >> seatX;
	cout << "Choose place col: ";
	cin >> seatY;
	seats[std::stoi(seatX) - 1][stoi(seatY) - 1] = 'X';

	ofstream bookingFile(getCurrentDir(bookingDir) + currentUser + seatX + "_" + seatY + ".txt");
	bookingFile << seatX << endl;
	bookingFile << seatY << endl;
	bookingFile << showName << endl;
	bookingFile << seatVal << endl;
	clearscreen();
}
void Booking::cancelBooking()
{

}