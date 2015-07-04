// Simple linear search method and DAC method
#include <iostream>
#include <cstdlib>
#include <sys/time.h>
using namespace std;

// Instead of returning two variables, we pass and return objects
class Pair
{
    public:
    int min, max;

    Pair()
    {
        min = 0, max = 0;
    }
};

// Function prototype for finding min and max using linear search
void linear_MinAndMax(int array[], int size);
// Function prototype for finding min and max using Divide and Conquer
// Function prototype for returning object of type class pair
Pair DAC_MinAndMax(int array[], int low, int high);

int main()
{
    int array[20];
    int n = sizeof(array)/sizeof(*array);

    srand(time(0));
    for(int i = 0 ; i < n ; i++)
        array[i] = 1 + (rand() % 10000);

    // Function call for finding min and max using linear search
    linear_MinAndMax(array, n);

    // min and max using DAC
    // Function call for finding min and max using linear search
    Pair result;
    result = DAC_MinAndMax(array, 0, n-1);
    cout<<"Max: "<<result.max<<" Min: "<<result.min<<endl;
}

void linear_MinAndMax(int array[], int size)
{
    int min, max;
    min = max = array[0];

    for(int i = 0 ; i < size ; i++)
    {
        // If we find array[i] equals to max or min, we don't change the value of min or max.
        // So, that case is not written here.
        if(array[i] > max)
            max = array[i];
        else if(array[i] < min)
            min = array[i];
    }
    cout<<"Max: "<<max<<" Min: "<<min<<endl;
}

Pair DAC_MinAndMax(int array[], int low, int high)
{
    Pair result, left, right;
    // if there is only one element
    if(low == high)
    {
        result.max = result.min = array[0];
        return result;
    }
    else
    {
        // if there are two elements
        if(low == high - 1)
        {
            if(array[low] < array[high])
            {
                result.max = array[high];
                result.min = array[low];
                return result;
            }
            else
            {
                result.max = array[low];
                result.min = array[high];
                return result;
            }
        }
        else
        {
            // if there are more than two elements
            int mid = low + (high - low)/2;
            left = DAC_MinAndMax(array, low, mid);
            right = DAC_MinAndMax(array, mid + 1, high);

            if (left.min < right.min)
                result.min = left.min;
            else
                result.min = right.min;

            if (left.max > right.max)
                result.max = left.max;
            else
                result.max = right.max;

            return result;
        }
    }
}
