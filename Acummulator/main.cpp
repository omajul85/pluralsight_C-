#include <iostream>
#include <string>
#include "Accum.h"

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

    return 0;
}
