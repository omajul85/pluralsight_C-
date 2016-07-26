#include <string>

#ifndef PERSON_H
#define PERSON_H

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
