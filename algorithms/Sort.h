
#ifndef ALGORITHM_SORT_H
#define ALGORITHM_SORT_H

namespace sort
{
    // heap

    void heap_sort(int* A, int length);

    namespace
    {
        inline int left(int i) { return i<<1; }
        inline int right(int i) { return (i<<1)+1; }

        void max_heapify(int* A, int heap_size, int i);
        void build_max_heap(int* A, int length, int& heap_size);
    }

    // insertion

    void insertion_sort(int* A, int length);

    // merge

    void merge_sort(int* A, int length);

    namespace
    {
        // p, q, and r are 1-based indices
        void merge_two_subarrays(int* A, int p, int q, int r);
        void merge_sort(int* A, int p, int r);
    }

    // quick

    void quick_sort(int* A, int length);

    namespace
    {
        int quick_partition(int* A, int p, int r);
        void quick_sort(int* A, int p, int r);
    }
}

#endif // ALGORITHM_SORT_H
