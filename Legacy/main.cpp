#include <iostream>
#include "Point.h"
#include "Functions.h"
#include "Strings.h"

using namespace std;
typedef unsigned long DWORD;

int main()
{
    int i1=7;
	long l1=3L;
	DWORD d1=13;
	//d1 = "hello";
	cout << i1 << " " << l1 << " "<< d1 << endl;
	KPoint p;
	p.x=2;
	p.y=3;
	cout << p.x << " - " << p.y << endl;

	// Pointer to function
	int i2 = Change(i1);
	int i3 = Change((int)l1);
	cout << i2 << " - " << i3 << endl;

	int i4 = ManipulateUtility(5);
	cout << i4 << endl;

	UseSomething(&i1);
	UseSomething(&(p.x));
	UseSomething(&p);
	//UseSomething(Change);

	arrays();

	stringdemo();

    return 0;
}
