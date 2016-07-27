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
        std::string getName();

        // Inline functions for setters and getters
        int getId(){ return id; }
        void setId(int n){ id = n; }
        bool operator<(int i);
        bool operator<(Person& p);
        // Without friend keyword: error: 'int Person::id' is private
        friend bool operator<(int i, Person& p);

    protected:
    private:
        std::string firstname;
        std::string lastname;
        int id;
};

// This is not a method of Person, but a free function. The declaration as friend is necessary inside the class.
bool operator<(int i, Person& p);

#endif // PERSON_H
