#pragma once
#include <string>
enum class TipContact {
    Prieten,
    Cunoscut,
    Coleg
};

class Contact {
protected:
    std::string nume;

public:
    Contact(const std::string& nume);
    virtual ~Contact();

    std::string getNume() const;
};
