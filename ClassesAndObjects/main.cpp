#include "Person.h"
#include "Tweeter.h"
#include <iostream>
#include <string>
#include "status.h"

using namespace std;

// Write the function with a placeholder
template <class T>
T max(T& a, T&b){
    return a < b? b : a;
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

    return 0;
}
