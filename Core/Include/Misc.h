#pragma once
#include <string>

enum currentCinema { cinemaCity, cinemaMax };
extern currentCinema current;
enum currentDir {movieDir, showDir, bookingDir};


 const std::string dirMovieCinemaMax = "cinemaMax\\Movie\\", dirMovieCinemaCity = "cinemaCity\\Movie\\";
 const std::string dirShowCinemaMax = "cinemaMax\\Show\\", dirShowCinemaCity = "cinemaCity\\Show\\";
 const std::string dirBookingCinemaMax = "cinemaMax\\Booking\\", dirBookingCinemaCity = "cinemaCity\\Booking\\";
typedef bool (*typeListCallBack)(const std::string&);
void clearscreen();
bool ListFiles(const std::string& directoryPath,typeListCallBack cb = 0);
bool FindFile(const std::string& dirFile, const std::string& fname);

//current cinema dir
std::string getCurrentDir(currentDir dir);

bool CallBackPrintf(const std::string& fname);

