#include "Tweeter.h"
#include <iostream>

Tweeter::Tweeter(std::string first, std::string last, int n, std::string handle) :
    Person(first, last, n), tweeterhandle(handle)
{
    std::cout << "Constructing " << tweeterhandle << std::endl;
}

Tweeter::~Tweeter()
{
    std::cout << "Destructing " << tweeterhandle << std::endl;
}
