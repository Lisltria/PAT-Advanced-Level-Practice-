#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int N,M,SUM=0;
int highWay[100001];

int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        scanf("%d",highWay+i);
        SUM+=highWay[i];
    }
    cin>>M;

   
    return 0;
}