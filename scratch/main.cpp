#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

//#include "SimpleList.h"

//#include "BBExceptions.h"
#include "BBAlgorithms.h"
//#include "BBConstructor.h"
//#include "BBOverloading.h"
//#include "BBPolymorphism.h"
//#include "BBTemplates.h"

namespace bbtypes
{
    struct Foo
    {

        Foo(int i) { std::cout<<'i';}
        Foo(char c) { std::cout<<'c';}
        Foo(long l) { std::cout<<'l';}
        Foo(float f) { std::cout<<'f';}
        inline virtual void g() { }

    };

    void testTypes()
    {
        Foo f1('a');
        Foo f2('a'+1);  /// this calls Foo(int i) because 's' is converted into an int and then summed to 1
        Foo f3(1);
        Foo f4(0x01);
        Foo f5(0x0001L);
        Foo f6(1.0f);
    }
}

template<class T>
class Obj
{
    T t;
public:
    operator T() const { return t; }
};

int main()
{




    return 0;
}
