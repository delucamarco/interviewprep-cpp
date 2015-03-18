#include <iostream>
#include <iomanip>
#include <limits>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "Common.h"

inline int left(int i) { return i<<1; }
inline int right(int i) { return (i<<1)+1; }

void max_heapify(int* A, int heap_size, int i)
{
    const int l_=left(i)-1;
    const int r_=right(i)-1;
    const int i_=i-1;

    int largest_;
    if (l_<heap_size && A[l_]>A[i_])
    {
        largest_=l_;
    }
    else
    {
        largest_=i_;
    }
    if (r_<heap_size && A[r_]>A[largest_])
    {
        largest_=r_;
    }

    if (largest_!=i_)
    {
        int temp=A[i_];
        A[i_]=A[largest_];
        A[largest_]=temp;
        max_heapify(A, heap_size, largest_+1);
    }
}

void build_max_heap(int* A, int length, int& heap_size)
{
    heap_size = length;
    for (int i=length>>1; i>=1; --i)
    {
        max_heapify(A, heap_size, i);
    }
}

void heap_sort(int* A, int length)
{
    int heap_size;
    build_max_heap(A, length, heap_size);
    for (int i=length-1; i>0; --i)
    {
        int temp=A[0];
        A[0]=A[i];
        A[i]=temp;
        heap_size-=1;
        max_heapify(A, heap_size, 1);
    }
}

void insertion_sort(int* A, int length)
{
    for (int j=1; j<length; ++j)
    {
        int key=A[j];
        int i=j-1;
        while (i>=0 && A[i]>key)
        {
            A[i+1]=A[i];
            --i;
        }
        A[i+1]=key;
    }
}

// p, q, and r are 1-based indices
void merge_two_subarrays(int* A, int p, int q, int r)
{
//  const int q_=q-1;
    const int p_=p-1;
    const int r_=r-1;
    const int n1=q-p+1;
    const int n2=r-q;
    int* L=new int[n1+1];
    int* R=new int[n2+1];

    std::copy(A+p_, A+p_+n1, L);
    L[n1]=std::numeric_limits<int>::max();

    std::copy(A+q, A+q+n2, R);
    R[n2]=std::numeric_limits<int>::max();

    int i=0, j=0;
    for (int k=p_; k<=r_; ++k)
    {
        if (L[i]<=R[j])
        {
            A[k]=L[i];
            ++i;
        }
        else
        {
            A[k]=R[j];
            ++j;
        }
    }

    delete L;
    delete R;
}

void merge_sort(int* A, int p, int r)
{
    if (p<r)
    {
        int q=(p+r)>>1;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge_two_subarrays(A, p, q, r);
    }
}

void merge_sort(int* A, int length)
{
    merge_sort(A, 1, length);
}

void print_array(int* A, int length)
{
    for (int i=0; i<length; ++i)
        std::cout<<A[i]<<" ";
    std::cout<<std::endl;
}

void init_array(int* &a, int N)
{
    a = new int[N];
    for (int i=0; i<N; ++i)
    {
        a[i] = rand() % N;
    }
}

void small_test_insertion()
{
    const int N=6;
    int A[] = {5, 2, 4, 6, 1, 3};

    print_array(A, N);
    insertion_sort(A, N);
    print_array(A, N);
}

void small_test_merge()
{
    const int N=8;
    int A[] = {2, 4, 5, 7, 1, 2, 3, 6};

    print_array(A, N);
    merge_sort(A, N);
    print_array(A, N);
}

double large_test(const int* _A, int N, int type)
{
    common::Chronometer c;
    int* A=new int[N];

    std::copy(_A, _A+N, A);

    c.start();
    switch (type)
    {
    case 0:
        heap_sort(A, N);
        break;
    case 1:
        insertion_sort(A, N);
        break;
    case 2:
        merge_sort(A, N);
        break;
    default:
        std::cerr << "Unknown sort type" <<std::endl;
        delete A;
        return -1.0;
    }
    double elapsed = c.stop();

    delete A;
    return elapsed;
}

void one_step(int N)
{
    int* A;
    double elapsed;

    init_array(A, N);

    std::cout << std::setw(12) << N;
    elapsed = large_test(A, N, 0);  // 0: heap
    std::cout << ",\t" << std::setw(12) <<std::setprecision(3) << elapsed;
    elapsed = large_test(A, N, 2);  // 2: merge
    std::cout << ",\t" << std::setw(12) <<std::setprecision(3)<< elapsed;
    //elapsed = large_test(A, N, 1);  // 1: insertion
    elapsed=0;
    std::cout << ",\t" << std::setw(12) <<std::setprecision(3)<< elapsed;

    std::cout<<std::endl;

    delete A;
}

int main()
{
    const int NTests=25;
    int tests[] = {     10, 20, 50,
                        100, 200, 500,
                        1000, 2000, 5000,
                        10000, 20000, 50000,
                        100000, 200000, 500000,
                        1000000, 2000000, 5000000,
                        10000000, 20000000, 50000000,
                        100000000, 200000000, 500000000,
                        1000000000};

    srand(time(NULL));

    std::cout<<std::setw(12)<<"N";
    std::cout<<",\t" << std::setw(12) << "HEAP";
    std::cout<<",\t" << std::setw(12) << "MERGE";
    std::cout<<",\t" << std::setw(12) << "INSERTION";
    std::cout<<std::endl;

    for (int i=0; i<NTests; ++i)
    {
        one_step(tests[i]);
    }

    return 0;
}
