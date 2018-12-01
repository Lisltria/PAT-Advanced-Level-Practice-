#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

vector<int> edge[10001];

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= M;i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        edge[t1].push_back(i);
        edge[t2].push_back(i);
    }
    int K;
    cin >> K;
    for (int i = 0; i < K;i++)
    {
        int Nt;
        cin >> Nt;
        set<int> s;
        for (int j = 0; j < Nt;j++)
        {
            int t;
            cin >> t;
            for (auto it = edge[t].begin(); it != edge[t].end();it++)
            {
                s.insert(*it);
            }
        }
        if(s.size()==M)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
        return 0;
}