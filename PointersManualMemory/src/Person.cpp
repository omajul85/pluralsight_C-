#include "Person.h"
#include "Resource.h"
#include <iostream>

using namespace std;

// Constructor with initializer syntax (pResource is optional)
Person::Person(string first, string last, int n) :
    firstname(first), lastname(last), id(n), pResource(NULL)
{
    cout << "Constructing " << getName() << endl;
}

// Copy constructor: The pResource requires a new pointer
Person::Person(const Person& p) :
    firstname(p.firstname), lastname(p.lastname), id(p.id), pResource(new Resource(p.pResource->getName()))
{
}

// Asignment operator
Person& Person::operator=(const Person& p) {
    firstname = p.firstname;
    lastname = p.lastname;
    id = p.id;
    delete pResource;
    pResource = new Resource(p.pResource->getName());
    return *this; // We return a reference, that is why we need to use *
}

string Person::getName() const {
    return firstname + " " + lastname;
}

// We can use private attributes directly for comparison because the operators are member functions
bool Person::operator<(const Person& p) const {
    return id < p.id;
}

bool Person::operator<(int i) const {
    return id < i;
}

bool operator<(int i, const Person& p) {
    // We use getId() because this operator is not a member function. Must use a public method.
    // return i < p.getId();

    // I can use the id attribute directly if the operator is declared as friend!
    return i < p.id;
}

void Person::addResource(){
    //This resource created here must be deleted if a new one is added or when calling the destructor of Resource
    delete pResource;
    pResource = new Resource("Resource for " + getName());
}

// Destructor
Person::~Person()
{
    delete pResource;
    cout << "Destructing " << getName() << endl;
}
