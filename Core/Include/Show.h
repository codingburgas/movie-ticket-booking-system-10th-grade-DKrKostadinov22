#pragma once
#include <string>
using std::string;

class Show
{
	string movieTitle;
	string showTime;
	string showDate;
	string showSeatType;
public:
	void addShow();
	void deleteShow();
	void updateShow();

	string getMovieTitle()
	{
		return movieTitle;
	}
	string getShowTime()
	{
		return showTime;
	}
	string getShowDate()
	{
		return showDate;
	}
	string getShowSeatType()
	{
		return showSeatType;
	}

	void setMovieTitle(string movieTitle)
	{
		this->movieTitle = movieTitle;
	}
	void setShowTime(string showTime)
	{
		this->showTime = showTime;
	}
	void setShowDate(string showDate)
	{
		this->showDate = showDate;
	}
	void setShowSeatType(string showSeatType)
	{
		this->showSeatType = showSeatType;
	}
};