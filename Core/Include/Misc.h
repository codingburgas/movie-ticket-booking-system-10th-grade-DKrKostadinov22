#pragma once
#include <string>

enum currentCinema { cinemaCity, cinemaMax };
extern currentCinema current;

static const std::string dirCinemaMax = "cinemaMax\\Movie", dirCinemaCity = "cinemaCity\\Movie";

void clearscreen();

//bool displayAllMovies();