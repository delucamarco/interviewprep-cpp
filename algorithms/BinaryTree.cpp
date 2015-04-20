#include "BinaryTree.h"

#include "cppunit/TestCaller.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestAssert.h"

#include <iostream>
#include <algorithm>

namespace datastructures
{
    CppUnit::Test* BinaryTreeTestCase::suite()
    {
        CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "BinaryTreeTestCase" );

        suiteOfTests->addTest( new CppUnit::TestCaller<BinaryTreeTestCase>(
                "testCreation",
                &BinaryTreeTestCase::testCreation ) );

        suiteOfTests->addTest( new CppUnit::TestCaller<BinaryTreeTestCase>(
                "testPushMinMax",
                &BinaryTreeTestCase::testPushMinMax ) );

        suiteOfTests->addTest( new CppUnit::TestCaller<BinaryTreeTestCase>(
                "testErase",
                &BinaryTreeTestCase::testErase ) );

        suiteOfTests->addTest( new CppUnit::TestCaller<BinaryTreeTestCase>(
                "testIterator",
                &BinaryTreeTestCase::testIterator ) );

        return suiteOfTests;
    }

    void BinaryTreeTestCase::setUp()
    {
        _empty =  new BinaryTree<int>();
        _t =  new BinaryTree<int>();
        _t2 =  new BinaryTree<int>();
        _t3 =  new BinaryTree<int>();
    }

    void BinaryTreeTestCase::tearDown()
    {
        delete _empty;
        delete _t;
        delete _t2;
        delete _t3;
    }

    void BinaryTreeTestCase::testCreation()
    {
        CPPUNIT_ASSERT( _empty->size() == 0 );
        CPPUNIT_ASSERT( _empty->empty() );
    }

    void BinaryTreeTestCase::testPushMinMax()
    {
        const int N=10;

        for (int i=1; i<=N; ++i)
        {
            _t->push(i);
            CPPUNIT_ASSERT( _t->size() == i );
            CPPUNIT_ASSERT( !_t->empty() );
            CPPUNIT_ASSERT( _t->max() == i );
            CPPUNIT_ASSERT( _t->min() == 1 );
        }
    }

    void BinaryTreeTestCase::testErase()
    {
        const int N=16;
        int v[N]={12, 5, 18, 2, 9,
                  1, 8, 10, 11, 15,
                 19, 25, 50, 20, 40,
                 45};

        for (int i=0; i<N; ++i)
        {
            _t2->push(v[i]);
            CPPUNIT_ASSERT( _t2->size() == i+1 );
            CPPUNIT_ASSERT( !_t2->empty() );
        }

        int n=_t2->size();
        BinaryTree<int>::iterator it=_t2->find(2);
        CPPUNIT_ASSERT( it != _t2->end());
        _t2->erase(it);
        CPPUNIT_ASSERT(--n == _t2->size());
        it=_t2->find(2);
        CPPUNIT_ASSERT( it == _t2->end());

        it=_t2->find(19);
        CPPUNIT_ASSERT( it != _t2->end());
        _t2->erase(it);
        CPPUNIT_ASSERT(--n == _t2->size());
        it=_t2->find(19);
        CPPUNIT_ASSERT( it == _t2->end());

        it=_t2->find(9);
        CPPUNIT_ASSERT( it != _t2->end());
        _t2->erase(it);
        CPPUNIT_ASSERT(--n == _t2->size());
        it=_t2->find(9);
        CPPUNIT_ASSERT( it == _t2->end());

        it=_t2->find(25);
        CPPUNIT_ASSERT( it != _t2->end());
        _t2->erase(it);
        CPPUNIT_ASSERT(--n == _t2->size());
        it=_t2->find(25);
        CPPUNIT_ASSERT( it == _t2->end());
    }

    void BinaryTreeTestCase::testIterator()
    {
        const int N=16;
        int v[N]={12, 5, 18, 2, 9,
                  1, 8, 10, 11, 15,
                 19, 25, 50, 20, 40,
                 45};


        for (int i=0; i<N; ++i)
        {
            _t3->push(v[i]);
        }
        std::sort(v, v+N);
        int i=0;
        for (BinaryTree<int>::iterator it=_t3->begin(); it!=_t3->end(); ++it)
        {
            int n=*it;
            CPPUNIT_ASSERT( n == v[i++]);
        }
    }
}
