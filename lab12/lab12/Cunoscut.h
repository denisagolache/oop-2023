#pragma once
#include "Contact.h"
#include <string>

class Cunoscut : public Contact {
private:
    std::string numarTelefon;

public:
    Cunoscut(const std::string& nume, const std::string& numarTelefon);

    std::string getNumarTelefon() const;
};