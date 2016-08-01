#ifndef UTILITY_H
#define UTILITY_H


class Utility
{
    private:
        int x;
    public:
        Utility(int a): x(a){}
        int doublex() {return 2*x;}
        int triplex() {return 3*x;}
};

#endif // UTILITY_H
