#include<iostream>
using namespace std;

inline double cube( double side )
{
    return side * side * side; // calculate the cube of side
}

int main()
{
    double sideValue; // stores value entered by user

    for ( int i = 1; i <= 3; i++ )
    {
        cout << "\nEnter the side length of your cube: \n";
        cin >> sideValue;
        cout << "Volume of cube with side "
             << sideValue <<" is "<<cube(sideValue)<< endl;
    }
}
