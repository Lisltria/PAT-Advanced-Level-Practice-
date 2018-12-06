#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;
int N[101][5];
int arry[101];
int countNode(int root)
{
    if(root==-1)
    {
        return 0;
    }
    else
    {
        N[root][3] = countNode(N[root][0]);
        N[root][4] = countNode(N[root][1]);
        return N[root][3] + N[root][4] + 1;
    }
}

void fillTree(int root,int s,int e)
{
    if(s==e)
    {
        N[root][2] = arry[s];
    }
    else
    {
        N[root][2] = arry[s + N[root][3]];
        if(s<= s + N[root][3] - 1)
            fillTree(N[root][0], s, s + N[root][3] - 1);
        if(s + N[root][3] + 1<= e)
            fillTree(N[root][1], s + N[root][3] + 1, e);
    }
}

int main()
{
    int NN;
    cin >> NN;
    for (int i = 0; i < NN;i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        N[i][0] = t1;
        N[i][1] = t2;
        N[i][2] = INT32_MIN;
    }
    for (int i = 0; i < NN;i++)
    {
        cin >> arry[i];
    }
    countNode(0);
    sort(arry, arry + NN);
    fillTree(0,0,NN-1);

    bool flag = false;
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        if(flag)
            cout << " ";
        else
            flag = true;
        //cout << N[t][3]<<" "<<N[t][4]<<endl;
        cout << N[t][2];
        if(N[t][0]!=-1)q.push(N[t][0]);
        if(N[t][1]!=-1)q.push(N[t][1]);
    }
    cout << endl;
    return 0;
}