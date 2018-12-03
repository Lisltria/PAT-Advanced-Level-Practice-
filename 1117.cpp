#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int D[100000];
bool cmp(int &a,int &b)
{
    return a > b;
}
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        cin >> D[i];
    }
    sort(D, D + N,cmp);
    int i;
    for (i = 0; i < N;i++)
    {
        if(D[i]<=i+1)
        {
            break;
        }
    }
    cout << i << endl;
    return 0;
}