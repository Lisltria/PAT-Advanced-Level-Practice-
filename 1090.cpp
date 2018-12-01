#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

vector<int> list[100001];
double price[100001];
void calc(int n,double r)
{
    price[0] = 1.0;
    price[0] = 1.0;
    for (int i = 1; i <= n; i++)
    {
        price[i] = price[i - 1] * (1.0 + r / 100);
    }
}
double getPrice(int time)
{
    return price[time];
}
double highest = 0.0;
int count = 0;
void find(int root,int level,double p)
{
    if(list[root].empty())
    {
        double tempPrice = getPrice(level) * p;
        if( tempPrice > highest)
        {
            highest = tempPrice;
            count = 1;
        }
        else if( abs(highest-tempPrice)<0.000000001)
        {
            count++;
        }
    }
    else
    {
        for (auto iter = list[root].begin(); iter != list[root].end(); iter++)
        {
            //cout << root << "->" << *iter << endl;
            find(*iter, level + 1, p);
        }
    }
}
int main()
{
    int N, root;
    double P, r;
    cin >> N >> P >> r;
    calc(N, r);
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        if(t==-1)
        {
            root = i;
        }
        else
        {
            list[t].push_back(i);
        }
    }
    int iter = root;
    find(root, 0, P);
    printf("%.2lf %d\n", highest, count);
    return 0;
}