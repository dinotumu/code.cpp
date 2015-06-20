// Universal Scope Resolution Operator to define a function (public) of a class outside the class.
#include <iostream>
using namespace std;
// Only public functions can be declared in this way.
// Prototype should declared under the public access specifier of the respective class.
// Function should'nt be declared twice.

class Dino
{
public:
    //void dinesh(int a){
    //cout<<a<<endl;
    //}
    void dinesh();
};

void Dino::dinesh()
{
    int a=10;
    cout<<a*a;
}

int main()
{
    Dino d;
    d.dinesh();
}
