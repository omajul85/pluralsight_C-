#include <iostream>
#include "Utility.h"

bool isPrime(int n){

    bool prime = true;
    for (int i = 2; i <= n/i; i++){
        int factor = n/i;
        if (factor * i == n) {
            std::cout << "factor found " << factor << std::endl;
            prime = false;
            break;
        }
    }
    return prime;
}

bool isTwoMorePrime(int n){
    n += 2;
    return isPrime(n);
}

bool isTwoMorePrimeRef(int& n){
    n += 2;
    return isPrime(n);
}
