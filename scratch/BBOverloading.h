#ifndef BRAINBENCH_OVERLOADING_H
#define BRAINBENCH_OVERLOADING_H

#include <iostream>

namespace brainbench
{
    class MyClass
    {
        int _i;
    public:
        MyClass(int i) : _i(i) {}

        MyClass& operator++(); // prefix
        const MyClass operator++(int dummy); //postfix

        int getValue() const;
    };

    std::ostream& operator<<(std::ostream&, MyClass const&);

    int x(int n);
    long x(long n);
    double x(double n);

    void testOverloading();
}

#endif // BRAINBENCH_OVERLOADING_H

