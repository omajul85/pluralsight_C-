#include <iostream>
#include "Person.h"

using namespace std;

int main()
{
    // Because of the scope, p1 will be destructed first
    {
        Person p1("omar", "alvarez", 1);
    }
    Person p2("laura", "snowise", 2);
    return 0;
}
