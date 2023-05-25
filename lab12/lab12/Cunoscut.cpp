#include "Cunoscut.h"

Cunoscut::Cunoscut(const std::string& nume, const std::string& numarTelefon) : Contact(nume), numarTelefon(numarTelefon) {}

std::string Cunoscut::getNumarTelefon() const {
    return numarTelefon;
}