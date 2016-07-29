#include <iostream>
#include <vector>
#include <map>
#include "Person.h"

using namespace std;

int main()
{
    // VECTOR

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    // Print the vector in normal order using an iterator
    for (auto i = v.begin(); i != v.end(); i++)
        cout << *i << " ";
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

    return 0;
}
