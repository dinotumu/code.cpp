#include <iostream>
#include <string>
using namespace std;

char caesar( char c , int k )
{
    if( c >= 65 && c <= 90 )
        c = (((c-65)-k+26) % 26) + 65;
    else if( c >= 97 && c <= 122 )
        c = (((c-97)-k+26) % 26) + 97;
    return c;
}

int main()
{
    string input;
    int k;
    cin>>input;
    cin>>k;
    string output = "";


    cout<<-2%26<<endl;
    for(int x = 0; x < input.length(); x++)
        output += caesar(input[x], k);
    cout << output << endl;
}
