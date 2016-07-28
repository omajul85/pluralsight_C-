#include <iostream>
#include <string>
#include "Resource.h"
#include "Person.h"

using namespace std;

int main()
{
    // Deleting something that has already been deleted is a bad thing ! (segmentation fault)

    Person p("Papo", "Lucca", 123);
    p.addResource();

    // CASE 1: This causes a memory leak if no delete resource is add to the addResource method!
    p.setFirstName("Omar");
    p.addResource();

    // CASE 2: When out of scope we try to delete twice the same Resource! (memory leak)
    // We need to teach the system how to copy object safely by writing a copy constructor
    Person newp = p;

    // CASE 3: Copy assignment. We need to overload the asignment operator (=)
    p = newp;

    return 0;
}
