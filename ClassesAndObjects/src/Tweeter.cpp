#include "Tweeter.h"
#include <iostream>

using namespace std;

Tweeter::Tweeter(string first, string last, int n, string handle) :
    Person(first, last, n), tweeterhandle(handle)
{
    cout << "Constructing " << tweeterhandle << endl;
}

Tweeter::~Tweeter()
{
    cout << "Destructing " << tweeterhandle << endl;
}
