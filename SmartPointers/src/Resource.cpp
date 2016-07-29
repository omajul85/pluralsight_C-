#include "Resource.h"
#include <iostream>
#include <string>

using namespace std;

Resource::Resource(string n) : name(n)
{
    cout << "Constructing " << name << endl;
}

Resource::~Resource()
{
    cout << "Destructing " << name << endl;
}
