#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
bool nodeB[10];
int node[10][2];

bool flag = false;
void inOrder(int root)
{
    if(root==-1)
    {
        return;
    }
    else
    {
        inOrder(node[root][0]);
        if(flag)
            cout << " ";
        else
            flag = true;
        cout << root;
        
        inOrder(node[root][1]);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int N;
    cin >> N;
    cin.get();
    for (int i = 0; i < N; i++)
    {
        char c;
        cin.get(c);
        if(c!='-')
        {
            node[i][1] = c - 48;
            nodeB[c - 48] = true;
        }
        else
        {
            node[i][1] = -1;
        }
        cin.get();
        cin.get(c);
        if(c!='-')
        {
            node[i][0] = c - 48;
            nodeB[c - 48] = true;
        }
        else
        {
            node[i][0] = -1;
        }
        cin.get();
    }
    int root;
    for (int i = 0; i < N;i++)
    {
        if(nodeB[i]==false)
        {
            root = i;
            break;
        }
    }
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        if(t!=root)
            cout << " ";
        cout << t;
        if(node[t][0]!=-1
            q.push(node[t][0]);
        if(node[t][1]!=-1)
            q.push(node[t][1]);
    }
    cout << endl;
    inOrder(root);
    cout << endl;
    return 0;
}
