#include "Person.h"
#include <iostream>

using namespace std;

// Constructor with initializer syntax
Person::Person(string first, string last, int n) :
    firstname(first), lastname(last), id(n)
{
    cout << "Constructing " << getName() << endl;
}

string Person::getName(){
    return firstname + " " + lastname;
}

// Destructor
Person::~Person()
{
    cout << "Destructing " << getName() << endl;
}
