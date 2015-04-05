#ifndef ALGORITHM_DATASTRUCTURES_HEAP_H
#define ALGORITHM_DATASTRUCTURES_HEAP_H

#include "DataStructures.h"
#include "cppunit/Test.h"
#include "cppunit/TestFixture.h"

namespace datastructures
{
    template <class T>
    class Heap
    {
    public:
        enum HeapType
        {
            MaxHeap,
            MinHeap
        };

    private:
        static const int DefaultSize = 16;

        T* _data;
        int _size;
        int _capacity;
        HeapType _type;
        bool (Heap::*_consistency)(int parent, int child) const;

        Heap(const Heap&);
        Heap(const T*, int length);
        Heap& operator=(const Heap&);

        inline int left(int j) const { return (j<<1)+1; }
        inline int right(int j) const { return (j+1)<<1; }
        inline int parent(int j) const { return (j-1)>>1; }
        inline bool consistencyMax(int parent, int child) const { return _data[parent]>=_data[child]; }
        inline bool consistencyMin(int parent, int child) const { return _data[parent]<=_data[child]; }

    public:
        Heap(HeapType type=MaxHeap);
        virtual ~Heap();

        void push(const T&);
        void pop() throw(DynamicSetUnderflowException);
        void clear();

        const T& top() const throw(DynamicSetUnderflowException);
        inline int size() const;
        inline bool empty() const;

        static void sort(T* unsortedArray, int length);
    };

    template <class T>
    Heap<T>::Heap(HeapType type) :
        _size(0), _capacity(DefaultSize), _type(type),
        _consistency((_type==MaxHeap)  ? &Heap<T>::consistencyMax : &Heap<T>::consistencyMin)
    {
        _data = new T[_capacity];
    }

    template <class T>
    Heap<T>::~Heap()
    {
        delete _data;
    }

    template <class T>
    inline int Heap<T>::size() const
    {
        return _size;
    }

    template <class T>
    inline bool Heap<T>::empty() const
    {
        return (_size==0);
    }

    template <class T>
    inline const T& Heap<T>::top() const throw(DynamicSetUnderflowException)
    {
        if (empty())
        {
            throw DynamicSetUnderflowException();
        }
        return _data[0];
    }

    template <class T>
    void Heap<T>::clear()
    {
        if (empty())
        {
            return;
        }
        _size=0;
        if (_capacity==DefaultSize)
        {
            return;
        }
        delete _data;
        _capacity=DefaultSize;
        _data=new T[_capacity];
    }

    template <class T>
    void Heap<T>::push(const T& key)
    {
        // realloc if needed
        if (_size == _capacity)
        {
            int newCapacity=_capacity<<1;
            T* newData = new T[newCapacity];
            std::copy(_data, _data+_capacity, newData);
            delete _data;
            _data=newData;
            _capacity=newCapacity;
        }

        // add key as last element
        int i=_size++;
        _data[i]=key;

        // move up until consistency relationship satisfied
        for (int pi=parent(i); i>0 && !(this->*_consistency)(pi, i); i=pi, pi=parent(i))
        {
            T x = _data[i];
            _data[i]=_data[pi];
            _data[pi]=x;
        }
    }

    template <class T>
    void Heap<T>::pop() throw(DynamicSetUnderflowException)
    {
        // if empty throw underflow
        if (empty())
        {
            throw DynamicSetUnderflowException();
        }

        // move last element to root
        T lastElement=_data[--_size];
        if (_size==0)
        {
            return;
        }
        _data[0]=lastElement;

        // move down until consistency relationship satisfied
        int i=0, largest=0;
        do
        {
            i=largest;
            int l=left(i);
            int r=right(i);
            if (l<_size && !(this->*_consistency)(i, l))
            {
                largest=l;
            }
            else
            {
                largest=i;
            }
            if (r<_size && !(this->*_consistency)(largest, r))
            {
                largest=r;
            }
            if (largest != i)
            {
                T x = _data[largest];
                _data[largest]=_data[i];
                _data[i]=x;
            }
        }
        while (i!=largest);
    }

    class HeapTestCase : public CppUnit::TestFixture
    {
    private:
        Heap<int>* _empty;
        Heap<int>* _max;
        Heap<int>* _min;

    public:
        static CppUnit::Test* suite();

        void setUp();
        void tearDown();

    protected:
        void testCreation();
        void testPushPopTopMax();
        void testPushPopTopMin();
    };
}

#endif // ALGORITHM_DATASTRUCTURES_HEAP_H
