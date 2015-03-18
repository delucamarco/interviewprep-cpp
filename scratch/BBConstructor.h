#ifndef BRAINBENCH_CONSTRUCTOR_H
#define BRAINBENCH_CONSTRUCTOR_H

namespace brainbench
{
    class A
    {
        int i;
    public:
        A(int ii) { i = ii; }
        A(const A& a) { i=a.i; i++; }
        A& operator=(const A& a) { i=a.i; i--; }
        int getValue() const { return i; }
    };

    class Foo
    {
        int i;
    public:
        Foo(int ii) : i(ii) {};
        ~Foo();
        int getData() const { return i; }
    };

    void testConstructor();
}

#endif // BRAINBENCH_CONSTRUCTOR_H
