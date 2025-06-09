#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <windows.h> 
using namespace std;

enum currentCinema{cinemaCity, cinemaMax}; 
extern currentCinema current;

class Admin
{
public:
	void adminMenu();
	void adminLogIn();
	void addMovie();
	void addShow();
	void deleteShow();
	void updateShow();
};

class Customer
{
public:
	void customerMenu();
};

struct Movie
{
	string title, language, genre;
	string releaseDate;

};


void clearscreen();
void menuChoice();
void chooseCinema();