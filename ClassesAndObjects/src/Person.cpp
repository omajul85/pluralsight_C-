#include "Person.h"
#include <iostream>

using namespace std;

// Constructor with initializer syntax
Person::Person(string first, string last, int n) :
    firstname(first), lastname(last), id(n)
{
    cout << "Constructing " << firstname << " " << lastname << endl;
}

// Destructor
Person::~Person()
{
    cout << "Destructing " << firstname << " " << lastname << endl;
}
