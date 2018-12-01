#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

int N, M;
vector<int> hhash[100001];
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        hhash[t1].push_back(t2);
        hhash[t2].push_back(t1);
    }
    for (int i = 1; i <= M; i++)
    {
        set<int> temp;
        int tempArr[1001];
        int K;
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            cin >> tempArr[j];
            temp.insert(tempArr[j]);
        }
        bool flag = true;
        for (int j = 0; j < K; j++)
        {
            for (auto iter = hhash[tempArr[j]].begin(); iter != hhash[tempArr[j]].end();iter++)
            {
                if(temp.find(*iter)!=temp.end())
                {
                    flag = false;
                    break;
                }
                if(!flag)
                    break;
            }
        }
        if(flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}