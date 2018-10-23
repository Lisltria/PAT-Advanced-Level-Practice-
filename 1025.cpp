#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int N,nTotal;

typedef struct node{
    string ID;
    int rankFinal;
    int localNum;
    int localRank;
    int grade;
}nodes;

bool cmp(nodes a,nodes b)
{
    if(a.grade==b.grade)
    {
        return a.ID < b.ID;
    }
    return a.grade>b.grade;
}


nodes tester[30001];
nodes *subLocal[301];
int subCount[301];
int main(int argc, char const *argv[])
{
    /* code */
    cin>>N;
    nTotal=1;
    for(int i=1;i<=N;i++)
    {
        int n;
        cin>>n;
        subLocal[i]=&tester[nTotal];
        subCount[i]=n;
        for(int j=1;j<=n;j++)
        {
            cin>>tester[nTotal].ID;
            cin>>tester[nTotal].grade;
            tester[nTotal].localNum=i;
            
            nTotal++;
        }
    }
    for(int i=1;i<=N;i++)
    {
        sort(subLocal[i],subLocal[i]+subCount[i],cmp);
    }
    int rank;
    
    for(int i=1;i<=N;i++)
    {
        rank=1;
        for(int j=1;j<=subCount[i];j++)
        {
            if(j>1)
            {
                if((subLocal[i]+j-1)->grade < (subLocal[i]+j-2)->grade)
                    rank=j;
            }
            (subLocal[i]+j-1)->localRank=rank;
        }
    }
    sort(tester+1,tester+nTotal,cmp);
    rank=1;
    cout<<nTotal-1<<endl;
    for(int i=1;i<nTotal;i++)
    {
        if(i>1)
        {
            if(tester[i].grade<tester[i-1].grade)
                rank=i;
        }
        cout<<tester[i].ID<<" "<<rank<<" "<<tester[i].localNum<<" "<<tester[i].localRank<<endl;
    }

    return 0;
}
