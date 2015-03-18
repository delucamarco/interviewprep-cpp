#include <iostream>

inline int parent(int i)
{
    return i>>1;
}

inline int left(int i)
{
    return i<<1;
}

inline int right(int i)
{
    return (i<<1)+1;
}

int main()
{
    int i = 5;
    std::cout << "i: " << i
        << " PARENT(i): " << parent(i)
        << " LEFT(i): " << left(i)
        << " RIGHT(i): " << right(i)
        << std::endl;
    return 0;
}
