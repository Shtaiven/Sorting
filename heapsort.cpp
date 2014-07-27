#include <algorithm> // for std::make_heap, std::sort_heap
 
template <typename Iterator>
void heapSort(Iterator begin, Iterator end)
{
    std::make_heap(begin, end);
    std::sort_heap(begin, end);
}