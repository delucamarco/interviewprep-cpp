#include <iostream>
#include "morgan.h"

namespace morgan
{
    void Consumer::receive(const Message& m)
    {
        db_type::const_iterator hit=db.find(m.id);
        if (hit == db.end())
        {
            // first sequence no. for this ID
            db[m.id]=Bucket();
        }
        Bucket& bucket=db[m.id];

        if (bucket.next == m.seq)
        {
            // consume m
            consume(m.id, m.seq);
            ++bucket.next;

            while (!bucket.q.empty())
            {
                int seq=bucket.q.top();
                if (seq!=bucket.next)
                {
                    break;
                }
                consume(m.id, seq);
                ++bucket.next;
                bucket.q.pop();
            }
        }
        else
        {
            // enqueue
            bucket.q.push(m.seq);
        }
    }

    void Consumer::consume(id_type id, seq_type seq)
    {
        std::cout<<"[id="<<id<<",seq="<<seq<<"]"<<std::endl;
    }

    void myreverse(std::string::iterator from, std::string::iterator to)
    {
        for(std::string::reverse_iterator rb(to);
    }

    void test()
    {
        Message m;
        Consumer c;

        m.id=1; m.seq=1; c.receive(m);
        m.id=2; m.seq=1; c.receive(m);
        m.id=1; m.seq=3; c.receive(m);
        m.id=1; m.seq=4; c.receive(m);
        m.id=1; m.seq=2; c.receive(m);

        std::string s="goedel";
        std::cout << "s =\t\t" << s << std::endl;

        std::reverse(s.begin(), s.end());
        std::cout<< "s reversed =\t" << s << std::endl;

        std::string::iterator b=s.begin();
        std::string::reverse_iterator rb(s.end());
        std::string::iterator e=rb.base()-1;

        std::cout << "b = " << *b
                << " e = " << *e
                << " rb = " << *rb
                << std::endl;

//        for(; b>rb.base(); ++b, ++rb)
//        {
//            std::swap(b, rb.base());
//        }
//        std::cout << "s =\t\t" << s << std::endl;
    }
}
