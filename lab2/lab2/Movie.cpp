#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"
#include <cstring>
#include <iostream>

using namespace std;

Movie::Movie(){};
void Movie::set_name(const char* name) {
    strcpy(this->name, name);
}
const char* Movie::get_name() {
    return name;
}
void Movie::set_year(int year) {
    this->year = year;
}

int Movie::get_year() {
    return year;
}

void Movie::set_score(double score) {

    if (score > 10.0f || score < 1.0f)
        return;
    this->score = score;
}

double Movie::get_score() {
    return score;
}

void Movie::set_length(int minutes) {
    this->lenght = minutes;
}

int Movie::get_lenght() {
    return lenght;
}

int Movie::get_passed_years() {
    return 2023-year;
}

