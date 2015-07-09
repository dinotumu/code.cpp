/*  Median Search Problem
Case 1: Let X[1,....,n] and Y[1,.....,n] be two arrays, each containing n numbers already in sorted order.
Find the median of all 2n numbers.
Case 2: Let X[1,....,p] and Y[1,.....,q] be two arrays, containing p numbers in array X and q numbers in array Y, already in sorted order.
Find the median of all m = p+q numbers.
*/

#include <iostream>
#include <cstdlib>
#include <sys/time.h>
// we can use these utility functions(below) or can include "#include <algorithm>"
// #define max(x, y) return x > y? x : y;
// #define min(x, y) return x > y? y : x;
#include <algorithm>

using namespace std;

int medianOfASortedArray(int array[], int n);
int getMedian(int array1[], int array2[], int size);
void bubbleSort(int array[], int size);

int main()
{
    int array1[10];
    int array2[10];
    int n1 = sizeof(array1)/sizeof(*array1);
    int n2 = sizeof(array2)/sizeof(*array2);

    srand(time(0));
    for(int i = 0 ; i < n1 ; i++)
        array1[i] = 1 + (rand()%1000);

    for(int i = 0 ; i < n1 ; i++)
        array2[i] = 1 + (rand()%1000);

    bubbleSort(array1, n1);
    bubbleSort(array2, n2);

    if (n1 == n2)
        cout<<"Median is "<<getMedian(array1, array2, n1);
    else
        cout<<"Doesn't work for arrays of unequal size";
}

int getMedian(int array1[], int array2[], int size)
{
    int m1; /* For median of array1 */
    int m2; /* For median of array2 */

    if (size == 1)
        return (array1[0] + array2[0])/2;
    else if (size == 2)
        return (max(array1[0], array2[0]) + min(array1[1], array2[1])) / 2;
    else
    {
        m1 = medianOfASortedArray(array1, size);
        m2 = medianOfASortedArray(array2, size);

        if (m1 == m2)
            return m1;
        // if m1 < m2 then median must exist in array1[m1....] and array2[....m2]
        else if(m1 < m2)
        {
            if (size % 2 == 0)
                return getMedian(array1 + size/2 - 1, array2, size - size/2 +1);
            else
                return getMedian(array1 + size/2, array2, size - size/2);
        }
        // if m1 > m2 then median must exist in array1[....m1] and array2[m2...]
        else
        {
            if (size % 2 == 0)
                return getMedian(array2 + size/2 - 1, array1, size - size/2 + 1);
            else
                return getMedian(array2 + size/2, array1, size - size/2);
        }
    }
}

int medianOfASortedArray(int array[], int n)
{
    if (n%2 == 0)
        // Number of elements are even
        return (array[n/2] + array[n/2-1])/2;
    else
        // Number of elements are odd
        return array[n/2];
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
