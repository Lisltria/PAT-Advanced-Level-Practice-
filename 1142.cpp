#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <queue>
using namespace std;

int Nv, Ne, M;
bool vEn[201];
vector<int> edge[201];
int count=1;
int group[201];
int gCount[201];
int main()
{
    cin >> Nv >> Ne;
    for (int i = 0; i < Ne; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        edge[t1].push_back(t2);
        edge[t2].push_back(t1);
    }

    int K,M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> K;
        int tt[201]={0};
        int countA[201]={0};
        for (int j = 0; j <K;j++)
        {
            cin >> tt[j];
            for (auto it = edge[tt[j]].begin(); it != edge[tt[j]].end();it++)
            {
                countA[*it]++;
            }
        }
        int status=0;
        for (int j = 0; j <K;j++)
        {
            if(countA[tt[j]]<K-1)
            {
                status = -1;
            }
        }

        if(status==0)
        {
            for (int j = 1; j <= Nv;j++)
            {
                if(countA[j]==K)
                {
                    status = 1;
                   
                }
            }
            if(status==1)
            {
                cout << "Not Maximal" << endl;
            }
            else
            {
                cout << "Yes" << endl;
            }
        }
        else
        {
            cout << "Not a Clique" << endl;
        }
    }

    return 0;
}