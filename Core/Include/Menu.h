#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
using namespace std;

class Admin
{
public:
	void adminMenu();
	void adminLogIn();
};

class Customer
{
public:
	void customerMenu();
	void customerLogin();
	void chooseShow();
};

void menuChoice();
void chooseCinema();

