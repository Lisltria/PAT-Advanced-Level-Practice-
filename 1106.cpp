#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<int> vvv[100000];
double price[100001];
void fillPrice(int n,double p,double r)
{
    price[0] = p;
    for (int i = 1; i <= n;i++)
    {
        price[i] = (100 + r) / 100 * price[i - 1];
    }
}
typedef struct node
{
    int pp;
    int level;
} query;
int main()
{
    int N;
    double P, r;
    cin >> N >> P >> r;
    fillPrice(N, P, r);
    for (int i = 0; i < N;i++)
    {
        int K;
        cin >> K;
        for (int j = 0; j < K;j++)
        {
            int t;
            cin >> t;
            vvv[i].push_back(t);
        }
    }
    double minp = price[N]+1;
    int count = 0;
    query t;
    t.level = 0;
    t.pp = 0;
    queue<query> q;
    q.push(t);
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        if(vvv[t.pp].empty())
        {
            if(price[t.level]<minp)
            {
                minp = price[t.level];
                count = 1;
            }
            else if(abs(price[t.level]-minp)<0.0001)
            {
                count++;
            }
        }
        else
        {
            for (auto iter = vvv[t.pp].begin(); iter != vvv[t.pp].end();iter++)
            {
                query x;
                x.pp = *iter;
                x.level = t.level + 1;
                q.push(x);
            }
        }
    }
    printf("%.4lf %d\n", minp, count);
    return 0;
}