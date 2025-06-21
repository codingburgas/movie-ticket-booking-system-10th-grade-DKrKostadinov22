#include "Misc.h"
#include <windows.h>

currentCinema current;
void clearscreen()
{
	system("cls");
}
//bool displayAllMovies()
//{
//	char pathCinema[MAX_PATH];
//	std::string pathJoin = current == cinemaMax ? dirCinemaMax + "\\*.txt" : dirCinemaCity + "\\*.txt";
//	strcpy(pathCinema, pathJoin.c_str());
//
//	WIN32_FIND_DATAA fd;
//
//	HANDLE finder = FindFirstFileA(pathCinema, &fd);
//	if (finder != INVALID_HANDLE_VALUE)
//	{
//		char fileMovie[MAX_PATH];
//		ZeroMemory(fileMovie, MAX_PATH);
//		do
//		{
//			if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
//			{
//			}
//			else
//			{
//				strcpy(fileMovie, fd.cFileName);
//				char* pos = strchr(fileMovie, '.');
//				fileMovie[pos - fileMovie] = 0;
//
//				printf("%s\n", fileMovie + 5);
//			}
//		} while (FindNextFileA(finder, &fd));
//		FindClose(finder);
//		return true;
//	}
//	return false;
//}