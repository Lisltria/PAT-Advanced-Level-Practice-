#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map<int,int>favoriteColor;
int count=1;
int stripe[10001];
int ans[201];
int N,M,L;
int main()
{
    cin>>N;
    cin>>M;
    for(int i=1;i<=M;i++)
    {
        int t;
        cin>>t;
        favoriteColor[t]=i;
    }
    cin>>L;
    for(int i=1;i<=L;i++)
    {
        int t;
        cin>>t;
        if(favoriteColor.find(t)==favoriteColor.end())
        {

        }
        else
        {
            auto iter=favoriteColor.find(t);
            stripe[count]=iter->second;
            count++;
        }
    }

    int left,right;
    int max_lenght=0;
    for(int i=1;i<count;i++)
    {
        int t_max=0;
        for(int j=stripe[i];j>=1;j--)
        {
            if(ans[j]>t_max)t_max=ans[j];
        }
        ans[stripe[i]]=t_max+1;
    }
    for(int i=1;i<=N;i++)
    {
        if(ans[i]>max_lenght)
        {
            max_lenght=ans[i];
        }
    }
    cout<<max_lenght<<endl;

    return 0;
}