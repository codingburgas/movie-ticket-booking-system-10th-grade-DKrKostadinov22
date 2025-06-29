#pragma once
#include <string>
using namespace std;


class Booking
{
	string seatVal, seatX, seatY, showName;
public:
	void makeBooking();
	void cancelBooking();

	string getSeatVal()
	{
		return seatVal;
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

	void setSeatVal(string seatVal)
	{
		this->seatVal = seatVal;
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