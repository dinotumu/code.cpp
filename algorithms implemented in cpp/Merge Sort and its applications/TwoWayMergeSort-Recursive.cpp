#include <iostream>
#include <cstdlib>
#include <sys/time.h>
using namespace std;

void twoWayMergeSort_Recursive(int array[], int low, int high);
void mergeTwoSortedArrays(int array[], int low, int mid, int high);

int main()
{
    int array[10];
    int n = sizeof(array)/sizeof(*array);

    srand(time(0));
    for(int i = 0 ; i < n ; i++)
        array[i] = 1 + (rand() % 1000);

        for(int i = 0 ; i < n ; i++)
        cout<<array[i]<<"\t";


        cout<<endl;

    twoWayMergeSort_Recursive(array, 0, n-1);

    for(int i = 0 ; i < n ; i++)
        cout<<array[i]<<"\t";
}

void twoWayMergeSort_Recursive(int array[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low)/2;
        twoWayMergeSort_Recursive(array, low, mid);
        twoWayMergeSort_Recursive(array, mid + 1, high);
        mergeTwoSortedArrays(array, low, mid, high);
    }
}

void mergeTwoSortedArrays(int array[], int low, int mid, int high)
{
    // (mid - low) + 1
    int nL = mid - low + 1;
    // high - (mid + 1) + 1
    int nR = high - mid;
    int left[nL], right[nR];

    // For copying elements of our original array into left and right, temporary arrays
    for(int i = 0 ; i < nL ; i++)
        left[i] = array[low + i];

    for(int j = 0 ; j < nR ; j++)
        right[j] = array[mid + j + 1];

    // Merge the temporary arrays back into a single sorted array
    int i = 0, j = 0;
    // the starting position in the original array
    int k = low;

    while (i < nL && j < nR)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        // since k is the position corresponding to original array, it should be incremented when an element is added to the array
        k++;
    }

    // Copy the remaining elements of left[], if there are any
    while (i < nL)
    {
        array[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[], if there are any
    while (j < nR)
    {
        array[k] = right[j];
        j++;
        k++;
    }
}
