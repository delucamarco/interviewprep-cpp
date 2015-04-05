#ifndef BRAINBENCH_TEMPLATES_H
#define BRAINBENCH_TEMPLATES_H

namespace brainbench
{
    template<class R, class N> R myfunction(N value);

    template<class T> class A
    {
    public:
        A(){}
    };

    template<class T> class B
    {
    public:
        B(){}
        friend class A<T>;
    };

    template<class T> class Stack
    {
    public:
        int Push(T);
        T Pop();
    };

    // template specialization example
    template<> class Stack<char>
    {
    public:
        int Push(char);
        char Pop();
    };

    void testTemplates();
    void testTemplates2();
}

#endif // BRAINBENCH_TEMPLATES_H

