#include "Person.h"

// Constructor with initializer syntax
Person::Person(std::string first, std::string last, int n) :
    firstname(first), lastname(last), id(n) {}


Person::~Person()
{
    //dtor
}
