#pragma once
#include "Contact.h"
#include <string>

class Prieten : public Contact {
private:
    std::string dataNastere;
    std::string numarTelefon;
    std::string adresa;

public:
    Prieten(const std::string& nume, const std::string& dataNastere, const std::string& numarTelefon, const std::string& adresa);

    std::string getDataNastere() const;
    std::string getNumarTelefon() const;
    std::string getAdresa() const;
};