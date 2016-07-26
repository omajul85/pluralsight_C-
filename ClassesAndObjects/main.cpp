#include <iostream>
//#include "Person.h"
#include "Tweeter.h"
#include <iostream>

using namespace std;

int main()
{
    Person p1("laura", "snowise", 2);
    {
        Tweeter t1("omar", "alvarez", 1, "@omajul");
    }
    std::cout << "After innermost block" << std::endl;

    return 0;
}
