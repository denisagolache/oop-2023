#include "Prieten.h"

Prieten::Prieten(const std::string& nume, const std::string& dataNastere, const std::string& numarTelefon, const std::string& adresa)
    : Contact(nume), dataNastere(dataNastere), numarTelefon(numarTelefon), adresa(adresa) {}

std::string Prieten::getDataNastere() const {
    return dataNastere;
}

std::string Prieten::getNumarTelefon() const {
    return numarTelefon;
}

std::string Prieten::getAdresa() const {
    return adresa;
}