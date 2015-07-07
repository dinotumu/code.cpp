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

Pair Tournament_MinAndMax(int array[], int n);

int main()
{
    int array[20];
    int n = sizeof(array)/sizeof(*array);

    srand(time(0));
    for(int i = 0 ; i < n ; i++)
        array[i] = 1 + (rand() % 10000);

    for(int i = 0 ; i < n ; i++)
        cout<<array[i]<<"\t";

    Pair result;
    result = Tournament_MinAndMax(array, n-1);
    cout<<"Max: "<<result.max<<" Min: "<<result.min<<endl;
}

Pair Tournament_MinAndMax(int array[], int n)
{
    Pair result;
    int i;

    // n = even
    if (n%2 == 0)
    {
        if (array[0] > array[1])
        {
            result.max = array[0];
            result.min = array[1];
        }
        else
        {
            result.min = array[0];
            result.max = array[1];
        }
        i = 2;
    }
    // n = odd
    else
    {
        result.min = array[0];
        result.max = array[0];
        i = 1;
    }

    while (i < n-1)
    {
        if (array[i] > array[i+1])
        {
            if(array[i] > result.max)
                result.max = array[i];
            if(array[i+1] < result.min)
                result.min = array[i+1];
        }
        else
        {
            if (array[i+1] > result.max)
                result.max = array[i+1];
            if (array[i] < result.min)
                result.min = array[i];
        }
        i += 2;
    }
    return result;
}
