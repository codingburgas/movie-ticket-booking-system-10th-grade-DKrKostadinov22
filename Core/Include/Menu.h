#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
using namespace std;

namespace Admin
{
	void adminMenu();
	void adminLogIn();
};

namespace Customer
{
	void customerMenu();
	void customerLogin();
	string chooseShow();
};
extern string currentUser;
void menuChoice();
void chooseCinema();