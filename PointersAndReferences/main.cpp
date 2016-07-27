#include <iostream>
#include "Person.h"
#include <string>

using namespace std;

int main()
{
    // Pointers

    int a=3;
	cout << "a is " << a << endl ;
	int* pA = &a;
	*pA = 4;
	cout << "a is " << a << endl;
	int b = 100;
	pA = &b;
	(*pA)++;
	cout << "a " << a << ", *pA " << *pA << endl;

	Person Kate("Kate", "Gregory", 234);
	Person* pKate = &Kate;
	(*pKate).setId(235);
	cout << "Kate: " << Kate.getName() << " " << Kate.getId() << endl;
	cout << "pKate: " << pKate->getName() << " " << pKate->getId() << endl;

    // References

	int& rA = a;
	rA = 5;
	cout << "a is " << a << endl;

	Person& rKate = Kate;
	rKate.setId(345);
	cout << "rKate: " << rKate.getName() << " " << rKate.getId() << endl;

	int* badPointer = 0;
	if (badPointer){
        *badPointer = 3;
        cout << *badPointer << endl;
	}
    //References has to be initialized!
    //	int& badReference;
    //	badReference = 3;
    //	cout << badReference;

    return 0;
}
