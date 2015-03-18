#ifndef SCRATCH_SIMPLELIST_H
#define SCRATCH_SIMPLELIST_H

namespace scratch
{

    class SimpleList
    {
        public:
            SimpleList();
            virtual ~SimpleList();

            void push_back(int i);
            void push_front(int i);
            void print();

        private:

            struct Node
            {
                int info;
                Node* next;
            };

            Node* head;
            Node* tail;
    };

    void testSimpleList();

}

#endif // SCRATCH_SIMPLELIST_H
