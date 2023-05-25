#pragma once
#include "Contact.h"
#include "Prieten.h"
#include <vector>

class Agenda {
private:
    std::vector<Contact*> contacte;

public:
    Contact* cautareContact(const std::string& nume);
    std::vector<Prieten*> listaPrieteni();
    void stergereContact(const std::string& nume);
    void adaugareContact(Contact* contact);
};
