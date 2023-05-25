#include "Contact.h"

Contact::Contact(const std::string& nume) : nume(nume) {}

Contact::~Contact() {}

std::string Contact::getNume() const {
    return nume;
}