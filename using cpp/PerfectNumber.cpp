/*
In number theory, a perfect number is a positive integer
that is equal to the sum of its proper positive divisors,
that is, the sum of its positive divisors excluding
the number itself (also known as its aliquot sum).
*/

#include<iostream>
using namespace std;

int main()
{
    int n,i=1,sum=0;
    cout << "Enter a number: ";
    cin >> n;
    while(i<n)
    {
        if(n%i==0)
            sum=sum+i;
        i++;
    }
    if(sum==n)
        cout << i << " is a perfect number\n";
    else
        cout << i << " is not a perfect number\n";
    return 0;
}
