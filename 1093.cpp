#include <iostream>
#include <cstdio>
using namespace std;

int P,A,T;
int main()
{
    char c;
    while((cin.get(c),c)!='\n'&&c!=EOF)
    {
        if(c=='P')
        {
            P++;
        }
        else if(c=='A')
        {
            A += P;
        }
        else if(c=='T')
        {
            T += A;
        }
        if(T>=1000000007)
        {
            T %= 1000000007;
        }
    }
    cout << T << endl;
    return 0;
}