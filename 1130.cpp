#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

typedef struct node
{
    int m;
    string data;
    int lc;
    int rc;
} treeNode;
treeNode tree[30];

int N;
bool whereIsRoot[21];

int ROOT;
void inOrder(int root)
{
    if(root<0||root>N)
    {
        return;
    }
    treeNode t=tree[root];
    if(t.lc!=-1||t.rc!=-1)
    {
        if(root!=ROOT)cout << "(";
    }
    if(t.lc!=-1)
    {
        inOrder(t.lc);
    }
    cout << t.data;
    if(t.rc!=-1)
    {
        inOrder(t.rc);
    }
    if(t.lc!=-1||t.rc!=-1)
    {
        if(root!=ROOT)cout << ")";
    }
}

int main(int argc, char const *argv[])
{
    /* code */

   
    cin >> N;

    for (int i = 1; i <= N; i++)
    { 
        treeNode t;
        t.m = i;
        cin >> t.data >> t.lc >> t.rc;

        tree[i]=t;
        if(t.lc>0)
            whereIsRoot[t.lc] = true;
        if(t.rc>0)
            whereIsRoot[t.rc] = true;
    }
    
    for (int i = 1; i < N;i++)
    {
        if(whereIsRoot[i]==false)
        {
            ROOT = i;
            break;
        }
    }
    inOrder(ROOT);
    cout << endl;
    return 0;
}
