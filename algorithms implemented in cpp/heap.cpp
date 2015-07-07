#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#define size 100
using namespace std;

class minHeap
{
private:
    int heap[size];
    int nHeap;
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
    return nHeap;
}

void minHeap::createHeap()
{
    heap[size] = {0};
    nHeap = 0;
}

void minHeap::insert(int element)
{
    nHeap++;
    heap[nHeap] = element;
    buildMinHeap();
}

void minHeap::buildMinHeap()
{

}

int main()
{

}
