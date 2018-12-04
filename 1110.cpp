#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

struct node{
    int d;
    int lc, rc;
} tree[30];
int N;
bool nodeF[30];
int main()
{
    int root;
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        char s1[20], s2[20];
        cin >> s1 >> s2;
        tree[i].d = i;
        if(s1[0]=='-')
        {
            tree[i].lc = -1;
        }
        else
        {
            int t;
            
            sscanf(s1, "%d", &t);nodeF[t] = true;
            tree[i].lc = t;
        }
        if(s2[0]=='-')
        {
            tree[i].rc = -1;
        }
        else
        {
            int t;
            
            sscanf(s2, "%d", &t);nodeF[t] = true;
            tree[i].rc = t;
        }
    }
    for (int i = 0; i < N;i++)
    {
        if(nodeF[i]==false)
            root = i;
    }

    bool isComplete = true;
    bool ready = false;
    int last;

    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int t = q.front();
        last = t;
        q.pop();
        if(ready&&(tree[t].rc!=-1||tree[t].lc!=-1))
        {
            isComplete = false;
        }

        if(tree[t].lc==-1&&tree[t].rc!=-1)
        {
            isComplete = false;
        }
        else if(tree[t].lc==-1&&tree[t].rc==-1)
        {
            ready = true;
        }
        else if(tree[t].lc!=-1&&tree[t].rc==-1)
        {
            ready = true;
        }
        if(tree[t].lc!=-1)
        {
            q.push(tree[t].lc);
        }
        if(tree[t].rc!=-1)
        {
            q.push(tree[t].rc);
        }
    }
    if(isComplete)
    {
        cout << "YES " << last << endl;
    }
    else
    {
        cout << "NO " << root << endl;
    }

    return 0;
}