#pragma once
class Movie {
    char name[257];
    int year;
    double score;
    int lenght;
    

  public:
    Movie();
    void set_name(const char* name);
    const char* get_name(); 
    void set_year(int year);
    int get_year();
    void set_score(double score);
    double get_score();
    void set_length(int lenght);
    int get_lenght();
    int get_passed_years();
};
int movie_compare_name(Movie& m1, Movie& m2);
int movie_compare_year(Movie& m1, Movie& m2);
int movie_compare_score(Movie& m1, Movie& m2);
int movie_compare_length(Movie& m1, Movie& m2);
int movie_compare_passed_years(Movie& m1, Movie& m2);