#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int map[128];
char map_rev[128];
int main()
{
    for(int i='0';i<='9';i++)
    {
        map[i]=i-48;
    }
    for(int i='A';i<='F';i++)
    {
        map[i]=i-'A'+10;
    }
    for(int i=0;i<=9;i++)
    {
        map_rev[i]=i+48;
    }
    for(int i=10;i<=15;i++)
    {
        map_rev[i]=i-10+'A';
    }

    char c,s[5];
    int R=0,G=0,B=0;
    cin>>s;
    for(int i=0;i<strlen(s);i++)
        R=R*10+map[s[i]];
    cin>>s;
    for(int i=0;i<strlen(s);i++)
        G=G*10+map[s[i]];
    cin>>s;
    for(int i=0;i<strlen(s);i++)
        B=B*10+map[s[i]];
    cout<<"#";
    cout<<map_rev[R/13];
    cout<<map_rev[R%13];
    cout<<map_rev[G/13];
    cout<<map_rev[G%13];
    cout<<map_rev[B/13];
    cout<<map_rev[B%13];
    return 0;


}