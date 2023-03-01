#include "MovieSeries.h"
#include "Movie.h"
#include <iostream>
#include <algorithm>
MovieSeries::MovieSeries() {}
void MovieSeries::init() {
    count = 0;
}

void MovieSeries::add(Movie* movie) {
    if (count < 16) {
        movies[count] = movie;
        count++;
    } else {
        std::cout << "Error: Movie series is full" << std::endl;
    }
}
bool compareMoviesByYear(Movie* a, Movie* b) {
    return a->get_year() > b->get_year();
}

void MovieSeries::sort() {
    std::sort(movies, movies + count, compareMoviesByYear);
}

void MovieSeries::print() {
    for (int i = 0; i < count - 1; i++)
        std::cout << movies[i];
}