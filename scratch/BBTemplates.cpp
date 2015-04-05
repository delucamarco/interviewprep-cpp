#ifndef BRAINBENCH_TEMPLATES_H
#define BRAINBENCH_TEMPLATES_H

#include "BBTemplates.h"

#include <iostream>

namespace brainbench
{
    template<class R, class N> R myfunction(N value)
    {
        return (R)value;
    }

    template<class T> void foo(T op1, T op2)
    {
    }

    template<> void foo(int a, int b)
    {
        std::cout<<"int version";
    }

    template<> void foo(long a, long b)
    {
        std::cout<<"long version";
    }

    template<class T>
    struct sum
    {
        static void foo(T op1, T op2)
        {
        }
    };

    void testTemplates2()
    {
        foo(1, 3);             /// OK, calls foo<int>
        foo<int> (1, 3L);      /// OK, also calls foo<int> with 1 and (int)3L
        //sum::foo(1, 2);      /// does NOT compile: no parameter specified for template class sum
        //sum<int>::foo(1, 2); /// this one compiles
    }

    void testTemplates()
    {
        //double d=6.9; int i=myfunction<>(d);                      // does not compile
        //int i=5; double d = template<double, int> myfunction(i);  // does not compile
        //double d=6.9; int i=myfunction(d);                        // does not compile
        //int i=5; double d=<double>myfunction<int>(i);             // does not compile
        double d=6.9; int i=myfunction<int, double>(d);             // OK
    }
}

#endif // BRAINBENCH_TEMPLATES_H

