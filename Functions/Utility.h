#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

bool isPrime(int n);
bool isTwoMorePrime(int n); // value
bool isTwoMorePrimeRef(int& n); // reference

/* You use references:
    - When you really want to change the variable
    - When the copy is too expensive (i.e images), so you mix references with const
*/

#endif // UTILITY_H_INCLUDED
