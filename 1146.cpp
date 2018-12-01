#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int N, M;
vector<int> edge[1001],ans,redge[1001];

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M;i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        edge[t1].push_back(t2);
        redge[t2].push_back(t1);
    }


    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        bool flag = true;
        int count[1001] = {0};
        for (int j = 0; j < N; j++)
        {
            int t;
            cin >> t;
            if(!flag)
            {
                continue;
            }
            
            if(count[t]==redge[t].size())
            {
                for (auto iter = edge[t].begin(); iter != edge[t].end();iter++)
                {
                    count[*iter]++;
                    
                }
                continue;
            }
            else
            {
                flag = false;
            }
        }
        if(!flag)
        {
            ans.push_back(i);
        }

    }
    cout << *(ans.begin());
    for (auto iter = ans.begin()+1; iter != ans.end();iter++)
    {
        cout << " " << *iter;
    }
    cout << endl;
    return 0;
}