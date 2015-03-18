#ifndef BRAINBENCH_TEMPLATES_H
#define BRAINBENCH_TEMPLATES_H

#include "BBTemplates.h"

namespace brainbench
{
    template<class R, class N> R myfunction(N value)
    {
        return (R)value;
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

