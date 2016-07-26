#ifndef TWEETER_H
#define TWEETER_H

#include <Person.h>
#include <string>

class Tweeter : public Person
{
    public:
        Tweeter(std::string first, std::string last, int n, std::string handle);
        virtual ~Tweeter();
    protected:
    private:
        std::string tweeterhandle;
};

#endif // TWEETER_H
