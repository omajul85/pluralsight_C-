#include <iostream>
#include "Utility.h"

using namespace std;

int main()
{
	int i=0;
	cout << "i " << i << endl;
	i += 2;
	cout << "i " << i << endl;
	i *= 3;
	cout << "i " << i << endl;
	i -= 2;
	cout << "i " << i << endl;
	i /= 4;
	cout << "i " << i << endl;

	int j = i++; // x++, x-- Returns the OLD value
	cout << "i " << i << ", j " << j << endl;
	j = ++i; // ++x, --x Returns the NEW value
	cout << "i " << i << ", j " << j << endl;
	j = i--;
	cout << "i " << i << ", j " << j << endl;
	j = --i;
	cout << "i " << i << ", j " << j << endl;

	i = 2;
	j = 0;
	while (i<101)
		j += IsPrime(i++)?1:0; // we call the function and then we increment the value!
	cout << "I found " << j << " primes up to 100" << endl;

	return 0;
}
