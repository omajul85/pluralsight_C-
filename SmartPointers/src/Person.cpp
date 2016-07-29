#include "Person.h"
#include "Resource.h"
#include <iostream>
#include <memory>

using namespace std;

// Constructor with initializer syntax (pResource is optional)
Person::Person(string first, string last, int n) :
    firstname(first), lastname(last), id(n)
{
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
    //This resource created here must be reset if a new one is added (decrements the reference count).
    // If count == 0, it will delete the resource
    pResource.reset();
    pResource = std::make_shared<Resource>("Resource for " + getName());
}
