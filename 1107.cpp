#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int hobby[1001];
set<int> ss[1001];
map<int, int> m2s;
int setCnt = 0;
int N;
bool cmp(int &a, int &b) { return a > b; }
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        int K;
        int temp[1000];
        int flag = -1;
        set<int> vvv;
        scanf("%d:", &K);
        for (int j = 0; j < K;j++)
        {
            cin >> temp[j];
            if(m2s.find(temp[j])!=m2s.end())
            {
                flag = m2s[temp[j]];
                vvv.insert(flag);
            }
        }
        if(flag==-1)
        {
            for (int j = 0; j < K;j++)
            {
                m2s[temp[j]] = setCnt;
                ss[setCnt].insert(temp[j]);
            }
            hobby[setCnt]++;
            setCnt++;
           
        }
        else
        {
            
            for (int j = 0; j < K;j++)
            {
                m2s[temp[j]] = flag;
                ss[flag].insert(temp[j]);
            }
            hobby[flag]++;
            for (auto iter = vvv.begin(); iter != vvv.end();iter++)
            {
                if(*iter==flag)
                {
                    continue;
                }
                else
                {
                    for (auto it = ss[*iter].begin(); it != ss[*iter].end();it++)
                    {
                        m2s[*it] = flag;
                        ss[flag].insert(*it);
                    }
                    hobby[flag] += hobby[*iter];
                    hobby[*iter] = 0;
                    ss[*iter].clear();
                }
            }
        }
    }
    
    sort(hobby, hobby + setCnt, cmp);
    bool pflag = false;
    int ansCnt = 0;
    for (int i = 0; i < setCnt;i++)
    {
        
        if(hobby[i]==0)
            break;
        ansCnt++;
    }
    cout << ansCnt << endl;
    for (int i = 0; i < ansCnt;i++)
    {
        if(hobby[i]==0)
            break;
        if(pflag)
            cout << " ";
        else
            pflag = true;
        cout << hobby[i];
    }
    cout << endl;
    return 0;
}