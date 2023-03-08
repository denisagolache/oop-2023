#include <iostream>
#include "Math.h"

using namespace std;

int main() {
    cout << "Add(2, 3) = " << Math::Add(2, 3) << endl;
    cout << "Add(2, 3, 4) = " << Math::Add(2, 3, 4) << endl;
    cout << "Add(2.5, 3.7) = " << Math::Add(2.5, 3.7) << endl;
    cout << "Add(2.5, 3.7, 4.2) = " << Math::Add(2.5, 3.7, 4.2) << endl;
    cout << "Mul(2, 3) = " << Math::Mul(2, 3) << endl;
    cout << "Mul(2, 3, 4) = " << Math::Mul(2, 3, 4) << endl;
    cout << "Mul(2.5, 3.9) = " << Math::Mul(2.5, 3.7) << endl;
    cout << "Mul(2.5, 3.7, 4.2) = " << Math::Mul(2.5, 3.7, 4.2) << endl;
    const char* s1 = "trei";
    const char* s2 = "patru";
    cout << "Add(trei, patru)= " << Math::Add(s1, s2)<<endl;
    const char* s3 =nullptr;
    cout << "Add(trei,nullptr)= " << Math::Add(s1, s3) << endl;
}