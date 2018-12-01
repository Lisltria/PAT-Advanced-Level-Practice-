#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <climits>
using namespace std;
 
typedef struct node
{
    int from;
    int to;
    int c;
} road;

int N,K;
string origin;
map<string, int> Happiness;
map<string, int> citycode;
map<int, string> checkcity;
vector<road> roads[201];

int rDis[201];
int dij(int start,int end,int *D)
{
    bool enable[201]={false};
    int count = 1;
    int refreshCity=start;
    
    for (int i = 0; i <= N;i++)
    {
        D[i] = INT32_MAX;
        enable[i] = false;
    }
    enable[start] = true;
    D[refreshCity] = 0;

    while (count < N)
    {
        for (auto iter = roads[refreshCity].begin(); iter != roads[refreshCity].end(); iter++)
        {
            if (!enable[iter->to] && D[refreshCity] + iter->c < D[iter->to])
            {
                D[iter->to] = D[refreshCity] + iter->c;
            }
        }
        int minD=INT32_MAX, minI=-1;
        for (int i = 1; i <= N;i++)
        {
            if(D[i]<minD&&!enable[i])
            {
                minD = D[i];
                minI = i;
            }
        }
        if(minI==-1)
            break;
        else{
            enable[minI] = true;
            refreshCity = minI;
            count++;
           
        }
    }
    return D[end];
}

int ansPathCount = 0, ansMinDis = INT32_MAX, ansMaxHapns = 0, ansAvgHapns = 0;
string ansPath[401];
string finalPath[401];
int finalPathCount = 0;

void fffind(int city,int cost,int happy,int rom,int level)
{
    if(rDis[city]+cost!=ansMinDis)
       return;
    if(city==rom)
    {
        ansPath[level] = checkcity[city];
        ansPathCount++;

        if(happy+Happiness["ROM"]>ansMaxHapns)
        {
            ansMaxHapns = happy+Happiness["ROM"];
            ansAvgHapns = (happy+Happiness["ROM"]) / level;
            for (int i = 0; i <= level;i++)
            {
                finalPath[i] = ansPath[i];
            }
            finalPathCount = level;
            
        }
        else if(happy+Happiness["ROM"]==ansMaxHapns)
        {
            if((happy+Happiness["ROM"])/level>ansAvgHapns)
            {
                ansAvgHapns = (happy+Happiness["ROM"]) / level;
                for (int i = 0; i <= level;i++)
                {
                    finalPath[i] = ansPath[i];
                }
                finalPathCount = level;
            }
        }
        return;
    }
    ansPath[level] = checkcity[city];

    for (auto iter = roads[city].begin(); iter != roads[city].end();iter++)
    {
        if(rDis[iter->to]+cost+iter->c==ansMinDis)
       
        {
            
            fffind(iter->to,
                cost + iter->c,
                happy + Happiness[checkcity[iter->from]],
                rom,level+1);
        }
    }
} 
int main(int argc, char const *argv[])
{
    /* code */
    cin >> N >> K >> origin;
     Happiness[origin] = 0;
    citycode[origin] = N;
    checkcity[N] = origin;
    for (int i = 0; i < N - 1;i++)
    {
        string s;
        int t;
        cin >> s >> t;
        Happiness[s] = t;
        citycode[s] = i + 1;
        checkcity[i + 1] = s;
    }
    for (int i = 0; i < K;i++)
    {
        string s1, s2;
        road rt;
        int t;
        cin >> s1 >> s2 >> t;
        rt.from = citycode[s1];
        rt.to = citycode[s2];
        rt.c = t;
        roads[rt.from].push_back(rt);
        rt.to = citycode[s1];
        rt.from = citycode[s2];
        rt.c = t;
        roads[rt.from].push_back(rt);
    }
    ansMinDis = dij(citycode["ROM"], citycode[origin], rDis);
    fffind(citycode[origin], 0, 0, citycode["ROM"], 0);
    cout << ansPathCount << " " << ansMinDis << " " << ansMaxHapns << " " << ansAvgHapns << endl;
    for (int i = 0; i <= finalPathCount;i++)
    {
        if(i!=0)
            cout << "->";
        cout << finalPath[i];
    }
    cout << endl;
    return 0;
}
