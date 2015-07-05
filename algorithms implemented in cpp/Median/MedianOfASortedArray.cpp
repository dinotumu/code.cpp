#include <iostream>
#include <cstdlib>
#include <sys/time.h>
using namespace std;

void bubbleSort(int array[], int size);

int main()
{
    int array[11];
    int n = sizeof(array)/sizeof(*array);

    srand(time(0));
    for(int i = 0 ; i < n ; i++)
        array[i] = 1 + (rand()%1000);

    for(int i = 0 ; i < n ; i++)
        cout<<array[i]<<"\t";

    cout<<endl;

    bubbleSort(array, n);

    for(int i = 0 ; i < n ; i++)
        cout<<array[i]<<"\t";

    cout<<endl;

    if(n%2 == 0)
        // For even Number of values, median is the average of the middle values
        cout<<"The median of the array is : "<<(array[n/2] + array[n/2 - 1])/2<<endl;
    else
        // For odd Number of values, median is the middle value
        cout<<"The median of the array is : "<<array[(n - 1)/2]<<endl;
}

void bubbleSort(int array[], int size)
{
    int temp = 0, flag = 0;

    // In each pass, the largest element in the unsorted part will bubble up to the highest index in the unsorted part.
    // After size-1 passes, list is sorted.
    for(int pass = 1 ; pass <= size-1 ; pass++)
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

