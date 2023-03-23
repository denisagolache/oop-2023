#include "complex.h"
#include <cmath>
#include <iostream>
Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return Complex(real(), -imag());
    ;
}

Complex& Complex::operator()(double real, double imag) {
    real_data = real;
    imag_data = imag;
    return *this;
}

Complex& Complex::operator++() {
    ++real_data;
    return *this;
}

Complex& Complex::operator++(int) {
    Complex tmp(*this);
    ++(*this);
    return tmp;
}

Complex& Complex::operator--() {
    --real_data;
    return *this;
}

Complex& Complex::operator--(int) {
    Complex tmp(*this);
    --(*this);
    return tmp;
}

Complex operator+(const Complex& l, const Complex& r) {
    double x = l.real() + r.real();
    double i = l.imag() + r.imag();
    Complex result(x, i);
    return result;
}

Complex operator+(const Complex& l, double r) {
    Complex result(l.real()+r, l.imag());
    return  result;
}

Complex operator+(double l, const Complex& r) {
   
    return r + l;
}

Complex operator-(const Complex& l, const Complex& r) {
    double x = l.real() - r.real();
    double i = l.imag() - r.imag();
    Complex result(x, i);
    return result;
}

Complex operator-(const Complex& l, double r) {
    return Complex(l.real() - r, l.imag());
}

Complex operator-(double l, const Complex& r) {
    return Complex(l - r.real(), -r.imag());
}

Complex operator*(const Complex& l, const Complex& r) {
    double x = l.real() * r.real()-l.imag() * r.imag();
    double i = l.real() * r.imag() + l.imag() * r.real();
    Complex result(x, i);
    return result;
}
Complex operator*(const Complex& l, double r) {
    return Complex(l.real()* r, l.imag() * r);
}
Complex operator*(double l, const Complex& r) {
    return r * l;
}

Complex operator-(const Complex& obj) {
    return Complex(-obj.real(), -obj.imag());
}

bool operator==(const Complex& l, const Complex& r) {
    return l.real() == r.real() && l.imag() == r.imag();
}

bool operator!=(const Complex& l, const Complex& r) {
    return !(l == r);
}

std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    out << complex.real() << ((complex.imag() >= 0) ? "+" : "-") << std::abs(complex.imag()) << "i";
    return out;
}