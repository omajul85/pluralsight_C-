#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
    vector<int> v{ 4, 6, 7, 6, 1, 3, -2, 0, 11, 2, 3, 2, 4, 4, 2, 4 };
	string s{ "Hello I am a sentence" };

	// Find the first 0 in the collection
	auto result = find(begin(v), end(v), 0);
	int out = *result;
	cout << out << endl;

    // Find the first 2 after the previous 0
    result = find(result, end(v), 2);
    if (result != end(v))
        out = *result;

    auto letter = find(begin(s), end(s), 'a');
    char c = *letter;
    cout << c << endl;

    // Find first odd value
    result = find_if(begin(v), end(v), [](bool n) { return n % 2 != 0; });
    cout << "First odd: " << *result << endl;

    // Find first of
    vector<int> primes{ 1,2,3,5,7,11,13 };
	result = find_first_of(begin(v), end(v), begin(primes), end(primes));
	out = *result;
	cout << out << endl;

	// Search
	vector<int> subsequence{ 2,4 };
	result = search(begin(v), end(v), begin(subsequence), end(subsequence));
	out = *result;
	result += 2;
	int four = *result;
	cout << "four = " << four << endl;

	string am = "am";
	letter = search(begin(s), end(s), begin(am), end(am));
	c = *letter;
	cout << c << " " << *(letter+5) << endl;

	// search_n
	result = search_n(begin(v), end(v), 2, 4); // args: begin, end, # of consecutive matches, target
	result--;
	int two = *result;
	cout << "two = " << two << endl;

	// adjacent find = The first 2 consecutive elements that are equal
	result = adjacent_find(begin(v), end(v));
	result -= 2;
	int three = *result;
	cout << "three = " << three << endl;

    return 0;
}
