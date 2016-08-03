#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <random>
#include <string>
#include "Employee.h"

using namespace std;

void printVector(string s, vector <int> ary){
    cout << s;
    for_each(begin(ary), end(ary), [](int i) { cout << i << " "; });
    cout << endl;
}

int main()
{
    vector<int> v{ 4,1,0,1,-2,3,7,-6,2,0,0,-9,9 };
	auto v2 = v;
	printVector("original: ", v);

	// ASC
	sort(begin(v2), end(v2));
	printVector("v2: ", v2);

	// DESC
	sort(begin(v2), end(v2), [](int a, int b){ return a > b; });
	printVector("v2: ", v2);

    // DESC with abs
	sort(begin(v2), end(v2), [](int a, int b){ return abs(a) > abs(b); });
	printVector("v2: ", v2);

    // Sorting custom Objects
    vector<Employee> staff{
		{ "Kate", "Gregory", 1000 },
		{ "Omar", "Alvarez", 2000 },
		{ "Fake", "Name", 1000 },
		{ "Alan", "Turing", 5000 },
		{ "Grace", "Hopper", 2000 },
		{ "Anita", "Borg", 2000 }
	};

	//std::sort(begin(staff), end(staff)); //- only works if operator< defined for Employee

	sort(begin(staff), end(staff),
		[](Employee e1, Employee e2) {return e1.getSalary() < e2.getSalary(); });
    for_each(begin(staff), end(staff), [](Employee e) { cout << e.getSortingName() << ": " << e.getSalary() << endl; });

    sort(begin(staff), end(staff),
		[](Employee e1, Employee e2) {return e1.getSortingName() < e2.getSortingName(); });
    for_each(begin(staff), end(staff), [](Employee e) { cout << e.getSortingName() << ": " << e.getSalary() << endl; });

    // stable sort: Sort by salary and presents the repeated entries by alphabetic order
    stable_sort(begin(staff), end(staff),
		[](Employee e1, Employee e2) {return e1.getSalary() < e2.getSalary(); });
    for_each(begin(staff), end(staff), [](Employee e) { cout << e.getSortingName() << ": " << e.getSalary() << endl; });

    auto sorted = is_sorted(begin(v2), end(v2));
    cout << sorted << endl;

    sorted = is_sorted(begin(v2), end(v2), [](int a, int b){ return abs(a) > abs(b); });
    cout << sorted << endl;

    // MAX and min using function
    int high, low;
    high = *(max_element(begin(v), end(v)));
    low = *(min_element(begin(v), end(v)));
    cout << "MAX: " << high << ", min: " << low << endl;

    // MAX and min manually
    sort(begin(v2), end(v2));
    low = *(begin(v2));
    high = *(end(v2)-1); // end points PAST the end of the collection!
    cout << "MAX: " << high << ", min: " << low << endl;

    // With a sorted collection, we can use lower and upper bound to perform searches
    sort(begin(staff), end(staff),
		[](Employee e1, Employee e2) {return e1.getSortingName() < e2.getSortingName(); });
    auto p = lower_bound(begin(staff), end(staff), "Alvarez, Omar",
                         [](Employee e, string n) { return e.getSortingName() < n; });
    cout << p->getSalary() << endl;

    // Shuffle
    random_device randomdevice;
	mt19937 generator(randomdevice());

    printVector("v2 before shuffle: ", v2);
	shuffle(begin(v2), end(v2), generator);
	printVector("v2 after shuffle: ", v2);

	partial_sort(begin(v2), find(begin(v2), end(v2), 4), end(v2)); //after 4 there is no more sorting
	printVector("v2 after partial sort: ", v2);

	int breakpoint = *is_sorted_until(begin(v2), end(v2));

	vector<int> v3(3);
	partial_sort_copy(begin(v), end(v), begin(v3), end(v3));
	printVector("v3: ", v3);

	// nth_element
	v2 = {1,5,4,2,9,7,3,8,2};
	int i = *(begin(v2) + 4);
	cout << i << endl;
	nth_element(begin(v2), begin(v2)+4, end(v2));
	i = *(begin(v2) + 4);
	cout << i << endl;

    return 0;
}
