#include <iostream>
using namespace std;

// Source: http://www.geeksforgeeks.org/binary-search-preferred-ternary-search/


// A recursive ternary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
int ternarySearch_Recursive(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid1 = l + (r - l)/3;
        int mid2 = mid1 + (r - l)/3;

        // If x is present at the mid1
        if (arr[mid1] == x)  return mid1;

        // If x is present at the mid2
        if (arr[mid2] == x)  return mid2;

        // If x is present in left one-third
        if (arr[mid1] > x) return ternarySearch(arr, l, mid1-1, x);

        // If x is present in right one-third
        if (arr[mid2] < x) return ternarySearch(arr, mid2+1, r, x);

        // If x is present in middle one-third
        return ternarySearch(arr, mid1+1, mid2-1, x);
   }
   // We reach here when element is not present in array
   return -1;
}

int main()
{
    int array[10];
    int n = sizeof(array)/sizeof(*array);

    srand(time(0));
    for(int i = 0 ; i < n ; i++)
        array[i] = 1 + (rand() % 10000);

    bubbleSort(array, n);

    int output = ternarySearch_Recursive(array, 0, n-1, 6);

    if(output == -1)
        cout<<endl<<"Key NOT found"<<endl;
    else
        cout<<endl<<"Key is found at "<<output<<endl;
}
