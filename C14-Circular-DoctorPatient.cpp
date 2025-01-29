#include <iostream>
#include "Doctor.h"
#include "Patient.h"
using namespace std;



int main() {
    //Create 3 patients and 1 doctor
    Patient* p1 = new Patient("Homer");
    Patient* p2 = new Patient("Lisa");
    Patient* p3 = new Patient("Bart");
    Patient* p4 = new Patient("Marge");

    Doctor* d1 = new Doctor("Dr. Hibbert");

    //Add patients to doctor
    d1->addPatient(p1);
    d1->addPatient(p2); 

    *d1 += p3;      //same as d1->addPatient(p3);
    *d1 += p4;      //same as d1->addPatient(p4);

    //Print patients and doctor
    cout << "p1 " << p1->toString() << endl;
    cout << "p2 " << p2->toString() << endl;
    cout << "p3 " << p3->toString() << endl;
    cout << "p4 " << p4->toString() << endl;

    cout << "d1 " << d1->toString() << endl;

    //Clean up
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete d1;
}
