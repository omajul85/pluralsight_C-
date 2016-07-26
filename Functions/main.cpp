#include <iostream>
#include "Utility.h"

using namespace std;

int main()
{
    int a;
    cout << "Enter a number: " << endl;
    cin >> a;
    if (isPrime(a))
        cout << a << " is prime" << endl;
    else
        cout << a << " is not prime" << endl;

    if (isTwoMorePrime(a))
        cout << a << "+2 is prime" << endl;
    else
        cout << a << "+2 is not prime" << endl;

    if (isTwoMorePrimeRef(a))
        cout << a << " is prime" << endl;
    else
        cout << a << " is not prime" << endl;

    return 0;
}
