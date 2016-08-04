#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

void printVector(string s, vector <int> ary){
    cout << s;
    for_each(begin(ary), end(ary), [](int i) { cout << i << " "; });
    cout << endl;
}

int main()
{
    vector<int> a{ 1, 2, 3, 4, 5};
	vector<int> b{ 1, 2, 0, 4};

	bool same = a.size() == b.size();
	for (size_t i = 0; i < a.size() && same; i++) {
		if (a[i] != b[i]) {
			same = false;
		}
	}
	cout << "with loop: " << same << endl;
	same = equal(begin(a), end(a), begin(b));
    cout << "with equal: " << same << endl;

	// Mismatch returns a pair of iterators
	auto firstchange = mismatch(begin(a), end(a), begin(b));
	int avalue = *(firstchange.first);
	int bvalue = *(firstchange.second);
	cout << "a value: " << avalue << endl;
	cout << "b value: " << bvalue << endl;

	// How long the collection stayed the same?
	auto distance = firstchange.first - begin(a);
	cout << "d = " << distance << endl;

    // Total the elements of a collection
    int total = 0;
    for (int i : a)
        total += i;
    cout << "total: " << total << endl;

    // Sum of ALL elements (+ by default)
    total = accumulate(begin(a), end(a), 0);
    cout << "total: " << total << endl;

    // Sum of EVEN elements
    total = accumulate(begin(a), end(a), 0, [](int total, int i){
        if (i % 2 == 0) return total + i; return total;
    });
    cout << "total of evens: " << total << endl;

    // Product of ALL elements
    total = accumulate(begin(a), end(a), 1, [](int total, int i){
        return total * i;
    });
    cout << "Product: " << total << endl;

    // Accumulate with strings
    vector <string> words{ "uno", "dos", "tres" };
    auto allwords = accumulate(begin(words), end(words), string{});
    cout << allwords << endl;

    // With separator ' '
    allwords = accumulate(begin(words), end(words), string{"Words:"},
    [](const string& total, string& w){ return total + " " + w; });
    cout << allwords << endl;

    string s = accumulate(begin(a), end(a), string{"The numbers are:"},
    [](const string& total, int n){ return total + " " + to_string(n); });
    cout << s << endl;

    // Initializing vector option 1
    b = a;
    for (auto it = begin(b); it != end(b); it++)
        *it = 0;
    printVector("b: ", b);

    // Initializing vector option 2
    for (auto& i : b)
        i = 1;
    printVector("b: ", b);

    // Initializing vector option 3 (we pass a reference because we want to change the value!)
    for_each(begin(b), end(b), [](int& elem) { elem = 2; });
    printVector("b: ", b);

    // Another example (not from begin to end)
    b = a;
    auto three = find(begin(b), end(b), 3);
    for_each(three, end(b), [](int& elem) { elem = 0; });
    printVector("b: ", b);

    return 0;
}
