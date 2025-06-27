#pragma once
#include <string>

enum currentCinema { cinemaCity, cinemaMax };
extern currentCinema current;

static const std::string dirCinemaMax = "cinemaMax\\Movie\\", dirCinemaCity = "cinemaCity\\Movie\\";
static const std::string dirShowCinemaMax = "cinemaMax\\Show\\", dirShowCinemaCity = "cinemaCity\\Show\\";
typedef bool (*typeListCallBack)(const std::string&);
void clearscreen();
bool ListFiles(const std::string& directoryPath,typeListCallBack cb = 0);
bool FindFile(const std::string& dirFile, const std::string& fname);

//current cinema dir
std::string getCurrentDir();
std::string getCurrentShowDir();
bool CallBackPrintf(const std::string& fname);

