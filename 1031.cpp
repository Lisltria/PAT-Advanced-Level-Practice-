#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    char s[100];
    int l,n1,n2;
    scanf("%s",s);
    l=strlen(s);
    if(l%3==2)
    {
        n1=l/3;
        n2=l-n1*2;
    }
    if(l%3==1)
    {
        n1=l/3;
        n2=l-n1*2;
    }
    if(l%3==0)
    {
        n1=l/3-1;
        n2=l-n1*2;
    }

    for(int i=0;i<n1;i++)
    {
        cout<<s[i];
        for(int j=0;j<n2-2;j++)
            printf(" ");
        cout<<s[strlen(s)-i-1]<<endl;
    }
    for(int i=n1;i<n1+n2;i++)
        cout<<s[i];
    cout<<endl;
    return 0;
}
