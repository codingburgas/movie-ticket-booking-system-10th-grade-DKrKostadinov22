#include "Misc.h"
#include <windows.h>

currentCinema current;
void clearscreen()
{
	system("cls");
}
#pragma warning(disable:4996)

bool ListFiles(const std::string& directoryPath, typeListCallBack cb )
{
    char pathCinema[MAX_PATH];
    std::string pathJoin = directoryPath + "*.txt";
    strcpy(pathCinema, pathJoin.c_str());

    WIN32_FIND_DATAA fd;
    HANDLE finder = FindFirstFileA(pathCinema, &fd);

    if (finder != INVALID_HANDLE_VALUE)
    {
        char fileMovie[MAX_PATH];
        ZeroMemory(fileMovie, MAX_PATH);

        do
        {
            if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            {
                strcpy(fileMovie, fd.cFileName);
                char* pos = strchr(fileMovie, '.');
                if (pos) fileMovie[pos - fileMovie] = 0; 

                std::string filenameOnly(fileMovie);

                if (cb && !cb(filenameOnly))    
                {
                    FindClose(finder);
                    return false;
                }
            }
        } while (FindNextFileA(finder, &fd));

        FindClose(finder);
        return true;
    }

    return false;
}
bool FindFileCallbackTarget = false;
std::string FindFileTarget;

bool FindFileCallback(const std::string& filename)
{
    if (filename == FindFileTarget)
    {
        FindFileCallbackTarget = true;
        return false;
    }
    return true;
}
bool CallBackPrintf(const std::string& fname)
{
    printf("%s\n", fname.c_str());
    return true;
}




bool FindFile(const std::string& dirFile, const std::string& fname)
{
    FindFileTarget = fname;
    FindFileCallbackTarget = false;

    ListFiles(dirFile, FindFileCallback);

    return FindFileCallbackTarget;
}
std::string getCurrentDir(currentDir dir)
{
    switch(dir)
    {
    case movieDir:
        return current == cinemaCity ? dirMovieCinemaCity : dirMovieCinemaMax;
        break;
    case showDir:
        return current == cinemaCity ? dirShowCinemaCity : dirShowCinemaMax;
        break;
    case bookingDir:
        return current == cinemaCity ? dirBookingCinemaCity : dirBookingCinemaMax;
        break;
    }
    return "";
}