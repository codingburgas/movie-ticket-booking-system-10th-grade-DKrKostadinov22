#include "Movie.h"
#include <fstream>
#include <string>
#include <iostream>
#include "misc.h"
#include <Windows.h>
using namespace std;
void Movie::addMovie()
{
	ofstream createFile;

	Movie movie;
	cout << "Enter movie title: "; cin >> movie.title; cout << endl;
	cout << "Enter movie language: "; cin >> movie.language; cout << endl;
	cout << "Enter movie genre: "; cin >> movie.genre; cout << endl;
	cout << "Enter movie releaseDate: "; cin >> movie.releaseDate; cout << endl;

	if (current == cinemaMax)
	{
		createFile.open("cinemaMax\\Movie\\Movie" + movie.title + ".txt");
	}
	else if (current == cinemaCity)
	{
		createFile.open("cinemaCity\\Movie\\Movie" + movie.title + ".txt");
	}
	createFile << movie.title << endl;
	createFile << movie.language << endl;
	createFile << movie.genre << endl;
	createFile << movie.releaseDate << endl;
}


#pragma warning(push)
#pragma warning(disable : 4996)
bool Movie::deleteMovie()
{
	char pathCinema[MAX_PATH];
	std::string pathJoin = current == cinemaMax ? dirCinemaMax + "*.txt" : dirCinemaCity + "*.txt";
	strcpy(pathCinema, pathJoin.c_str());

	WIN32_FIND_DATAA fd;

	HANDLE finder = FindFirstFileA(pathCinema, &fd);
	if (finder != INVALID_HANDLE_VALUE)
	{
		char fileMovie[MAX_PATH];
		ZeroMemory(fileMovie, MAX_PATH);
		do
		{
			if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
			}
			else
			{
				strcpy(fileMovie, fd.cFileName);
				char* pos = strchr(fileMovie, '.');
				fileMovie[pos - fileMovie] = 0;

				printf("%s\n", fileMovie);
			}
		} while (FindNextFileA(finder, &fd));
		FindClose(finder);

		ZeroMemory(fileMovie, MAX_PATH);
		pathCinema[strrchr(pathCinema, '*') - pathCinema] = 0;

		printf("\nEnter which movie to delete:\n");

		char name[80];
		getchar();
		fgets(name, sizeof(name) - 1, stdin);
		name[strcspn(name, "\n")] = 0;
		strcpy(fileMovie, pathCinema);
		strcat(fileMovie, name);
		strcat(fileMovie, ".txt");
		return DeleteFileA(fileMovie);
	}
	return false;
}
#pragma warning(pop)