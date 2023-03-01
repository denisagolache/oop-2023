#pragma once
#include "Movie.h"
class MovieSeries {
  private:
    int count;
    Movie* movies[16];

  public:
    MovieSeries();
    void init();
    void add(Movie* movie);
    void print();
    void sort();
};