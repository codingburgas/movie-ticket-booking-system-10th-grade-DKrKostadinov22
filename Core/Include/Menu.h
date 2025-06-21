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
};

void menuChoice();
void chooseCinema();

