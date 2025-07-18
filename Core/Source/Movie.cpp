#include "Movie.h"
#include <fstream>
#include <string>
#include <iostream>
#include "misc.h"
#include <Windows.h>
using namespace std;
void Movie::addMovie()
{
	clearscreen();
	ofstream createFile;

	Movie movie;
	cout << "Enter movie title: "; cin >> movie.title; cout << endl;
	cout << "Enter movie language: "; cin >> movie.language; cout << endl;
	cout << "Enter movie genre: "; cin >> movie.genre; cout << endl;
	cout << "Enter movie releaseDate: "; cin >> movie.releaseDate; cout << endl;

	createFile.open(getCurrentDir(movieDir) + movie.title + ".txt");

	createFile << movie.title << endl;
	createFile << movie.language << endl;
	createFile << movie.genre << endl;
	createFile << movie.releaseDate << endl;

	createFile.close();
}

bool Movie::deleteMovie()
{	
	clearscreen();
	printf("\n\nEnter which movie to delete:\n\n");
	if (!ListFiles(getCurrentDir(movieDir),CallBackPrintf))
	{
		return false;
	}	
	
	std::string fileMovie; 
	std::cin >> fileMovie;
	fileMovie.insert(0, getCurrentDir(movieDir));
	fileMovie += ".txt";
	return DeleteFileA(fileMovie.c_str());
}

