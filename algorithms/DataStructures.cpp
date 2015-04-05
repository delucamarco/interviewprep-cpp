#include <iostream>
#include <algorithm>

#include "DataStructures.h"

namespace datastructures
{

//    template <class T> const DynamicSet<T>::PtrType DynamicSet<T>::_search(DynamicSet<T>::KeyType k) const throw(DynamicSetOperationNotImplementedException)
//    {
//        throw DynamicSetOperationNotImplementedException();
//    }
//
//    template <class T> const DynamicSet<T>::PtrType DynamicSet<T>::_minimum() const throw(DynamicSetOperationNotImplementedException)
//    {
//        throw DynamicSetOperationNotImplementedException();
//    }
//
//    template <class T> const DynamicSet<T>::PtrType DynamicSet<T>::_maximum() const throw(DynamicSetOperationNotImplementedException)
//    {
//        throw DynamicSetOperationNotImplementedException();
//    }
//
//    template <class T> const DynamicSet<T>::PtrType DynamicSet<T>::_successor(const PtrType x) const throw(DynamicSetOperationNotImplementedException)
//    {
//        throw DynamicSetOperationNotImplementedException();
//    }
//
//    template <class T> const DynamicSet<T>::PtrType DynamicSet<T>::_predecessor(const PtrType x) const throw(DynamicSetOperationNotImplementedException)
//    {
//        throw DynamicSetOperationNotImplementedException();
//    }

    ///////////////////////////////////////

