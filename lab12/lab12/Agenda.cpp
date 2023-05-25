#include "Agenda.h"
#include <algorithm>

Contact* Agenda::cautareContact(const std::string& nume) {
    auto it = std::find_if(contacte.begin(), contacte.end(), [&nume](const Contact* contact) {
        return contact->getNume() == nume;
        });

    if (it != contacte.end()) {
        return *it;
    }

    return nullptr;
}

std::vector<Prieten*> Agenda::listaPrieteni() {
    std::vector<Prieten*> prieteni;

    for (const auto& contact : contacte) {
        if (dynamic_cast<Prieten*>(contact)) {
            prieteni.push_back(dynamic_cast<Prieten*>(contact));
        }
    }

    return prieteni;
}

void Agenda::stergereContact(const std::string& nume) {
    contacte.erase(std::remove_if(contacte.begin(), contacte.end(), [&nume](const Contact* contact) {
        return contact->getNume() == nume;
        }), contacte.end());
}

void Agenda::adaugareContact(Contact* contact) {
    contacte.push_back(contact);
}