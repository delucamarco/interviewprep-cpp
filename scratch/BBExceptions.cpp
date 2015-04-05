#include <iostream>
#include "BBExceptions.h"

namespace brainbench
{
    void testExceptions()
    {
        try
        {
            Derived* derived = new Derived();
            throw derived;  /// throw pointer
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
            throw &de;      /// throw pointer
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

    void MyFunc2()
    {
        try
        {
            Derived de;
            throw de;   /// throw by value
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

    void testExceptions3()
    {
        try
        {
            MyFunc2();
        }
        catch (Derived &)
        {
            std::cout<<"Derived caught in testExceptions3" << std::endl;
        }
        catch (Base &)
        {
            std::cout<<"Base caught in testExceptions3" << std::endl;
        }
        catch (...)
        {
            std::cout<<"Unhandled exception caught in testExceptions3" << std::endl;
        }
    }

}
