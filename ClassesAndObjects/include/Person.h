/* We use include guards to avoid compilation errors when trying
to include the same file several times */

#ifndef PERSON_H
#define PERSON_H

#include <string>

// Do not use using namespace std; in header files !

class Person
{
    public:
        Person(std::string first, std::string last, int n);
        virtual ~Person();
    protected:
    private:
        std::string firstname;
        std::string lastname;
        int id;
};

#endif // PERSON_H
