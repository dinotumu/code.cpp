#include <iostream>
using namespace std;

int number = 7;
// global variable named number
// name of variables (local and global) can be different

int main()
{

double number = 10.5; // local variable named number

// display values of local and global variables

cout << "Local double value of number = " <<number
<< "\nGlobal int value of number = " << ::number << endl;

}
