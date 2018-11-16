#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int color[480001];
int main(int argc, char const *argv[])
{
    /* code */
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",color+(i*N+j));
        }
    }
    sort(color,color+N*M);

    int tag=-1;
    int count=-2;
    int max_pixel,max_count=-1;
    for(int i=0;i<N*M;i++)
    {
        if(color[i]!=tag)
        {
            if(count>max_count)
            {
                max_count=count;
                max_pixel=tag;
            }
            count=1;
            tag=color[i];
        }
        else
        {
            count++;
        }
    }

    if(count>max_count)
    {
        max_count=count;
        max_pixel=tag;
    }
    cout<<max_pixel<<endl;
    return 0;
}
