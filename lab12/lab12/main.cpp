#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Agenda.h"
#include "Prieten.h"
#include "Cunoscut.h"
#include "Coleg.h"

int main() {
   
    Contact* contact1 = new Prieten("Ion Popescu", "01/01/1990", "123456789", "Adresa 1");
    Contact* contact2 = new Cunoscut("Maria Ionescu", "987654321");
    Contact* contact3 = new Coleg("Ana Georgescu", "555555555", "Compania X", "Adresa 2");


    Agenda agenda;

  
    agenda.adaugareContact(contact1);
    agenda.adaugareContact(contact2);
    agenda.adaugareContact(contact3);

    
    Contact* cautat = agenda.cautareContact("Maria Ionescu");
    if (cautat != nullptr) {
        std::cout << "Contactul " << cautat->getNume() << " a fost gasit.\n";
    }
    else {
        std::cout << "Contactul nu a fost gasit.\n";
    }

  
    std::vector<Prieten*> prieteni = agenda.listaPrieteni();
    std::cout << "Lista de prieteni:\n";
    for (const auto& prieten : prieteni) {
        std::cout << "- " << prieten->getNume() << ", Telefon: " << prieten->getNumarTelefon() << "\n";
    }

    
    agenda.stergereContact("Ion Popescu");

    delete contact1;
    delete contact2;
    delete contact3;

    return 0;
}
