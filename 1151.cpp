#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int M, N;
int inorder[10000];
int preorder[10000];
typedef struct node
{
    int mem;
    int ft;
    int lc;
    int rc;
    int data;
} treeNode;
treeNode theTree[10000];
int memoryCount = 0;
map<int, int> num2mem;
int buidTree(int *in,int s1,int e1,int *pre,int s,int e,int father)
{
    treeNode t;
    t.ft = father;
    t.lc = -1;
    t.rc = -1;
    t.data = pre[s];
    
    t.mem = memoryCount;
    theTree[memoryCount] = t;
    num2mem[pre[s]] = t.mem;
    memoryCount++;
    if(s==e)
    {
        return t.mem;
    }
    else
    {
        int i;
        for (i = s1; i <= e1; i++)
        {
            if(in[i]==pre[s])
            {
                break;
            }
        }
        if(s1<=i-1)
            theTree[t.mem].lc=buidTree(in, s1, i - 1, pre, s + 1, s + i - s1, t.mem);
        if(i+1<=e1)
            theTree[t.mem].rc=buidTree(in, i + 1, e1, pre, s + i - s1 + 1, e, t.mem);
        return t.mem;
    }
}
void findRoot(int memory,vector<int>&v)
{
    v.push_back(theTree[memory].mem);
    if(theTree[memory].ft!=-1)
    {
        findRoot(theTree[memory].ft, v);
    }
}


int findDaddy(int m1,int m2)
{
    vector<int> p1, p2;
    findRoot(m1, p1);
    findRoot(m2, p2);
    reverse(p1.begin(),p1.end());
    reverse(p2.begin(),p2.end());
    int i = 0;
    while(i<p1.size()&&i<p2.size())
    {
        if(p1[i]==p2[i])
        {
            i++;
        }
        else
            break;
    }
    if(i<p1.size()&&i<p2.size())
    {
        return p1[i-1];
    }
    else if(i>=p1.size()&&i<p2.size())
    {
        return -1;
    }
    else if(i<p1.size()&&i>=p2.size())
    {
        return -2;
    }
    else if(i>=p1.size()&&i>=p2.size())
    {
        return -3;
    }
}

int main()
{
    cin >> M >> N;
    int head;
    for (int i = 0; i < N; i++)
    {
        cin >> inorder[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> preorder[i];
    }
    head = buidTree(inorder, 0, N - 1, preorder, 0, N - 1, -1);
    for (int i = 0; i < M;i++)
    {
        int find1,find2;
        int mem1, mem2;
        cin >> find1 >> find2;
        if(num2mem.find(find1)==num2mem.end())
        {
            mem1 = -1;
        }
        else
        {
            mem1 = num2mem[find1];
        }
        if(num2mem.find(find2)==num2mem.end())
        {
            mem2 = -1;
        }
        else
        {
            mem2 = num2mem[find2];
        }
        if(mem1!=-1&&mem2!=-1)
        {
            int status = findDaddy(mem1, mem2);
            if(status>=0)
            {
                printf("LCA of %d and %d is %d.\n", find1, find2, theTree[status].data);
            }
            else if(status==-1)
            {
                printf("%d is an ancestor of %d.\n", find1, find2);
            }
            else if(status==-2)
            {
                printf("%d is an ancestor of %d.\n", find2, find1);
            }
            else if(status==-3)
            {
                printf("%d is an ancestor of %d.\n", find2, find1);
            }
        }
        else if(mem1==-1&&mem2!=-1)
        {
             printf("ERROR: %d is not found.\n", find1);
        }
        else if(mem1!=-1&&mem2==-1)
        {
             printf("ERROR: %d is not found.\n", find2);
        }
        else if(mem1==-1&&mem2==-1)
        {
            printf("ERROR: %d and %d are not found.\n", find1, find2);
        }
    }
 
    return 0;
}
