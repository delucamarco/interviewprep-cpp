#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <exception>

using namespace std;

namespace engine
{
    void test();

    enum Direction
    {
        Buy,
        Sell
    };

    struct Order
    {
        static Order* createOrder(Direction, int, int);

        Direction side;
        int quantity;
        int price;
        unsigned int timestamp;

    private:
        static unsigned int lastID;

        Order(Direction, int, int, unsigned int);
    };

    class OrderBook
    {
    private:
        const int _minPrice, _maxPrice;

    public:
        OrderBook(int minPrice, int maxPrice);
        void accept(Order*);

        friend ostream& operator<<(ostream&, const OrderBook&);
    };

    ostream& operator<<(ostream&, const OrderBook&);

    class engine_exception : public exception {};
}

#endif // ENGINE_H
