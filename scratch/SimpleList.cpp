#include <iostream>

#include "SimpleList.h"

namespace scratch
{

    SimpleList::SimpleList() :
        head(NULL), tail(NULL)
    {
    }

    SimpleList::~SimpleList()
    {
        for (Node* p; head != NULL; head = p)
        {
            p=head->next;
            delete head;
        }
        tail = NULL;
    }

    void SimpleList::push_back(int i)
    {
        Node* p=new Node();
        p->next=NULL;
        p->info=i;

        if (head == NULL)
        {
            head=tail=p;
        }
        else
        {
            tail->next=p;
            tail=p;
        }
    }

    void SimpleList::push_front(int i)
    {
        Node* p=new Node();
        p->next=head;
        p->info=i;

        if (head == NULL)
        {
            head=tail=p;
        }
        else
        {
            head=p;
        }
    }

    void SimpleList::print()
    {
        for (Node* p=head; p != NULL; p=p->next)
        {
            if (p != head)
            {
                std::cout << " ";
            }
            std::cout << p->info;
        }
        if (head != NULL)
        {
            std::cout<<std::endl;
        }
    }

    void testSimpleList()
    {
        const int N=10;
        SimpleList* l1;

        std::cout<<"Testing push_back"<<std::endl;
        l1 = new SimpleList();
        for (int i=0; i<N; ++i)
        {
            l1->push_back(i);
        }
        l1->print();
        delete l1;

        std::cout<<"Testing push_front"<<std::endl;
        l1 = new SimpleList();
        for (int i=0; i<N; ++i)
        {
            l1->push_front(i);
        }
        l1->print();
        delete l1;
    }

}
