#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int list[1001];
int ans[1001];
int countN = 0;
bool flag = false;

void fill(int root)
{
    if(root*2<=N)
    {
        fill(root * 2);
    }
    ans[root] = list[countN];
    countN++;
    if(root*2+1<=N)
    {
        fill(root * 2+1);
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        cin >> list[i];
    }
    sort(list, list + N);
    fill(1);
    for (int i = 1; i <= N;i++)
    {
        if(flag)
            cout << " ";
        else
            flag = true;
        cout << ans[i];
    }
    return 0;
}