#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node 
{
    int ft;
    int data;
    int mem;
} treeNode;
vector<treeNode> theTree;
map<int, int> num2mem;
int memory = 0;
int pre[10000];
int M, N;

void buildTree(int s,int e,int father)
{
    treeNode tt;
    tt.ft = father;
    tt.data = pre[s];
    tt.mem = memory;
    theTree.push_back(tt);
    num2mem[tt.data] = memory;
    memory++;
   

    if(s==e)
    {
        return ;
    }
    int i;
    for (i = s+1; i <= e;i++)
    {
        if(pre[i]>pre[s])
        {
            break;
        }
    }
    if(s+1<=i-1)
        buildTree(s + 1, i - 1, tt.mem);
    if(i<=e)
        buildTree(i, e, tt.mem);
}
int find(int m1,int m2)
{
    int it1 = m1, it2 = m2;
    vector<int> p1;
    vector<int> p2;
    while(it1!=-1)
    {
        p1.push_back(theTree[it1].data);
        it1 = theTree[it1].ft;
    }
    while(it2!=-1)
    {
        p2.push_back(theTree[it2].data);
        it2 = theTree[it2].ft;
    }
    reverse(p1.begin(),p1.end());
    reverse(p2.begin(),p2.end());
    int i = 0;
    while(i<p1.size()&&i<p2.size())
    {
        if(p1[i]!=p2[i])
        {
            break;
        }
        else
        {
            i++;
        }
    }
    if(i<p1.size()&&i<p2.size())
    {
        return p1[i-1];
    }
    else if(i<p1.size()&&i>=p2.size())
    {
        return -1;
    }
    else if(i>=p1.size()&&i<p2.size())
    {
        return -2;
    }
    else
        return -3;
}
int main()
{
    cin >> M >> N;
    for (int i = 0; i < N;i++)
    {
        cin >> pre[i];
    }
    buildTree(0, N - 1, -1);
    for (int i = 0; i < M;i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        if(num2mem.find(t1)!=num2mem.end()&&num2mem.find(t2)!=num2mem.end())
        {
            int mem1 = num2mem[t1], mem2 = num2mem[t2];
            int st=find(mem1,mem2);
            if(st>0)
            {
                printf("LCA of %d and %d is %d.\n", t1, t2, st);
            }
            else
            {
                if(st==-2)
                {
                    printf("%d is an ancestor of %d.\n", t1, t2);
                }
                else if(st==-1)
                {
                    printf("%d is an ancestor of %d.\n", t2, t1);
                }
                else
                {
                    printf("%d is an ancestor of %d.\n", t2, t1);
                }
            }
        }
        else if(num2mem.find(t1)==num2mem.end()&&num2mem.find(t2)==num2mem.end())
        {
            printf("ERROR: %d and %d are not found.\n", t1, t2);
        }
        else if(num2mem.find(t1)==num2mem.end() )
        {
            printf("ERROR: %d is not found.\n", t1);
        }
        else 
        {
            printf("ERROR: %d is not found.\n", t2);
        }
    }
    return 0;
}