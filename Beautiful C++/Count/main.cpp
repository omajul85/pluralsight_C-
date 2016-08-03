#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    vector<int> v{ 2,7,1,6,2,-2,4,0 };

	//count how many entries have the target value (2)
	int twos = 0;
	int const target = 2;
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i] == target) {
			twos++;
		}
	}
    cout << twos << endl;

    // STL with member begin and end
    twos = count(v.begin(), v.end(), target);
    cout << twos << endl;

    // STL with non member begin and end. safest choice and a good habit
    twos = count(begin(v), end(v), target);
    cout << twos << endl;

    // Count how many entries are odd
    int odds = 0;
	for (auto elem : v) {
		if (elem % 2 != 0) {
			odds++;
		}
	}
    cout << odds << endl;

    odds = count_if(begin(v), end(v), [](int elem) { return elem % 2 != 0; });
    cout << odds << endl;

    map<int, int> monthlengths{ { 1,31 },{ 2,28 },{ 3,31 },{ 4,30 },{ 5,31 },{ 6,30 },{ 7,31 },{ 8,31 },{ 9,30 },{ 10,31 },{ 11,30 },{ 12,31 } };
	int longmonths = count_if(begin(monthlengths), end(monthlengths), [](pair<int, int> elem) { return elem.second == 31; });
    cout << longmonths << endl;

    // Are all, any, or none of the values odd? (Conclude from number of odd entries)
    bool allodd, noneodd, anyodd;
    allodd = (odds == v.size());
    noneodd = (odds == 0);
    anyodd = (odds > 0);
    cout << allodd << " - " << noneodd << " - " << anyodd << endl;

    // The same using STL header
    allodd = all_of(begin(v), end(v), [](bool n) { return n % 2 != 0; });
    noneodd = none_of(begin(v), end(v), [](bool n) { return n % 2 != 0; });
    anyodd = any_of(begin(v), end(v), [](bool n) { return n % 2 != 0; });
    cout << allodd << " - " << noneodd << " - " << anyodd << endl;


    return 0;
}
