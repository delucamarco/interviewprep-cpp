#include "BBAlgorithms.h"

#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <functional>

namespace brainbench
{
    void printList(const std::list<int>& l)
    {
        for (std::list<int>::const_iterator cit=l.begin(); cit != l.end(); ++cit)
        {
            std::cout<<*cit<<" ";
        }
        std::cout<<std::endl;
    }

    void testAlgorithms()
    {
        const int N=8;
        int v[] = {1, 2, 4, 5, 10, 20, 30, 55};
        std::list<int> l(v, v+N);
        printList(l);

        std::replace_if(l.begin(), l.end(), std::bind2nd(std::less<int>(), 10), 10);
        printList(l);
    }

    void testAlgorithms2()
    {
        int myints[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
        std::vector<int> v(myints, myints+9);
        std::sort(v.begin(), v.end());
        std::cout << (std::binary_search(v.begin(), v.end(), 3)) << std::endl;
    }

    void testAlgorithms3()
    {
        std::vector<std::string> strVec;
        strVec.push_back("Foo");
        strVec.push_back("Bar");
        strVec.push_back("Baz");
        strVec.push_back("Bee");

        std::cout << std::count_if(strVec.begin(), strVec.end(), std::bind2nd(std::greater<std::string>(), "Baz"));
    }

    void testAlgorithms4()
    {
        std::list<int> L;
        std::list<int>::iterator it;

        L.push_back(10);    // 10
        printList(L);
        L.push_back(25);    // 10 25
        printList(L);
        L.push_back(40);    // 10 25 40
        printList(L);
        it = L.end();
        L.push_back(55);    // 10 25 40 55
        printList(L);
        L.insert(it, 30);   // 10 25 40 55 30
        printList(L);
        L.push_front(15);   // 15 10 25 40 55 30
        printList(L);
        L.sort(std::greater<int>()); // default sorter: std::less<int>()
        printList(L);       // 55 40 30 25 15 10

        it=std::find_if(L.begin(), L.end(), std::bind2nd(std::less<int>(), 40));
        std::cout << *it << std::endl;

        std::cout<< *max_element(L.begin(), L.end());
    }
}

