// One word don't use them debugging is difficult
#include<iostream>

// this is for multiple lines
#define swap(x,y,t)  {t=x; \
                      x=y; \
                      y=t;}

// single line
#define compare(x,y)  (x<y?-1:(x==y)?0:1)
// you can define swap function in this way too
#define swap(x,y) int t; t=x; x=y; y=t;

using namespace std;

int main()
{
    // If we try to define these variables using #define x 4 etc., compiler gives an error
    int t=0, x=5, y=10;
    swap(x,y,t);
    cout<<"after swapping x="<<x<<" and y= "<<y<<endl;
    cout<<"after comparing" <<compare(x,y);
}

