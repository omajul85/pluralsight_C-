#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

class Resource
{
    public:
        Resource(std::string n);
        virtual ~Resource();
        std::string getName() const { return name; };
    protected:
    private:
        std::string name;
};

#endif // RESOURCE_H
