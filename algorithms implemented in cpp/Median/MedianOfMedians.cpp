#include <iostream>
#include <cstdlib>
#include <sys/time.h>
using namespace std;

void bubbleSort(int start, int end);
int select(int array[], int start, int end, int k);

int array[11];

int main()
{
    int n = sizeof(array)/sizeof(*array);

    srand(time(0));
    for(int i = 0 ; i < n ; i++)
        array[i] = 1 + (rand()%1000);

    for(int i = 0 ; i < n ; i++)
        cout<<array[i]<<"\t";

    cout<<endl;

    int mom = select(array, 0, n-1, n/2);
    cout<<"Median of Medians: " << array[mom] << endl;
}

int select(int array, int start, int end, int k)
{
    int temp = 0;

    if(end - start + 1 <= 5)
    {
        bubbleSort(start, end);
        return start + k - 1;
    }

    for(int i = 0 ; i < (end + 1)/5 ; i++)
    {
        int left = 5*i;
        int right = left + 4;
        if(right > end) right = end;

        int median = select(array, left, right, 3);
        temp = array[median];
        array[median] = array[i];
        array[i] = temp;
    }
    return select(array, 0, (end + 1)/5, (end + 1)/10);
}

void bubbleSort(int start, int end)
{
    int temp = 0, flag = 0;
    int size = end - start;

    // In each pass, the largest element in the unsorted part will bubble up to the highest index in the unsorted part.
    // After size-1 passes, list is sorted.
    for(int pass = start ; pass <= size-1 ; pass++)
    {
        int flag = 0;
        // No need to sort the sorted part of the array.
        // Also, value of i+1 should not be 'size' as it cannot be accessible. So, size-pass-1.
        for(int i = 0 ; i <= size-pass-1 ; i++)
            if(array[i] > array[i+1])
            {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                flag=1;
            }
        // If we go through a pass without swapping, then the list is already sorted.
        if(flag == 0) break;
    }
}
