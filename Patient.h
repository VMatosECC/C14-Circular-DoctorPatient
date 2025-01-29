#pragma once
using namespace std;
//--------------------Patient.h--------------------
class Doctor;   //forward reference

class Patient
{
public:
    string pname;   
    Doctor* dptr;

    Patient(string pname = "n.a.");
    ~Patient();

    void setDoctor(Doctor* d);
    void print();
};
//--------------------Patient.cpp IMPLEMENTATION --------------------
#include "Doctor.h"
//#include "Patient.h"

Patient::Patient(string pname) {
    this->pname = pname;
    std::cout << this << " Patient created" << std::endl;
}

Patient::~Patient() {
    std::cout << this << " Patient destroyed" << std::endl;
    cout << endl;
}

void Patient::setDoctor(Doctor* d) {
    dptr = d;
}

void Patient::print() {
    std::cout << this << " Patient[ ";
    std::cout << "Name: " << pname;
    std::cout << ", Doctor: " << dptr->docName << " ]" << std::endl;
    cout << endl;
}