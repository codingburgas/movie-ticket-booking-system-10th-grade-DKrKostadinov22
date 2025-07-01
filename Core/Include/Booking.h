#pragma once
#include <string>
using namespace std;


class Booking
{
	string seatX, seatY, showName;
	double price;
public:
	void makeBooking();
	bool cancelBooking();
	double getprice()
	{
		return price;
	}
	string getSeatX()
	{
		return seatX;
	}
	string getSeatY()
	{
		return seatY;
	}
	string getShowName()
	{
		return showName;
	}

	void setprice(double price)
	{
		this->price = price;
	}
	void setSeatX(string seatX)
	{
		this->seatX = seatX;
	}
	void setSeatY(string seatY)
	{
		this->seatY = seatY;
	}
	void setShowName(string showName)
	{
		this->showName = showName;
	}
};