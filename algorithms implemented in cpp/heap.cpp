#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#define size_for_initialisation 100
using namespace std;

class minHeap
{
private:
    int heap[size_for_declaring];
    int index_of_heap;
    void minHeapify();

public:
    minHeap(){}
    void createHeap();
    void insert(int element);
    int findMin();
    void deleteKey();
    void deleteMin();
    int extractMin();
    void displayHeap();
    void decreaseKey();
    int size();
};


int minHeap::size()
{
    return index_of_heap;
}

void minHeap::createHeap()
{
    heap[size_for_initialisation] = {0};
    index_of_heap = 0;
}

void minHeap::insert(int element)
{
    index_of_heap++;
    heap[index_of_heap] = element;
    buildMinHeap();
}

void minHeap::buildMinHeap()
{

}

void minHeap::deleteMin()
{
    swap(heap[1], heap[index_of_heap--]);
    buildMaxHeap();
}

int main()
{

}