    void testStack()
    {
        const int N=10;
        Stack<int>* s = new Stack<int>(N);

        std::cout<< "Testing Stack(" << N << ")" <<std::endl;

        for (int i=0; i<N; ++i)
        {
            s->push(i);
        }

        int j;
        while (!s->empty())
        {
            j=s->pop();
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;

        delete s;
    }

    template<class T>
    Stack<T>::Stack(int capacity) :
        _capacity(capacity), _top(-1)
    {
        _data = new T[capacity];
    }

    template<class T>
    Stack<T>::Stack(const Stack<T>& s) :
        _capacity(s._capacity), _top(s._top)
    {
        _data=new T[_capacity];
        if (_top>=0)
        {
            std::copy(s._data, s._data+_top+1, _data);
        }
    }

    template<class T>
    Stack<T>::~Stack()
    {
        delete _data;
    }

    template<class T>
    Stack<T>& Stack<T>::operator=(const Stack<T>& s)
    {
        if (&s != this)
        {
            if (s._capacity != this->_capacity)
            {
                delete _data;
                _data=new T[_capacity];
                _capacity=s._capacity;
            }
            _top=s._top;
            if (_top>=0)
            {
                std::copy(s._data, s._data+_top+1, _data);
            }
        }
        return *this;
    }

    template<class T>
    void Stack<T>::push(const T& k) throw(DynamicSetOverflowException)
    {
        if (full())
        {
            throw DynamicSetOverflowException();
        }
        _data[++_top]=k;
    }

    template<class T>
    T Stack<T>::pop() throw(DynamicSetUnderflowException)
    {
        if (empty())
        {
            throw DynamicSetUnderflowException();
        }
        T k = _data[_top--];
        return k;
    }

    template <class T>
    bool Stack<T>::empty() const
    {
        return (_top==-1);
    }

    template <class T>
    bool Stack<T>::full() const
    {
        return (_top==_capacity-1);
    }

    ///////////////////////////////////////////

    void testQueue()
    {
        const int N=10;
        Queue<int>* s = new Queue<int>(N+1);

        std::cout<< "Testing Queue(" << N << ")" <<std::endl;

        for (int i=0; i<N; ++i)
        {
            s->enqueue(i);
        }

        int j;
        while (!s->empty())
        {
            j=s->dequeue();
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;

        delete s;
    }

    template <class T>
    Queue<T>::Queue(int capacity) :
        _capacity(capacity), _head(0), _tail(0)
    {
        _data=new T[_capacity];
    }

    template <class T>
    Queue<T>::Queue(const Queue<T>& s) :
        _capacity(s._capacity), _head(s._head), _tail(s._tail)
    {
        _data=new T[_capacity];
        for (int i=_head; i<_tail; i=(i+1)%_capacity)
        {
            _data[i]=s._data[i];
        }
    }

    template <class T>
    Queue<T>::~Queue()
    {
        delete _data;
    }

    template <class T>
    Queue<T>& Queue<T>::operator=(const Queue<T>& s)
    {
        if (this != &s)
        {
            if (s._capacity != this->_capacity)
            {
                delete _data;
                _data=new T[_capacity];
                _capacity=s._capacity;
            }
            _head=s._head;
            _tail=s._tail;
            for (int i=_head; i<_tail; i=(i+1)%_capacity)
            {
                _data[i]=s._data[i];
            }
        }
        return *this;
    }

    template <class T>
    void Queue<T>::enqueue(const T& k) throw(DynamicSetOverflowException)
    {
        if (full())
        {
            throw DynamicSetOverflowException();
        }
        _data[_tail]=k;
        _tail=(_tail+1)%_capacity;
    }

    template <class T>
    T Queue<T>::dequeue() throw(DynamicSetUnderflowException)
    {
        if (empty())
        {
            throw DynamicSetUnderflowException();
        }
        T k=_data[_head];
         _head=(_head+1)%_capacity;
        return k;
    }

    template <class T>
    bool Queue<T>::empty() const
    {
        return _head==_tail;
    }

    template <class T>
    bool Queue<T>::full() const
    {
        return (_tail+1)%_capacity==_head;
    }

    /////////////////////////////////////////////////////////

    void testLinkedList()
    {
        const int N=10;
        LinkedList<int>* l = new LinkedList<int>();

        std::cout<< "Testing LinkedList" <<std::endl;

        for (int i=0; i<N; ++i)
        {
            l->push_back(i);
        }

        for (LinkedList<int>::iterator it=l->begin(); it!=l->end(); ++it)
        {
            int j=*it;
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;

        delete l;
    }

    template <class T>
    LinkedList<T>::LinkedList() :
        _head(NULL), _tail(NULL)
    {
    }

    template <class T>
    LinkedList<T>::~LinkedList()
    {
        _cleanup();
    }

    template <class T>
    LinkedList<T>::LinkedList(const LinkedList<T>& l) :
        _head(NULL), _tail(NULL)
    {
        _copy(l);
    }

    template <class T>
    LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& l)
    {
        if (&l != this)
        {
            _cleanup();
            _head=_tail=NULL;
            _copy(l);
        }
        return *this;
    }

    template <class T>
    void LinkedList<T>::push_back(const T& k)
    {
        Node* n=new Node();
        n->info=k;
        n->next=NULL;
        if (_head==NULL)
        {
            _head=_tail=n;
        }
        else
        {
            _tail->next=n;
            _tail=n;
        }
    }

    template <class T>
    void LinkedList<T>::push_front(const T& k)
    {
        Node* n=new Node();
        n->info=k;
        n->next=NULL;
        if (_head==NULL)
        {
            _head=_tail=n;
        }
        else
        {
            n->next=_head;
            _head=n;
        }
    }

    template <class T>
    bool LinkedList<T>::empty() const
    {
        return _head==NULL;
    }

    template <class T>
    bool LinkedList<T>::full() const
    {
        return false;
    }

    template <class T>
    bool LinkedList<T>::search(const T& t) const
    {
        for (const Node*p=_head; p!=NULL; p=p->next)
        {
            if (p->info==t)
            {
                return true;
            }
        }
        return false;
    }

    template <class T>
    typename LinkedList<T>::iterator LinkedList<T>::begin() const
    {
        return iterator(_head);
    }

    template <class T>
    typename LinkedList<T>::iterator LinkedList<T>::end() const
    {
        return iterator(NULL);
    }

    template <class T>
    void LinkedList<T>::_copy(const LinkedList<T>& l)
    {
        for (Node* p=l._head; p!=NULL; p=p->next)
        {
            Node* n=new Node();
            n->info=p->info;
            n->next=NULL;
            if (_head==NULL)
            {
                _head=_tail=n;
            }
            else
            {
                _tail->next=n;
                _tail=n;
            }
        }
    }

    template <class T>
    void LinkedList<T>::_cleanup()
    {
        while (_head != NULL)
        {
            Node*p = _head->next;
            delete _head;
            _head = p;
        }
    }

    template <class T>
    const T& LinkedList<T>::iterator::operator*()
    {
        return _current->info;
    }

    template <class T>
    bool LinkedList<T>::iterator::operator!=(const LinkedList<T>::iterator& rhs) const
    {
        return this->_current != rhs._current;
    }

    template <class T>
    typename LinkedList<T>::iterator& LinkedList<T>::iterator::operator++()
    {
        _current=_current->next;
        return *this;
    }
}
