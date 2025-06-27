#pragma once
#include <string>
using std::string;

class Movie
{
	string title, language, genre, releaseDate;
public:
	void addMovie();
	bool deleteMovie();

	string getTitle()
	{
		return title;
	}
	string getLanguage()
	{
		return language;
	}

	string getGenre()
	{
		return genre;
	}
	string getReleaseDate()
	{
		return releaseDate;
	}

	void setTitle(string title)
	{
		this->title = title;
	}
	void setLanguage(string languange)
	{
		this->language = languange;
	}
	void setGenre(string genre)
	{
		this->genre = genre;
	}
	void setReleaseDate(string releaseDate)
	{
		this->releaseDate = releaseDate;
	}
};