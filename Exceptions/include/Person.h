#include <string>
#ifndef _Person_H
#define _Person_H

class Person
{
    private:
        std::string firstname;
        std::string lastname;
        int arbitrarynumber;

    public:
        Person(std::string first,
            std::string last,
            int arbitrary);
        Person();
        ~Person();
        std::string GetName() {return firstname + " " + lastname;}
        int GetNum() {return arbitrarynumber;}
        int ratio ();
};
#endif
