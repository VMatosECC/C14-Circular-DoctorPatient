#pragma once
#include <iostream>
#include <sstream>
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
    Doctor(string dname = "Dr. House");
    ~Doctor();

    Doctor& operator+=(Patient* p);

    void addPatient(Patient* p);
    string toString();
};
//--------------------Doctor.cpp IMPLEMENTATION --------------------
//#include "Doctor.h"
#include "Patient.h"

Doctor::Doctor(string dname) : docName(dname) {
    vp.clear();
    cout << this << " Doctor created: " << dname << endl;
}

Doctor::~Doctor() {
    cout << this << " Doctor destroyed: " << docName << endl;
}

// Why the reference Doctor& ? --------------------------------------
// Standard Practice: It is a common practice in C++ to return 
// a reference from compound asoutignment operators (like +=, -=, etc.) 
// to allow for chaining and to avoid unnecesoutary copies.
// -------------------------------------------------------------------
Doctor& Doctor::operator+=(Patient* p) {
    addPatient(p);
    return *this;
}
void Doctor::addPatient(Patient* p) {
    p->setDoctor(this);
    vp.push_back(p);
}

string Doctor::toString() {
    stringstream sout;
    sout << this << " Doctor[ ";
    sout << "Name: " << docName;
    sout << ", Patients: " << vp.size() << " ]" << endl;
    for (int i = 0; i < vp.size(); i++) {
        sout << "\tPatient " << i << ": " << vp[i]->pname << endl;
    }
    sout << endl;
    return sout.str();
}

