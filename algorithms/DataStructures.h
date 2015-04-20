#ifndef ALGORITHM_DATASTRUCTURES_H
#define ALGORITHM_DATASTRUCTURES_H

#include <exception>

namespace datastructures
{
    class DynamicSetException : public std::exception {};
    class DynamicSetRangeException : public DynamicSetException {};
    class DynamicSetOverflowException : public DynamicSetException {};
    class DynamicSetUnderflowException : public DynamicSetException {};
    class DynamicSetOperationNotImplementedException : public DynamicSetException {};

//    template <class T>
//    class DynamicSet
//    {
//    public:
//        class Iterator
//        {
//        public:
//            virtual ~Iterator();
//            virtual T getValue() const;
//        };
//
//        virtual ~DynamicSet();
//
//    protected:
//
//        virtual Iterator _search(const T&) const throw(DynamicSetOperationNotImplementedException);
//        virtual Iterator _minimum() const throw(DynamicSetOperationNotImplementedException);
//        virtual Iterator _maximum() const throw(DynamicSetOperationNotImplementedException);
//        virtual Iterator _successor(const Iterator&) const throw(DynamicSetOperationNotImplementedException);
//        virtual Iterator _predecessor(const Iterator&) const throw(DynamicSetOperationNotImplementedException);
//
//        virtual void _insert(const T&) = 0;
//        virtual void _delete(const T&) = 0;
//    };
//

////////////////////////////////////////////////////////////////////////

    template<class T>
    class Stack
    {
        public:
            Stack(int capacity);
            Stack(const Stack<T>& s);
            ~Stack();

            Stack<T>& operator=(const Stack<T>& s);
            void push(const T&) throw(DynamicSetOverflowException);
            T pop() throw(DynamicSetUnderflowException);

            bool empty() const;
            bool full() const;

        private:
            int _capacity;
            int _top;
            T* _data;
    };

    template <class T>
    class Queue
    {
        public:
            Queue(int capacity);
            Queue(const Queue<T>& s);
            ~Queue();

            Queue<T>& operator=(const Queue<T>& s);
            void enqueue(const T& k) throw(DynamicSetOverflowException);
            T dequeue() throw(DynamicSetUnderflowException);

            bool empty() const;
            bool full() const;

        private:
            int _capacity;
            int _head;
            int _tail;
            T* _data;
    };

    template <class T>
    class LinkedList
    {
        private:
            struct Node;

        public:
            class iterator
            {
            private:
                const Node* _current;

            public:
                iterator(const Node* n) : _current(n)  {}
                ~iterator() {}

                const T& operator*();
                bool operator!=(const iterator& rhs) const;
                iterator& operator++();
            };

            LinkedList();
            LinkedList(const LinkedList<T>&);
            ~LinkedList();

            LinkedList<T>& operator=(const LinkedList<T>& l);
            void push_back(const T& k);
            void push_front(const T& k);

            bool search(const T& k) const;
            bool empty() const;
            bool full() const;

            iterator begin() const;
            iterator end() const;

        private:
            struct Node
            {
                T info;
                Node* next;
            };

            Node* _head;
            Node* _tail;

            void _copy(const LinkedList<T>& l);
            void _cleanup();
    };

    void testStack();
    void testQueue();
    void testLinkedList();
}

#endif // ALGORITHM_DATASTRUCTURES_H
