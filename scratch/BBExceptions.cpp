#include <iostream>
#include "BBExceptions.h"

namespace brainbench
{
    void testExceptions()
    {
        try
        {
            Derived* derived = new Derived();
            throw derived;
        }
        catch (Derived)
        {
            std::cout << "Caught Derived" << std::endl;
        }
        catch (Base)
        {
            std::cout << "Caught Base" << std::endl;
        }
        catch (Base *)
        {
            std::cout << "Caught Base *" << std::endl;
        }
        catch (Derived *)
        {
            std::cout << "Caught Derived *" << std::endl;
        }
        catch (...)
        {
            std::cout << "Uncaught exception" << std::endl;
        }
    }

    static void MyFunc()
    {
        try
        {
            Derived de;
            throw &de;
        }
        catch (Base &)
        {
            std::cout<<"Base caught in MyFunc" << std::endl;
            throw;
        }
        catch (Derived &)
        {
            std::cout<<"Derived caught in MyFunc" << std::endl;
            throw;
        }
    }

    void testExceptions2()
    {
        try
        {
            MyFunc();
        }
        catch (Derived &)
        {
            std::cout<<"Derived caught in testExceptions2" << std::endl;
        }
        catch (Base &)
        {
            std::cout<<"Base caught in testExceptions2" << std::endl;
        }
        catch (...)
        {
            std::cout<<"Unhandled exception caught in testExceptions2" << std::endl;
        }
    }
}
