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

// We can use private attributes directly for comparison because the operators are member functions
bool Person::operator<(Person& p){
    return id < p.id;
}

bool Person::operator<(int i){
    return id < i;
}

bool operator<(int i, Person& p){
    // We use getId() because this operator is not a member function. Must use a public method.
    // return i < p.getId();

    // I can use the id attribute directly if the operator is declared as friend!
    return i < p.id;
}

// Destructor
Person::~Person()
{
    cout << "Destructing " << getName() << endl;
}
