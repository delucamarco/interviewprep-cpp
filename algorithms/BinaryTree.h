#ifndef ALGORITHM_DATASTRUCTURES_BINARYTREE_H
#define ALGORITHM_DATASTRUCTURES_BINARYTREE_H

#include "DataStructures.h"
//#include "cppunit/Test.h"
//#include "cppunit/TestFixture.h"


namespace datastructures
{
    template <class T>
    class BinaryTree
    {
    private:
        struct Node
        {
            const T info;
            Node* left;
            Node* right;
            Node* parent;

            Node(const T& i) : info(i), left(NULL), right(NULL), parent(NULL) {}
        };

        Node* _root;
        int _size;
        BinaryTree(const BinaryTree&);
        BinaryTree& operator=(const BinaryTree&);

    public:
        BinaryTree();

        inline bool empty() const;
        inline int size() const;

        void push(const T&);
    };

    template <class T>
    BinaryTree<T>::BinaryTree() :
        _root(NULL), _size(0)
    {
    }

    template <class T>
    bool BinaryTree<T>::empty() const
    {
        return (_size == 0);
    }

    template <class T>
    int BinaryTree<T>::size() const
    {
        return _size;
    }

    template <class T>
    void BinaryTree<T>::push(const T& key)
    {
        Node* z=new Node(key);
        Node* x=_root, y=NULL;

        while (x != NULL)
        {
            y=x;
            if (z->info<x->info)
            {
                x=x->left;
            }
            else
            {
                x=x->right;
            }
        }
        z->parent=y;
        if (y==NULL)
        {
            _root=z;
        }
        else if (z->info < y->info)
        {
            y->left=z;
        }
        else
        {
            y->right=z;
        }
    }

    class BinaryTreeTestCase : public CppUnit::TestFixture
    {
    private:
        BinaryTree<int>* _empty;
        BinaryTree<int>* _t;

    public:
        static CppUnit::Test* suite();

        void setUp();
        void tearDown();

    protected:
        void testCreation();
        //void testPushPopTopMax();
        //void testPushPopTopMin();
    };
}

#endif // ALGORITHM_DATASTRUCTURES_BINARYTREE_H
