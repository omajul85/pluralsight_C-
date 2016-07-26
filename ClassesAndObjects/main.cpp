#include <iostream>
//#include "Person.h"
#include "Tweeter.h"
#include <iostream>
#include "status.h"

using namespace std;

int main()
{
    Person p1("laura", "snowise", 2);
    {
        Tweeter t1("omar", "alvarez", 1, "@omajul");
    }
    cout << "After innermost block" << endl;

    Status s = Pending;
    s = Approved;

    cout << "Status = " << s << endl;

    return 0;
}
