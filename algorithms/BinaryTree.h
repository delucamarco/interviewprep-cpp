#ifndef ALGORITHM_DATASTRUCTURES_BINARYTREE_H
#define ALGORITHM_DATASTRUCTURES_BINARYTREE_H

#include "DataStructures.h"
//#include "cppunit/Test.h"
//#include "cppunit/TestFixture.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <deque>

namespace datastructures
{
    template <class T> class BinaryTree;
    template <class T> std::ostream& operator<<(std::ostream& os, const BinaryTree<T>& t);

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
            const Node* minNode() const;
            const Node* maxNode() const;
            Node* minNode();
            Node* maxNode();
            Node* successor();
        };

        Node* _root;
        int _size;
        BinaryTree(const BinaryTree&);
        BinaryTree& operator=(const BinaryTree&);

        void transplant(Node* u, Node* v);
        int maxHeight(const Node* p) const;
        void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const std::deque<Node*>& nodesQueue, std::ostream& out) const;
        void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const std::deque<Node*>& nodesQueue, std::ostream& out) const;
        void printLeaves(int indentSpace, int level, int nodesInThisLevel, const std::deque<Node*>& nodesQueue, std::ostream& out) const;

    public:
        class iterator
        {
        private:
            Node* _current;

        public:
            iterator(Node* n) : _current(n)  {}
            ~iterator() {}

            const T& operator*() const;
            inline bool operator!=(const iterator& rhs) const { return rhs._current != this->_current; }
            inline bool operator==(const iterator& rhs) const { return rhs._current == this->_current; }
            iterator& operator++();
            //iterator& operator--();

            friend class BinaryTree<T>;
        };

        BinaryTree();

        inline bool empty() const;
        inline int size() const;
        const T& max() const throw(DynamicSetRangeException);
        const T& min() const throw(DynamicSetRangeException);
        iterator find(const T&);

        void push(const T&);
        void erase(iterator it) throw(DynamicSetRangeException);

        iterator begin();
        iterator end();

        friend std::ostream& operator<< <> (std::ostream& os, const BinaryTree<T>& t);
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
    const typename BinaryTree<T>::Node* BinaryTree<T>::Node::minNode() const
    {
        Node* n=this;
        while (n->left!=NULL)
        {
            n=n->left;
        }
        return n;
    }

    template <class T>
    const typename BinaryTree<T>::Node* BinaryTree<T>::Node::maxNode() const
    {
        Node* n=this;
        while (n->right!=NULL)
        {
            n=n->right;
        }
        return n;
    }

    template <class T>
    typename BinaryTree<T>::Node* BinaryTree<T>::Node::minNode()
    {
        Node* n=this;
        while (n->left!=NULL)
        {
            n=n->left;
        }
        return n;
    }

    template <class T>
    typename BinaryTree<T>::Node* BinaryTree<T>::Node::maxNode()
    {
        Node* n=this;
        while (n->right!=NULL)
        {
            n=n->right;
        }
        return n;
    }

    template <class T>
    typename BinaryTree<T>::Node* BinaryTree<T>::Node::successor()
    {
        Node* x=this;
        if (x->right != NULL)
        {
            return x->right->minNode();
        }
        Node* y=x->parent;
        while (y!=NULL && x==y->right)
        {
            x=y;
            y=y->parent;
        }
        return y;
    }

    template <class T>
    const T& BinaryTree<T>::max() const throw(DynamicSetRangeException)
    {
        const Node* n=_root->maxNode();
        if (n==NULL)
        {
            throw DynamicSetRangeException();
        }
        return n->info;
    }

    template <class T>
    const T& BinaryTree<T>::min() const throw(DynamicSetRangeException)
    {
        const Node* n=_root->minNode();
        if (n==NULL)
        {
            throw DynamicSetRangeException();
        }
        return n->info;
    }

    template <class T>
    void BinaryTree<T>::push(const T& key)
    {
        Node* z=new Node(key);
        Node* x=_root;
        Node* y=NULL;

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
        ++_size;
    }

    template <class T>
    typename BinaryTree<T>::iterator BinaryTree<T>::begin()
    {
        return iterator(_root->minNode());
    }

    template <class T>
    typename BinaryTree<T>::iterator BinaryTree<T>::end()
    {
        return iterator(NULL);
    }

    template <class T>
    typename BinaryTree<T>::iterator BinaryTree<T>::find(const T& key)
    {
        Node* n=_root;
        while (n!=NULL && n->info!=key)
        {
            if (key < n->info)
            {
                n = n->left;
            }
            else
            {
                n = n->right;
            }
        }
        return iterator(n);
    }

    template <class T>
    void BinaryTree<T>::transplant(Node* u, Node* v)
    {
        if (u->parent == NULL)
        {
            _root=v;
        }
        else if (u == u->parent->left)
        {
            u->parent->left = v;
        }
        else
        {
            u->parent->right = v;
        }
        if (v != NULL)
        {
            v->parent = u->parent;
        }
    }

    template <class T>
    void BinaryTree<T>::erase(iterator it) throw(DynamicSetRangeException)
    {
        Node* z = it._current;
        if (z==NULL)
        {
            throw DynamicSetRangeException();
        }
        if (z->left == NULL)
        {
            transplant(z, z->right);
        }
        else if (z->right == NULL)
        {
            transplant(z, z->left);
        }
        else
        {
            Node* y=z->right;
            while (y->left != NULL)
            {
                y = y->left;
            }
            if (y->parent != z)
            {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
        --_size;
    }

    template <class T>
    int BinaryTree<T>::maxHeight(const Node* p) const
    {
        if (p == NULL)
        {
            return 0;
        }
        int leftHeight = maxHeight(p->left);
        int rightHeight = maxHeight(p->right);
        return (leftHeight > rightHeight) ? leftHeight + 1: rightHeight + 1;
    }

    template <class T>
    std::ostream& operator<<(std::ostream& out, const BinaryTree<T>& t)
    {
      const int level=1;
      const int indentSpace=0;
      int h = t.maxHeight(t._root);
      int nodesInThisLevel = 1;

      int branchLen = 2*((1<<h)-1) - (3-level)*(1<<(h-1));  // eq of the length of branch for each node of each level
      int nodeSpaceLen = 2 + (level+1)*(1<<h);  // distance between left neighbor node's right arm and right neighbor node's left arm
      int startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)

      std::deque< typename BinaryTree<T>::Node* > nodesQueue;
      nodesQueue.push_back(t._root);
      for (int r = 1; r < h; r++)
      {
        t.printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
        branchLen = branchLen/2 - 1;
        nodeSpaceLen = nodeSpaceLen/2 + 1;
        startLen = branchLen + (3-level) + indentSpace;
        t.printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

        for (int i = 0; i < nodesInThisLevel; i++) {
          typename BinaryTree<T>::Node* currNode = nodesQueue.front();
          nodesQueue.pop_front();
          if (currNode) {
           nodesQueue.push_back(currNode->left);
           nodesQueue.push_back(currNode->right);
          } else {
            nodesQueue.push_back(NULL);
            nodesQueue.push_back(NULL);
          }
        }
        nodesInThisLevel *= 2;
      }
      t.printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
      t.printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
      return out;
    }

    // Print the arm branches (eg, /    \ ) on a line
    template <class T>
    void BinaryTree<T>::printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const std::deque<BinaryTree<T>::Node*>& nodesQueue, std::ostream& out) const
    {
      typename std::deque< typename BinaryTree<T>::Node* >::const_iterator iter = nodesQueue.begin();
      for (int i = 0; i < nodesInThisLevel / 2; i++) {
        out << ((i == 0) ? std::setw(startLen-1) : std::setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
        out << std::setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
      }
      out << std::endl;
    }

    // Print the branches and node (eg, ___10___ )
    template <class T>
    void BinaryTree<T>::printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const std::deque<BinaryTree<T>::Node*>& nodesQueue, std::ostream& out) const
    {
      typename std::deque< typename BinaryTree<T>::Node* >::const_iterator iter = nodesQueue.begin();
      for (int i = 0; i < nodesInThisLevel; i++, iter++)
      {
        std::ostringstream ss("");
        if (*iter)
        {
            ss << (*iter)->info;
        }
        out << ((i == 0) ? std::setw(startLen) : std::setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->left) ? std::setfill('_') : std::setfill(' '));
        out << std::setw(branchLen+2) << ss.str();
        out << ((*iter && (*iter)->right) ? std::setfill('_') : std::setfill(' ')) << std::setw(branchLen) << "" << std::setfill(' ');
      }
      out << std::endl;
    }

    // Print the leaves only (just for the bottom row)
    template <class T>
    void BinaryTree<T>::printLeaves(int indentSpace, int level, int nodesInThisLevel, const std::deque<BinaryTree<T>::Node*>& nodesQueue, std::ostream& out) const
    {
      typename std::deque< typename BinaryTree<T>::Node* >::const_iterator iter = nodesQueue.begin();
      for (int i = 0; i < nodesInThisLevel; i++, iter++)
      {
        std::ostringstream ss("");
        if (*iter)
        {
            ss << (*iter)->info;
        }
        out << ((i == 0) ? std::setw(indentSpace+2) : std::setw(2*level+2)) << ss.str();
      }
      out << std::endl;
    }

    template <class T>
    const T& BinaryTree<T>::iterator::operator*() const
    {
        return this->_current->info;
    }

    template <class T>
    typename BinaryTree<T>::iterator& BinaryTree<T>::iterator::operator++()
    {
        _current = _current->successor();
        return *this;
    }

    class BinaryTreeTestCase : public CppUnit::TestFixture
    {
    private:
        BinaryTree<int>* _empty;
        BinaryTree<int>* _t;
        BinaryTree<int>* _t2;
        BinaryTree<int>* _t3;

    public:
        static CppUnit::Test* suite();

        void setUp();
        void tearDown();

    protected:
        void testCreation();
        void testPushMinMax();
        void testErase();
        void testIterator();
    };
}

#endif // ALGORITHM_DATASTRUCTURES_BINARYTREE_H
