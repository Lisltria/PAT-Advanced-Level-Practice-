#include <iostream>
#include <cstdio>
#include <unordered_set>
#include <set>
#include <unordered_map>
using namespace std;

unordered_map<int, int> birds;
unordered_set<int> groupCnt[10000];

int setCnt = 0;
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        int K, setNum=i;
        int picture[10000];
        cin >> K;
        for (int j = 0; j < K;j++)
        {
            scanf("%d", picture + j);
        }
        int group = setCnt;
        int maxGroup = group, maxBird = 0;
        
        set<int> xx;
        setCnt++;
        xx.insert(group);
        for (int j = 0; j < K;j++)
        {
            if(birds.find(picture[j])!=birds.end())
            {
                xx.insert(birds[picture[j]]);
                if(groupCnt[birds[picture[j]]].size()>maxBird)
                {
                    maxBird = groupCnt[birds[picture[j]]].size();
                    maxGroup = birds[picture[j]];
                }
            }
            birds[picture[j]] = group;
            groupCnt[group].insert(picture[j]);
        }
        for (auto iter = xx.begin(); iter != xx.end();iter++)
        {
            if(*iter==maxGroup)
                continue;
            for (auto it = groupCnt[*iter].begin(); it != groupCnt[*iter].end();it++)
            {
                groupCnt[maxGroup].insert(*it);
                birds[*it] = maxGroup;
            }
            groupCnt[*iter].clear();
        }
    }
    int treeCnt = 0;
    for (int i = 0; i < N;i++)
    {
        if(!groupCnt[i].empty())
        {
            treeCnt++;
        }
    }
    cout << treeCnt << " " << birds.size() << endl;
    int M;
    cin >> M;
    for (int i = 0; i < M;i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        if(birds[t1]==birds[t2])
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