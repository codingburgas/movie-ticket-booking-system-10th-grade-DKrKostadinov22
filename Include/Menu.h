#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Admin
{
public:
	void adminMenu();
	void adminLogIn();
	void createOrDeleteMovie();
	string username;
	string password;
};

class Customer
{
public:
	void customerMenu();
};

void clearscreen();
void menuChoice();
void chooseCinema();