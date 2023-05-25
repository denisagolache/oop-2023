#include "Coleg.h"

Coleg::Coleg(const std::string& nume, const std::string& numarTelefon, const std::string& firma, const std::string& adresa)
    : Contact(nume), numarTelefon(numarTelefon), firma(firma), adresa(adresa) {}

std::string Coleg::getNumarTelefon() const {
    return numarTelefon;
}

std::string Coleg::getFirma() const {
    return firma;
}

std::string Coleg::getAdresa() const {
    return adresa;
}