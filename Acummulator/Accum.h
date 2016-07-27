#ifndef ACCUM_H_INCLUDED
#define ACCUM_H_INCLUDED

template <class T>
class Accum{
    public:
        Accum(T start): total(start){};
        T operator+=(const T& t){ return total += t; };
        T getTotal(){ return total; };

    private:
        T total;
};

#endif // ACCUM_H_INCLUDED
