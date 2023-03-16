#define _CRT_SECURE_NO_WARNINGS
#include "MyLibrary.h"
#include <stdarg.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstring>
#include <initializer_list>
#include <algorithm>
MyLibrary::~MyLibrary() {
    delete[] books;
}

MyLibrary::MyLibrary(std::ostream& output_stream) : output_stream(output_stream), books_count(-1), books(nullptr) {
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int* books)
    : output_stream(output_stream), books_count(books_count), books(new int[books_count]) {
    for (unsigned i = 0; i < books_count; i++)
        this->books[i] = books[i];
}
MyLibrary::MyLibrary(const MyLibrary& other)
    : output_stream(other.output_stream), books_count(other.books_count), books(new int[other.books_count]) {
    for (unsigned i = 0; i < books_count; i++)
        this->books[i] = other.books[i];
}
MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max)
    : output_stream(output_stream), books_count(books_count), books(new int[books_count]) {
    srand(time(nullptr));
    for (unsigned i = 0; i < books_count; i++)
        books[i] = rand() % (int) (max - min) + min;
}

MyLibrary::MyLibrary(std::ostream& output_stream, const char* books_values)
    : output_stream(output_stream), books_count(0), books(nullptr) {
    char* s = new char[strlen(books_values) + 1];
    strcpy(s, books_values);
    char* p = strtok(s, ";");
    while (p) {
        books_count++;
        p = strtok(nullptr, ";");
    }
    delete[] s;
    s = new char[strlen(books_values) + 1];
    strcpy(s, books_values);
    books = new int[books_count];
    p = strtok(s, ";");
    int i = 0;
    while (p) {
        books[i++] = atoi(p);
        p = strtok(nullptr, ";");
    }
    delete[] s;
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, ...)
    : output_stream(output_stream), books_count(books_count), books(new int[books_count]) {
    va_list args;
    va_start(args, books_count);
    for (unsigned i = 0; i < books_count; i++)
        books[i] = va_arg(args, int);
    va_end(args);
}

MyLibrary::MyLibrary(std::initializer_list<int> v)
    : output_stream(std::cout), books_count(v.size()), books(new int[books_count]) {
    std::copy(v.begin(), v.end(), books);
}

void MyLibrary::print_books() const {
    if (books_count == -1) {
        output_stream << "Found -1 books" << std::endl;
        return;
    }

    output_stream << "Found " << books_count << " books:";

    for (unsigned i = 0; i < books_count; ++i) {
        output_stream << " " << books[i];
    }

    output_stream << std::endl;
}
void MyLibrary::update_book_id_by_index(unsigned book_index, int book_id) {
    if (book_index >= 0 && book_index < books_count) {
        books[book_index] = book_id;
    }
}
int MyLibrary::get_books_count() const {
    return books_count;
}
int MyLibrary::get_book_id_by_index(int index) const {
    if (index >= 0 && index < (int) books_count)
        return books[index];
}