#pragma once
#include <string>
using std::string;

class Show
{
	string movieTitle;
	string showDate;
	string showSeatType;
public:
	void addShow();
	bool deleteShow();
	void updateShow();

	string getMovieTitle()
	{
		return movieTitle;
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
	void setShowDate(string showDate)
	{
		this->showDate = showDate;
	}
	void setShowSeatType(string showSeatType)
	{
		this->showSeatType = showSeatType;
	}
};