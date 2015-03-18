#include <iostream>

inline int left(int i) { return i<<1; }
inline int right(int i) { return (i<<1)+1; }

void max_heapify(int* A, int heap_size, int i)
{
    int l=left(i);
    int r=right(i);

    int largest;
    if (l<=heap_size && A[l-1]>A[i-1])
    {
        largest=l;
    }
    else
    {
        largest=i;
    }
    if (r<=heap_size && A[r-1]>A[largest-1])
    {
        largest=r;
    }
    if (largest!=i)
    {
        int temp=A[i-1];
        A[i-1]=A[largest-1];
        A[largest-1]=temp;
        max_heapify(A, heap_size, largest);
    }
}

void build_max_heap(int* A, int length)
{
    int heap_size = length;
    for (int i=length>>1; i>=1; --i)
    {
        max_heapify(A, heap_size, i);
    }
}

void print_array(int* A, int length)
{
    for (int i=0; i<length; ++i)
        std::cout<<A[i]<<" ";
    std::cout<<std::endl;
}

int main()
{
    const int N=10;
    int A[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

    print_array(A, N);
    build_max_heap(A, N);
    print_array(A, N);
    return 0;
}
