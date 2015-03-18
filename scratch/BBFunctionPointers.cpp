#include "BBFunctionPointers.h"

namespace brainbench
{
    void X::myMemberFunction(int i) {}

    void myFunction(int i) {}

    void testFunctionPointers()
    {
        void (*p)(int) = &myFunction;
        (*p)(5);

        X x;
        X* xp=&x;
        x.myMemberFunction(5);

        void (X::*cp)(int) = &X::myMemberFunction; // declaration of pointer to member function

        (x.*cp)(5); // invoke myMemberFunction on object x
        (xp->*cp)(5); // invoke myMemberFunction on object pointed by xp
    }
}
