#include <iostream>
#include <string>
#include "Accum.h"
#include "Person.h"

using namespace std;

int main()
{
    Accum<int> x(0);
    x += 3;
    x += 7;
    cout << x.getTotal() << endl;

    Accum<string> s("");
    s += "hello ";
    s += "world!";
    cout << s.getTotal() << endl;

    // The examples below will cause compilation problems

    // x += "word"; Invalid conversion from 'const char*' to 'int'
    // s += 1; Invalid conversion from 'int' to 'const char*'

    // Template specialization example (for class Person)
    Accum<Person> people(0);
    Person p1("omar", "alvarez", 123);
    Person p2("laura", "snowise", 456);
    people += p1;
    people += p2;
    cout << people.getTotal() << endl;

    return 0;
}
