#include <iostream>
#include <iomanip>
#include <locale>
#include <limits>
#include <cmath>
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

int quick_partition(int* A, int p, int r)
{
    int x=A[r-1];
    int i=p-1;
    int temp;

    for (int j=p; j<=r-1; ++j)
    {
        if (A[j-1]<=x)
        {
            ++i;
            temp=A[i-1];
            A[i-1]=A[j-1];
            A[j-1]=temp;
        }
    }
    temp=A[i];
    A[i]=A[r-1];
    A[r-1]=temp;

    return i+1;
}

void quick_sort(int* A, int p, int r)
{
    if (p<r)
    {
        int q=quick_partition(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
    }
}

void quick_sort(int* A, int length)
{
    quick_sort(A, 1, length);
}

void print_array(int* A, int length)
{
    for (int i=0; i<length; ++i)
        std::cout<<A[i]<<" ";
    std::cout<<std::endl;
}

double normal(double mu, double sigma)
{
	const double epsilon = std::numeric_limits<double>::min();
	const double two_pi = 2.0*3.14159265358979323846;
	const double ee = 1.0 / RAND_MAX;

	static double z0, z1;
	static bool generate;
	generate = !generate;

	if (!generate)
	   return z1 * sigma + mu;

	double u1, u2;
	do
	 {
	   u1 = rand() * ee;
	   u2 = rand() * ee;
	 }
	while ( u1 <= epsilon );

	const double l=-2.0*log(u1);
	const double r=two_pi * u2;

	z0 = sqrt(l) * cos(r);
	z1 = sqrt(l) * sin(r);
	return z0 * sigma + mu;
}

void init_array(int* &a, int N, int mode=0)
{
    switch (mode)
    {
    case 1:
        {
            // normal
            const double k = RAND_MAX/6.0;
            a = new int[N];
            for (int i=0; i<N; ++i)
            {
                double d=normal(0.0, 1.0);
                int x=0;
                if (d>=3.0)
                {
                    x=RAND_MAX;
                }
                else if (d<3.0 && d>-3.0)
                {
                    x=(d+3.0)*k;
                }
                a[i] = x;
            }
        }
        break;
    case 0:
    default:
        {
            // uniform
            a = new int[N];
            for (int i=0; i<N; ++i)
            {
                a[i] = rand() % N;
            }
        }
        break;
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

void small_test_quick()
{
    const int N=8;
    int A[] = {2, 8, 7, 1, 3, 5, 6, 4};

    print_array(A, N);
    quick_sort(A, N);
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
    case 3:
        quick_sort(A, N);
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
    const int S=3;
    const int sortType[S] = {
        0,  // 0: heap
        2,  // 2: merge
        3   // 3: quick
    };
    int* A;
    double elapsed;

    init_array(A, N, 0);    // 0: uniform; 1: gaussian

    std::cout.imbue(std::locale("en_US.UTF-8"));
    std::cout << std::setw(12) << N;

    for (int s=0; s<S; ++s)
    {
        elapsed = large_test(A, N, sortType[s]);
        std::cout << "\t" << std::setw(12) <<std::setprecision(3) << elapsed;
    }

    delete A;
    std::cout<<std::endl;
}

int main()
{
    const int NTests=19;
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
    std::cout<<"\t" << std::setw(12) << "HEAP";
    std::cout<<"\t" << std::setw(12) << "MERGE";
    std::cout<<"\t" << std::setw(12) << "QUICK";
    std::cout<<std::endl;

    for (int i=0; i<NTests; ++i)
    {
        one_step(tests[i]);
    }

    return 0;
}
