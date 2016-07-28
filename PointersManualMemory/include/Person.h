/* We use include guards to avoid compilation errors when trying
to include the same file several times */

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Resource.h"

// Do not use using namespace std; in header files !

class Person
{
    public:
        Person(std::string first, std::string last, int n);

        // Copy constructor
        Person(const Person& p);

        virtual ~Person();
        std::string getName() const;

        // Inline functions for setters and getters
        int getId() const { return id; }
        void setId(int n){ id = n; }
        void setFirstName(std::string f){ firstname = f; }
        void addResource();
        bool operator<(int i) const;
        bool operator<(const Person& p) const;
        Person& operator=(const Person& p);
        // Without friend keyword: error: 'int Person::id' is private
        friend bool operator<(int i, const Person& p);

    protected:
    private:
        std::string firstname;
        std::string lastname;
        int id;
        Resource* pResource;
};

// This is not a method of Person, but a free function. The declaration as friend is necessary inside the class.
bool operator<(int i, const Person& p);

#endif // PERSON_H
