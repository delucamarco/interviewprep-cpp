#include "BinaryTree.h"

#include "cppunit/TestCaller.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestAssert.h"

namespace datastructures
{
    CppUnit::Test* BinaryTreeTestCase::suite()
    {
        CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "BinaryTreeTestCase" );

        suiteOfTests->addTest( new CppUnit::TestCaller<BinaryTreeTestCase>(
                "testCreation",
                &BinaryTreeTestCase::testCreation ) );

//        suiteOfTests->addTest( new CppUnit::TestCaller<BinaryTreeTestCase>(
//                "testPushPopTopMax",
//                &BinaryTreeTestCase::testPushPopTopMax ) );
//
//        suiteOfTests->addTest( new CppUnit::TestCaller<BinaryTreeTestCase>(
//                "testPushPopTopMin",
//                &BinaryTreeTestCase::testPushPopTopMin ) );

        return suiteOfTests;
    }

    void BinaryTreeTestCase::setUp()
    {
        _empty =  new BinaryTree<int>();
        _t =  new BinaryTree<int>();
    }

    void BinaryTreeTestCase::tearDown()
    {
        delete _empty;
        delete _t;
    }

    void BinaryTreeTestCase::testCreation()
    {
        CPPUNIT_ASSERT( _empty->size() == 0 );
        CPPUNIT_ASSERT( _empty->empty() );
    }

//    void BinaryTreeTestCase::testPushPopTopMax()
//    {
//        const int N=10;
//
//        for (int i=1; i<=N; ++i)
//        {
//            _max->push(i);
//            CPPUNIT_ASSERT( _max->size() == i );
//            CPPUNIT_ASSERT( !_max->empty() );
//            CPPUNIT_ASSERT( _max->top() == i );
//        }
//
//        for (int i=N; i>0; --i)
//        {
//            CPPUNIT_ASSERT( _max->size() == i );
//            CPPUNIT_ASSERT( _max->top() == i );
//            _max->pop();
//        }
//
//        CPPUNIT_ASSERT( _max->empty() );
//    }
//
//    void BinaryTreeTestCase::testPushPopTopMin()
//    {
//        const int N=10;
//
//        for (int i=N; i>0; --i)
//        {
//            _min->push(i);
//            CPPUNIT_ASSERT( _min->size() == N-i+1 );
//            CPPUNIT_ASSERT( !_min->empty() );
//            CPPUNIT_ASSERT( _min->top() == i );
//        }
//
//        for (int i=1; i<=N; ++i)
//        {
//            CPPUNIT_ASSERT( _min->size() == N-i+1 );
//            CPPUNIT_ASSERT( _min->top() == i );
//            _min->pop();
//        }
//
//        CPPUNIT_ASSERT( _min->empty() );
//    }
}
