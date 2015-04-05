#include <iostream>
#include <iomanip>
#include <locale>
#include <limits>
#include <cmath>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

//#include "Common.h"
//#include "Sort.h"
//#include "DataStructures.h"

#include <cppunit/ui/text/TestRunner.h>
#include "Heap.h"
#include "BinaryTree.h"

int main()
{
//    datastructures::testStack();
//    datastructures::testQueue();
//    datastructures::testLinkedList();
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(datastructures::HeapTestCase::suite());
    runner.addTest(datastructures::BinaryTreeTestCase::suite());
    runner.run();
    return 0;
}
