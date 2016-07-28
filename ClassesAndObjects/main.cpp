#include "Person.h"
#include "Tweeter.h"
#include <iostream>
#include <string>
#include "status.h"
#include <memory>

using namespace std;

// Write the function with a placeholder
template <class T>
T max(T& a, T&b){
    return a < b? b : a;
}

int DoubleIt(const int& x){
	return x*2;
}

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
    p1.setId(69);
    cout << p1.getName() << " " << p1.getId() << endl;

    // Operator overloading
    Person p3("Kate", "Gregory", 123);
	Person p4("Someone", "Else", 456);
	cout << "p3 is ";
	if (!(p3 < p4)) // The operator < is a member function of class Person (method) taking an obj Person
		cout << "not ";
	cout << "less than p4" << endl;

	cout << "p3 is ";
	if (!(p3 < 300)) // The operator < is a member function of class Person (method) taking an int
		cout << "not ";
	cout << "less than 300" << endl;

	cout << "300 is ";
	if (!(300 < p3))
		cout << "not ";
	cout << "less than p3" << endl;

	int a(33);
	int b(44);
	string s1 = "Omar";
	string s2 = "Julian";

	cout << "max of " << a << " and " << b << " is " << max(a,b) << endl;
	cout << "max of " << s1 << " and " << s2 << " is " << max(s1,s2) << endl;
	cout << "max of " << p3.getName() << " and " << p4.getName() << " is " << max(p3,p4).getName() << endl;

	// Const

	int i = 3;
	const int ci = 3;
	i = 4;
	//ci = 4;

	int j = 10;
	int DoubleJ = DoubleIt(j);
	int DoubleTen = DoubleIt(10);

	Person Kate("Kate", "Gregory", 234);
	Kate.setId(235);
	const Person cKate = Kate;
	//cKate.SetNumber(236);
	int KateNumber = cKate.getId();

	int* pI = &i;
	const int* pII = &ci;

	Person* pKate = &Kate;
	Person Someone("Someone","Else", 345);

	const int * pcI = pI; // pointer to a const
	//*pcI = 4;
	pcI = &j;

	int * const cpI = pI; // const pointer
	*cpI = 4;
	//cpI = &j;

	const int * const crazy = pI; // const pointer to a const
	//*crazy = 4;
	//crazy = &j;
	int k = *crazy;

    return 0;
}
