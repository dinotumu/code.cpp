#include <iostream>
#include <cstdlib>  // For rand() function
#include <sys/time.h> // For time() function
using namespace std;

void bubbleSort(int array[], int size);
bool binarySearch(int array[], int size,int key);

int main()
{
    int array[100];
    int n = sizeof(array);

    srand(time(0));
    for(int i=0; i<n; i++)
        cout<< 1+(rand()%1000) <<endl;

    bubbleSort(array,n);

    cout<<"Enter the key to search"<<endl;
    cin>>key;
    int toSearchFor = key;
    int result=binarySearch(array,n,key);

    if(result==1)
        cout<<"\n\t\t\tKey Found in Array "<<endl;
    else
        cout<<"\n\t\t\tKey NOT Found in Array "<<endl;
    return 0;
}

void bubbleSort(int array[], int size)
{
    int temp;
    for(int i2=0; i2<size; i2++)
    {
        for(int j=0; j<size-1; j++)
        {
            if(array[j]>array[j+1])
            {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}

bool binarySearch(int array[],int size, int key)
{
    int start=1, end=size;
    int mid=(start+end)/2;

    while(start<=end&&array[mid]!=key)
    {
        if(array[mid]<key)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
        mid=(start+end)/2;
    }

    if(array[mid]==key)
        return true;
    else
        return false;
}
