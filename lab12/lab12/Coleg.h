#pragma once
#include "Contact.h"
#include <string>

class Coleg : public Contact {
private:
    std::string numarTelefon;
    std::string firma;
    std::string adresa;

public:
    Coleg(const std::string& nume, const std::string& numarTelefon, const std::string& firma, const std::string& adresa);

    std::string getNumarTelefon() const;
    std::string getFirma() const;
    std::string getAdresa() const;
};