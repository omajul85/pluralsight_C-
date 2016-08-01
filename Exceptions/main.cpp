#include <iostream>
#include <vector>
#include <stdexcept>
#include "Person.h"
#include "Noise.h"

using namespace std;

int main()
{
    /*
    - Wrap code that might throw an exception in a try block
    - Try/catch as close to the problem as possible
    - Add one or more catch blocks after the try
    - Catch more specific exceptions first try
    - Catch exceptions by reference
    */

    Noise n1("Beep 1");
    try {
        vector <int> v;
        v.push_back(1);
        Noise n2("Bloop 2");
        Person p("neron", "navarrete", 0);
        int j = v.at(99);
    } catch (out_of_range& e) {
        cout << "out of range exception: " << e.what() << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
