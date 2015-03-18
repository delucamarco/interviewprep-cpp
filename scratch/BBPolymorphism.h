#ifndef BRAINBENCH_POLYMORPHISM_H
#define BRAINBENCH_POLYMORPHISM_H

namespace brainbench
{
    class Base
    {
    public:
        Base();
        virtual ~Base();    // must be virtual if I want this to work:
                            // Base* b = new Derived; delete b;
    };

    class Derived : public Base
    {
    public:
        Derived();
        ~Derived();
    };

    class Grandpa
    {
    public:
        Grandpa() { std::cout<<"Grandpa::Grandpa()"<<std::endl; }
    };

    class Ma : virtual public Grandpa {};
    class Pa : virtual public Grandpa {};

    class Me : public Ma, public Pa, virtual public Grandpa {};

    void testPolymorphism();
    void testPolymorphism2();
}

#endif // BRAINBENCH_POLYMORPHISM_H


