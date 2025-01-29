#pragma once
using namespace std;
//--------------------Patient.h--------------------
class Doctor;   //forward reference

class Patient
{
public:
    string  pname;   
    Doctor* dptr;

    Patient(string pname = "n.a.");
    ~Patient();

    void setDoctor(Doctor* d);
    string toString();
};
//--------------------Patient.cpp IMPLEMENTATION --------------------
#include "Doctor.h"

Patient::Patient(string pname) {
    this->pname = pname;
    cout << this << " Patient created " << pname << endl;
}

Patient::~Patient() {
    cout << this << " Patient destroyed " << pname << endl;
}

void Patient::setDoctor(Doctor* d) {
    dptr = d;
}


string Patient::toString() {
    stringstream sout;
    sout << this << " Patient[ ";
    sout << "Name: " << pname;
    sout << ", Doctor: " << dptr->docName << " ]" << endl;
    return sout.str();
}