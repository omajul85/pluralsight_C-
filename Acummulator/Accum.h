#ifndef ACCUM_H_INCLUDED
#define ACCUM_H_INCLUDED

#include "Person.h"

template <class T>
class Accum{
    public:
        Accum(T start): total(start){};
        T operator+=(const T& t){ return total += t; };
        T getTotal(){ return total; };

    private:
        T total;
};

// Template specialization for Person
template <>
class Accum<Person>{
    public:
        Accum(int start): total(start){};
        int operator+=(Person& p){ return total += p.getId(); };
        int getTotal(){ return total; };

    private:
        int total;
};

#endif // ACCUM_H_INCLUDED
