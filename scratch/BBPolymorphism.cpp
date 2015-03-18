#include <iostream>
#include "BBPolymorphism.h"

namespace brainbench
{
    Base::Base() { std::cout<< "Base::Base()" << std::endl; }
    Base::~Base() { std::cout<< "Base::~Base()" << std::endl; }

    Derived::Derived() { std::cout<< "Derived::Derived()" << std::endl; }
    Derived::~Derived() { std::cout<< "Derived::~Derived()" << std::endl; }

    void testPolymorphism()
    {
        Derived *d = new Derived();
        delete d;
        std::cout<<"-------------------------"<<std::endl;

        Base *b = new Base();
        delete b;
        std::cout<<"-------------------------"<<std::endl;

        //d = new Base(); // compilation error
        //delete d;

        b = new Derived();
        delete b;
        std::cout<<"-------------------------"<<std::endl;
    }

    void testPolymorphism2()
    {
        Me me;
    }
}
