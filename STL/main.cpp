#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "Person.h"

using namespace std;

void print(int i){
    cout << i << " ";
}

bool odd(int i){
    return i % 2;
}

int main()
{
    // VECTOR

    vector<int> v;
    v.push_back(10);
    v.push_back(7);
    v.push_back(88);
    v.push_back(99);

    // Print the vector in normal order using an iterator
    for (auto i = v.begin(); i != v.end(); i++)
        cout << *i << " ";
    cout << endl;

    // Using for_each and a tiny function
    cout << "Printed with tiny function: ";
    for_each(v.begin(), v.end(), print);
    cout << endl;

    // Using for_each and a lambda
    cout << "Printed with lambda: ";
    for_each(v.begin(), v.end(),
             [](int i){
                cout << i << " ";
             });
    cout << endl;

    cout << "Sorted content ov v: ";
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), print);
    cout << endl;

    cout << "Odd elements of v: ";
    auto o = find_if(v.begin(), v.end(), odd);
    while(o != v.end()){
        cout << *o << " ";
        o = find_if(++o, v.end(), odd);
    }
    cout << endl;

    // Print the vector in reverse order using an iterator
    for (auto i = v.rbegin(); i != v.rend(); i++)
        cout << *i << " ";
    cout << endl;

    vector<Person> people;
    Person p1("omar", "alvarez", 123);
    Person p2("juana","valentina",456);
    people.push_back(p1);
    people.push_back(p2);

    // Print the vector in reverse order using an iterator (ip is a pointer)
    for (auto ip = people.begin(); ip != people.end(); ip++)
        cout << ip->getId() << " ";
    cout << endl;

    // MAP

    map<int,Person> people_map;
    // Adding Persons using [] notation (did not work)
//    people_map[p1.getId()] = p1;
//    people_map[p2.getId()] = p2;

    // Adding people using pair notation
    Person p3("luis", "daniel", 124);
    pair<int,Person> pair1(p1.getId(), p1);
    pair<int,Person> pair2(p2.getId(), p2);
    pair<int,Person> pair3(p3.getId(), p3);
    people_map.insert(pair1);
    people_map.insert(pair2);
    people_map.insert(pair3);

    // first => key (int), second => value (Person)
    for (auto ip = people_map.begin(); ip != people_map.end(); ip++)
        cout << ip->first << " " << ip->second.getName() << " ";
    cout << endl;

    // Find elements in the map
    auto found = people_map.find(124);
    cout << "Found: " << found->first << " " << found->second.getName() << endl;

    // Finding Persons using [] notation (did not work)
//    string who = people_map[123].getName();
//    cout << "Who? " << who << endl;

    // String
    int tam = p3.getName().size();
    cout << "The size of '" << p3.getName() << "' is " << tam << endl;
    string ss = p3.getName().substr(0,4); // 4 is the number of chars
    cout << ss << endl;

    // Lambdas
    vector <int> v2;
    for(int i = 0; i < 10; i++)
        v2.push_back(i);

    for_each(v2.begin(),
             v2.end(),
             [](int n){
                cout << n << " is ";
                if(n % 2 == 0)
                    cout << " even" << endl;
                else
                    cout << " odd" << endl;
             });

    vector <int> v3;
    transform(v2.begin(),
             v2.end(),
              back_inserter(v3),
             [](int n) -> double{ return n*2; });

    // Print v3
    for_each(v3.begin(), v3.end(), [](int i){ cout << i << " ";});
    cout << endl;

    return 0;
}
