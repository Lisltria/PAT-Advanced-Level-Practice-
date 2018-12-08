#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int N,m,n;
int ans[10001];
bool enable[10001];
vector<int> sortV;
bool cmp(int &a, int &b) { return a > b; }
void find()
{
    int x = N;
    int y = 1.0*sqrt(x)+0.5;
    while(x%(y++)!=0)
    {
        ;
    }
    y--;
    m = y;
    n = x / y;
    if(m<n)
    {
        swap(n, m);
    }
}

int main()
{
    cin >> N;
    find();
    for (int i = 0;i<N;i++)
    {
        int t;
        cin >> t;
        sortV.push_back(t);
    }
    sort(sortV.begin(), sortV.end(), cmp);
    int x=0, y=0;
    int xD = 0, yD = 1;
    int count = 0;
    while(count<N)
    {
        ans[x * n + y] = sortV[count];
        enable[x * n + y] = true;
        count++;
        y += yD;
        x += xD;
        if(x>=m||y>=n||x<0||y<0||enable[x * n + y]==true)
        {
            y -= yD;
            x -= xD;
            if(xD==0&&yD==1)
            {
                xD = 1;
                yD = 0;
            }
            else if(xD==1&&yD==0)
            {
                xD = 0;
                yD = -1;
            }
            else if(xD==0&&yD==-1)
            {
                xD = -1;
                yD = 0;
            }
            else if(xD==-1&&yD==0)
            {
                xD=0;
                yD = 1;
            }
            y += yD;
            x += xD;
        }
    }
    for (int i = 0; i < m;i++)
    {
        cout << ans[i * n];
        for (int j = 1; j < n;j++)
        {
            cout << " " <<ans[i * n+j];
        }
        cout << endl;
    }
    return 0;
}