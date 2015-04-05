#include "Heap.h"

#include "cppunit/TestCaller.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestAssert.h"

namespace datastructures
{
    CppUnit::Test* HeapTestCase::suite()
    {
        CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "HeapTestCase" );

        suiteOfTests->addTest( new CppUnit::TestCaller<HeapTestCase>(
                "testCreation",
                &HeapTestCase::testCreation ) );

        suiteOfTests->addTest( new CppUnit::TestCaller<HeapTestCase>(
                "testPushPopTopMax",
                &HeapTestCase::testPushPopTopMax ) );

        suiteOfTests->addTest( new CppUnit::TestCaller<HeapTestCase>(
                "testPushPopTopMin",
                &HeapTestCase::testPushPopTopMin ) );

        return suiteOfTests;
    }

    void HeapTestCase::setUp()
    {
        _empty =  new Heap<int>();
        _max =  new Heap<int>();
        _min =  new Heap<int>(Heap<int>::MinHeap);
    }

    void HeapTestCase::tearDown()
    {
        delete _empty;
        delete _max;
        delete _min;
    }

    void HeapTestCase::testCreation()
    {
        CPPUNIT_ASSERT( _empty->size() == 0 );
        CPPUNIT_ASSERT( _empty->empty() );
    }

    void HeapTestCase::testPushPopTopMax()
    {
        const int N=10;

        for (int i=1; i<=N; ++i)
        {
            _max->push(i);
            CPPUNIT_ASSERT( _max->size() == i );
            CPPUNIT_ASSERT( !_max->empty() );
            CPPUNIT_ASSERT( _max->top() == i );
        }

        for (int i=N; i>0; --i)
        {
            CPPUNIT_ASSERT( _max->size() == i );
            CPPUNIT_ASSERT( _max->top() == i );
            _max->pop();
        }

        CPPUNIT_ASSERT( _max->empty() );
    }

    void HeapTestCase::testPushPopTopMin()
    {
        const int N=10;

        for (int i=N; i>0; --i)
        {
            _min->push(i);
            CPPUNIT_ASSERT( _min->size() == N-i+1 );
            CPPUNIT_ASSERT( !_min->empty() );
            CPPUNIT_ASSERT( _min->top() == i );
        }

        for (int i=1; i<=N; ++i)
        {
            CPPUNIT_ASSERT( _min->size() == N-i+1 );
            CPPUNIT_ASSERT( _min->top() == i );
            _min->pop();
        }

        CPPUNIT_ASSERT( _min->empty() );
    }
}
