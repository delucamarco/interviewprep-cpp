#include <iostream>
#include "BBOverloading.h"

namespace brainbench
{
    int x(int n) { std::cout<<"int version called"<<std::endl; return n-2; }
    long x(long n) { std::cout<<"long version called"<<std::endl; return n-2L;}
    double x(double n) { std::cout<<"double version called"<<std::endl; return n-2.0;}

    int MyClass::getValue() const { return _i; }

    std::ostream& operator<<(std::ostream& os, MyClass const& m)
    {
        os<<m.getValue();
        return os;
    }

    // prefix
    MyClass& MyClass::operator++()
    {
        ++_i;
        return *this;
    }

    // postfix
    const MyClass MyClass::operator++(int dummy)
    {
        MyClass res(_i);
        ++_i;
        return res;
    }

    void testOverloading()
    {
        int n = (int)x(float(5.3)); // calls double x(double n)
        int &m=++n;
        ++m;
        std::cout << "n = " << n << std::endl;
        std::cout << "m = " << m << std::endl;


        MyClass x(1);
        std::cout << "x = " << x << std::endl;

        MyClass y = ++x;
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;

        x = MyClass(7);
        std::cout << "x = " << x << std::endl;

        y=x++;
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
    }
}
