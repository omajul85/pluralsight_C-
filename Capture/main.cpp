// The capture

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int> v){
    for_each(v.begin(), v.end(), [](int n) { cout << n << " ";});
    cout << endl;
}

int main()
{
    int x(3);
    int y(7);
    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);

    // Capturing by value explicitly [x,y]
    cout << "Printing elements between " << x << " and " << y << " inclusive: ";
    for_each(v.begin(),
             v.end(),
             [x,y](int n){
                if(n >= x && n <= y)
                    cout << n << " ";
             });
    cout << endl;
    printVector(v);

    // Capturing by value implicitly [=]
    x = 2;
    y = 9;
    cout << "Printing elements between " << x << " and " << y << " inclusive: ";
    for_each(v.begin(),
             v.end(),
             [=](int n){
                if(n >= x && n <= y)
                    cout << n << " ";
             });
    cout << endl;
    printVector(v);

    // Capturing by value and changing locally [=] mutable - also changing the param (int&)
    x = 1;
    y = 1;
    for_each(v.begin(), v.end(), [=](int& n) mutable {
        const int old = n;
        n *= 2; // double each element
        x = y;
        y = old;
    });
    cout << "x: " << x << "  y: " << y << endl;
    printVector(v);

    // Capturing by reference [&x, &y]  - also changing the param (int&)
    v.clear();
    for (int i = 0; i < 10; ++i) {v.push_back(i);}
    for_each(v.begin(), v.end(), [&x, &y](int& n) {
        const int old = n;
        n *= 2;
        x = y;
        y = old;
    });
    cout << "x: " << x << "  y: " << y << endl;
    printVector(v);

    // Capturing whole stack by reference (and a neater way to keep initializing these vectors)
    v.clear();
    int i = 0;
    generate_n(back_inserter(v), 10, [&] { return i++; }); // [&]() { return i++; } would have been OK too
    printVector(v);
    cout << "i: " << i << endl;

    return 0;
}
