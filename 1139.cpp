#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, K, M;
vector<int> relation[10010];
bool gender[10010];
bool isHomo[10010];
bool mapRe[301][301];
map<int, int> id2num;
int countNum = 0;

typedef struct node
{
    int AA;
    int BB;
} sortN;
bool cmp(sortN a,sortN b)
{
    if(a.AA==b.AA)
    {
        return a.BB < b.BB;
    }
    else
        return a.AA < b.AA;
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < M;i++)
    {
        char sa[10], sb[10];
        int a, b;
        cin >> sa >> sb;
        if(sa[0]=='-')
        {
            a = (sa[1] - 48)*1000 + (sa[2] - 48)*100 + (sa[3] - 48)*10 + (sa[4] - 48);
            gender[abs(a)] = false;
        }
        else
        {
            a = (sa[0] - 48)*1000 + (sa[1] - 48)*100 + (sa[2] - 48)*10 + (sa[3] - 48);
            gender[abs(a)] = true;
        }
        if(sb[0]=='-')
        {
            b = (sb[1] - 48)*1000 + (sb[2] - 48)*100 + (sb[3] - 48)*10 + (sb[4] - 48);
            gender[abs(b)] = false;
        }
        else
        {
            b = (sb[0] - 48)*1000 + (sb[1] - 48)*100 + (sb[2] - 48)*10 + (sb[3] - 48);
            gender[abs(b)] = true;
        }
        
        if(id2num.find(abs(a))==id2num.end())
        {
            id2num[abs(a)] = countNum;
            countNum++;
        }
        if(id2num.find(abs(b))==id2num.end())
        {
            id2num[abs(b)] = countNum;
            countNum++;
        }
        isHomo[abs(a)] = true;
        isHomo[abs(b)] = true;
        if(gender[a]==gender[b])
        {
            relation[abs(a)].push_back(abs(b));
            relation[abs(b)].push_back(abs(a));
        }
        mapRe[id2num[abs(a)]][id2num[abs(b)]] = true;
        mapRe[id2num[abs(b)]][id2num[abs(a)]] = true;
    }
    cin >> K;
    for (int i = 0; i < K;i++)
    {
        int a,b;
        int oa, ob;
        cin >> a >> b;
        oa = abs(a);
        ob = abs(b);

        vector<int> ansA, ansB;
        vector<sortN> fans;
        for (auto it = relation[oa].begin(); it != relation[oa].end();it++)
        {
            if(*it!=ob)
            {
                ansA.push_back(*it);
            }
        }
        for (auto it = relation[ob].begin(); it != relation[ob].end();it++)
        {
            if(*it!=oa)
            {
                ansB.push_back(*it);
            }
        }
        sortN tS;
        if(ansB.empty()||ansA.empty())
        {
            cout << "0" << endl;
            continue;
        }
        for (auto it1 = ansA.begin(); it1 != ansA.end();it1++)
        {
            int tA = id2num[*it1];
            for (auto it2 = ansB.begin(); it2 != ansB.end();it2++)
            {
                int tB = id2num[*it2];
                if(mapRe[tA][tB])
                {
                    tS.AA = *it1;
                    tS.BB = *it2;
                    fans.push_back(tS);
                }
            }
        }
        sort(fans.begin(), fans.end(), cmp);
        cout << fans.size() << endl;
        for (auto it1 = fans.begin(); it1 != fans.end();it1++)
        {
            printf("%04d %04d\n", it1->AA, it1->BB);
        }
    }
    return 0;
}