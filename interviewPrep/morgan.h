#ifndef MORGAN_H
#define MORGAN_H

#include <iostream>
#include <ext/hash_map>
#include <queue>
#include <vector>

namespace morgan
{
    typedef int id_type;
    typedef int seq_type;
    struct Message
    {
        id_type id;
        seq_type seq;
    };

    class Consumer
    {
    public:
        void receive(const Message&);

    private:
        struct Bucket
        {
            seq_type next;
            std::priority_queue<seq_type, std::vector<seq_type>, std::greater<seq_type> > q;

            Bucket() : next(1) {}
        };

        typedef __gnu_cxx::hash_map<id_type, Bucket> db_type;
        db_type db;

        void consume(id_type id, seq_type seq);
    };

    void test();
}

#endif // MORGAN_H
