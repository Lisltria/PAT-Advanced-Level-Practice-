#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int post[31];
int in[31];
int N;
int node[31][3];
int count = 1;

int build(int s1,int e1,int s2,int e2)
{
    if(s1==e1)
    {
        int now=count;
        count++;
        node[now][0] = -1;
        node[now][1] = -1;
        node[now][2] = in[s1];
        return now;
    }
    else
    {
        int i,now=count;
        count++;
        node[now][0] = -1;
        node[now][1] = -1;
        node[now][2] = post[e2];
        for (i = s1; i <= e1;i++)
        {
            if(in[i]==post[e2])
                break;
        }
        if(s1<=i-1)
            node[now][0]=build(s1, i - 1, s2, s2 + (i - 1 - s1 + 1) - 1);
        if(i+1<=e1)
            node[now][1]=build(i + 1, e1, s2 + (i - 1 - s1 + 1), e2-1);
        return now;
    }
}
int root;
stack<int> r, l;
void makeAnsLeft()
{
    while(!l.empty())
    {
        int t = l.top();
         if(t!=root)
            cout << " ";
        cout << node[t][2];
        l.pop();
        if(node[t][0]>0) r.push(node[t][0]);
        if(node[t][1]>0) r.push(node[t][1]);
    }
}
void makeAnsRight()
{
    while(!r.empty())
    {
        int t = r.top();
        if(t!=root)
            cout << " ";
        cout << node[t][2];
        r.pop();
        if(node[t][1]>0)l.push(node[t][1]);
        if(node[t][0]>0)l.push(node[t][0]);
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    
    cin >> N;
    for (int i = 0;i<N;i++)
        cin >> in[i];
    for (int i = 0;i<N;i++)
        cin >> post[i];
    root=build(0, N - 1, 0, N - 1);
    
    r.push(root);
    while(!l.empty()||!r.empty())
    {
        makeAnsRight();
        makeAnsLeft();
    }
    cout << endl;
    return 0;
}
