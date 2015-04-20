#include <iostream>
#include "engine.h"

using namespace std;

namespace engine
{
    void test()
    {
        const int minPrice=1, maxPrice=400;

        // 1. setup OrderBook
        OrderBook* ob = new OrderBook(minPrice, maxPrice);

        // 2. create order
        Order* o = Order::createOrder(Buy, 10, 99);

        // 3. send order to engine
        ob->accept(o);

        // 4. print OrderBook
        cout << *ob << endl;

        // 5. cleanup
        delete ob;
        delete o;
    }

    unsigned int Order::lastID = 0;

    Order::Order(Direction d, int qty, int prc, unsigned int ts) :
        side(d), quantity(qty), price(prc), timestamp(ts)
    {
    }

    Order* Order::createOrder(Direction d, int qty, int prc)
    {
        return new Order(d, qty, prc, Order::lastID++);
    }

    OrderBook::OrderBook(int minPrice, int maxPrice) :
        _minPrice(minPrice), _maxPrice(maxPrice)
    {
    }

    void OrderBook::accept(Order* newOrder)
    {
        if (!newOrder
            || newOrder->price < _minPrice
            || newOrder->price > _maxPrice
            || newOrder->quantity < 1)
        {
            throw engine_exception();
        }

        // my side == buy
    }

    ostream& operator<<(ostream& os, const OrderBook& ob)
    {
        // TODO
        return os;
    }

//    using namespace std;
//
//    bool cmpBuy(int x, int y) { return x<y; }
//    bool cmpSell(int x, int y) { return x>y; }
//
//    void f()
//    {
//        typedef int price_type;
//        typedef int level_type;
//        typedef map<price_type, level_type, bool(*)(price_type, price_type) > side_type;
//
//        level_type dummyLevel=0;
//
//        int bv[] = { 60, 80, 70, 90 };
//        side_type buyside(cmpBuy);
//        for (int i=0; i<4; ++i)
//        {
//            price_type p=bv[i];
//            buyside[p]=dummyLevel;
//        }
//
//        int sv[] = { 160, 180, 170, 190 };
//        side_type sellside(cmpSell);
//        for (int i=0; i<4; ++i)
//        {
//            price_type p=sv[i];
//            sellside[p]=dummyLevel;
//        }
//
//        side_type *bs = &buyside, *as=&sellside;
//        cout << "Bid\tAsk" << endl;
//        side_type::const_iterator bit=bs->begin(), ait=as->begin();
//        while (bit!=bs->end() || ait!=as->end())
//        {
//            if (bit!=bs->end())
//            {
//                cout << bit->first;
//                ++bit;
//            }
//            cout << '\t';
//
//            if (ait!=as->end())
//            {
//                cout << ait->first;
//                ++ait;
//            }
//            cout << endl;
//        }
//        cout<<endl;
//
//        // O(1)
//        price_type bbid=buyside.begin()->first, bask=sellside.begin()->first;
//        cout << "bbid\tbask" << endl << bbid << '\t' << bask << endl;
//
//        int p;
//        do
//        {
//            cin >> p;
//
//            if (p>0)
//            {
//                side_type::const_iterator l=bs->lower_bound(p), u=bs->upper_bound(p);
//                cout << "Bid. lower_bound: " << l->first << " upper_bound: " << u->first << endl;
//
//                l=as->lower_bound(p);
//                u=as->upper_bound(p);
//                cout << "Ask. lower_bound: " << l->first << " upper_bound: " << u->first << endl;
//            }
//            else if (p==0)
//            {
//                side_type *bs = &buyside, *as=&sellside;
//                cout << endl << "Bid\tAsk" << endl;
//                side_type::const_iterator bit=bs->begin(), ait=as->begin();
//                while (bit!=bs->end() || ait!=as->end())
//                {
//                    if (bit!=bs->end())
//                    {
//                        cout << bit->first;
//                        ++bit;
//                    }
//                    cout << '\t';
//
//                    if (ait!=as->end())
//                    {
//                        cout << ait->first;
//                        ++ait;
//                    }
//                    cout << endl;
//                }
//                cout<<endl;
//            }
//        }
//        while (p>=0);
//    }

}

