#include "Person.h"
#include <iostream>

// Constructor with initializer syntax
Person::Person(std::string first, std::string last, int n) :
    firstname(first), lastname(last), id(n)
{
    std::cout << "Constructing " << firstname << " " << lastname << std::endl;
}

// Destructor
Person::~Person()
{
    std::cout << "Destructing " << firstname << " " << lastname << std::endl;
}
