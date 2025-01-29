#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//--------------------Doctor.h--------------------
class Patient;   //forward reference
class Doctor
{
public:
    string docName;
    vector<Patient*> vp;
    Doctor(string dname);
    ~Doctor();

    Doctor& operator+=(Patient* p);

    void addPatient(Patient* p);
    void print();
};
//--------------------Doctor.cpp IMPLEMENTATION --------------------
//#include "Doctor.h"
#include "Patient.h"

Doctor::Doctor(string dname) : docName(dname) {
    vp.clear();
    std::cout << this << " Doctor created" << std::endl;
}

Doctor::~Doctor() {
    std::cout << this << " Doctor destroyed" << std::endl;
    cout << endl;
}

// Why the reference Doctor& ? --------------------------------------
// Standard Practice: It is a common practice in C++ to return 
// a reference from compound assignment operators (like +=, -=, etc.) 
// to allow for chaining and to avoid unnecessary copies.
Doctor& Doctor::operator+=(Patient* p) {
    addPatient(p);
    return *this;
}
void Doctor::addPatient(Patient* p) {
    p->setDoctor(this);
    vp.push_back(p);
}

void Doctor::print() {
    std::cout << endl << this << " Doctor[ ";
    std::cout << "Name: " << docName;
    std::cout << ", Patients: " << vp.size() << " ]" << std::endl;
    for (int i = 0; i < vp.size(); i++) {
        std::cout << "\tPatient " << i << ": " << vp[i]->pname << endl;
    }
    cout << endl;
}