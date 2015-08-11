#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    int n, ans;
    cin>>n;
    int num[n];

    for(int i = 0 ; i < n ; i++)
        cin>>num[i];

    ans = num[0];
    for(int i = 1 ; i < n ; i++)
        ans = gcd(ans,num[i]);

    cout<<ans;
    return 0;
}
