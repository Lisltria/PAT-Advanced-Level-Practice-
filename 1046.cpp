#include <iostream>
#include <cstdio>
using namespace std;

int list[100001];
int sum[100001];
int SUM;

int main(int argc, char const *argv[])
{
    /* code */
    int N,M;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        scanf("%d",list+i);
        SUM+=list[i];
        sum[i]=SUM;
    }

    cin>>M;
    for(int i=1;i<=M;i++)
    {
        int t1,t2,t;
        cin>>t1>>t2;
        if(t1>t2){
            t1^=t2^=t1^=t2;
        }
        t=sum[t2-1]-sum[t1-1];
        if(t<SUM-t)cout<<t<<endl;
        else cout<<SUM-t<<endl;
    }
    return 0;
}
