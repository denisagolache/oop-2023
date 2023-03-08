#include "canvas.h"
#include <iostream>
#include <stdarg.h>

Canvas::Canvas(int lines, int columns) {
    this->lines = lines;
    this->columns = columns;
    matrix = new char*[lines];
    for (int i = 0; i < lines; i++) {
        matrix[i] = new char[columns];
        for (int j = 0; j < columns; j++)
            matrix[i][j] = ' ';
    }
}

void Canvas::set_pixel(int x, int y, char value) {
    matrix[x][y] = value;
}

void Canvas::set_pixels(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i ++) {
        int x = va_arg(args, int);
        int y = va_arg(args, int);
        char value = va_arg(args, char);
        matrix[x][y] = value;
    }
    va_end(args);
}

void Canvas::print() const {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << '\n';
    }
}

void Canvas::clear() {
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < columns; j++)
            matrix[i][j] = ' ';
}