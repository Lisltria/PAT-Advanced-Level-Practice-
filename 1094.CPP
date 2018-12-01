#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int N, M;
vector<int> tree[101];
int level[101];
int ans[100];
void DFS(int root,int l)
{
    level[root] = l;
    if(tree[root].empty())
    {
        return;
    }
    else
    {
        for (auto iter = tree[root].begin(); iter != tree[root].end(); iter++)
        {
            DFS(*iter, l + 1);
        }
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    cin >> N >> M;
    for (int i = 1; i <= M;i++)
    {
        int t, tN;
        cin >> t >> tN;
        for (int j = 0; j < tN; j++)
        {
            int x;
            cin >> x;
            tree[t].push_back(x);
        }
    }
    DFS(1, 1);
    for (int i = 1; i <= N;i++)
    {
        ans[level[i]]++;
    }
    int max=0, maxi;
    for (int i = 1; i <= N;i++)
    {
        if(ans[i]>max)
        {
            max = ans[i];
            maxi = i;
        }
    }
    cout << max << " " << maxi << endl;
    return 0;
}
