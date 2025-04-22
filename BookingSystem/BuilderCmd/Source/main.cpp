#include "Menu.h"

int main()
{
	ifstream checkFile("Users\\admin_credentials.txt");
	if (!checkFile.is_open())
	{
		ofstream createFile("Users\\admin_credentials.txt");
		createFile << "admin" << endl;
		createFile << "admin" << endl;
		createFile.close();
	}
	else
	{
		checkFile.close();
	}
	menuChoice();
}