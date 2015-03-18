#include <iostream>

#include "BBConstructor.h"

namespace brainbench
{
    Foo::~Foo()
    {
        std::cout<<"~Foo()"<<std::endl;
    }

    void testConstructor()
    {
        //Foo* af = new Foo[10]; // fails: missing Foo:Foo()
        {
            std::cout<<"about to create a reference to a temporary Foo"<<std::endl;
            const Foo &af = Foo(1); // OK
            std::cout<<"reference to a temporary Foo created. waiting..."<<std::endl;
            for (long i=0; i<1000000000; ++i);
            std::cout<<"af::i = "<<af.getData()<<std::endl;
        }
        std::cout<<"reference to a temporary Foo now went out of scope"<<std::endl;

        A a(4);
        A b=a;
        std::cout << "value of b.i = " << b.getValue() << std::endl;
    }
}
