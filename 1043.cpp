#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int N;
typedef struct node
{
    int data;
    int rank;
}nodes;
nodes tree[1001];

int rank_count=1;
int flag=true;

void randTheTree(nodes *T,int s,int e)
{
    if(!flag)return ;
    if(s>e)return ;

    if(s==e)
    {
        T[s].rank=rank_count;
        rank_count++;
    }
    else
    {
        int i,j;
        for(i=s+1;i<=e;i++)
        {
            if(T[i].data>=T[s].data)
            {
                break;
            }
        }
        for(j=s+1;j<=i-1;j++)
        {
            if(T[j].data>=T[s].data)
            {
                flag=false;
                break;
            }
        }
        randTheTree(T,s+1,i-1);
        for(j=i;j<=e;j++)
        {
            if(T[j].data<T[s].data)
            {
                flag=false;
                break;
            }
        }
        randTheTree(T,i,e);
        T[s].rank=rank_count;
        rank_count++;
    }
}


int rank_count_2=1;
int flag_2=true;

void randTheTree_2(nodes *T,int s,int e)
{
    if(!flag_2)return ;
    if(s>e)return ;

    if(s==e)
    {
        T[s].rank=rank_count_2;
        rank_count_2++;
    }
    else
    {
        int i,j;
        for(i=s+1;i<=e;i++)
        {
            if(T[i].data<T[s].data)
            {
                break;
            }
        }
        for(j=s+1;j<=i-1;j++)
        {
            if(T[j].data<T[s].data)
            {
                flag_2=false;
                break;
            }
        }
        randTheTree_2(T,s+1,i-1);
        for(j=i;j<=e;j++)
        {
            if(T[j].data>=T[s].data)
            {
                flag_2=false;
                break;
            }
        }
        randTheTree_2(T,i,e);
        T[s].rank=rank_count_2;
        rank_count_2++;
    }
}

bool cmp(nodes a,nodes b)
{
    return a.rank<b.rank;
}
int main(int argc, char const *argv[])
{
    /* code */
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>tree[i].data;
    }
    randTheTree(tree,1,N);
    if(flag)
    {
        sort(tree+1,tree+N+1,cmp);
        cout<<"YES"<<endl;
        for(int i=1;i<N;i++)
        {
            cout<<tree[i].data<<" ";
        }
        cout<<tree[N].data<<endl;
    }
    else
    {
        randTheTree_2(tree,1,N);
        if(flag_2)
        {
            sort(tree+1,tree+N+1,cmp);
            cout<<"YES"<<endl;
            for(int i=1;i<N;i++)
            {
                cout<<tree[i].data<<" ";
            }
            cout<<tree[N].data<<endl;

        }
        else cout<<"NO"<<endl;
    }
    return 0;
}


