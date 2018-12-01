#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

queue<int> ans;
int main()
{
    long N;
    long chushu = 1;
    cin >> N;
    for (int i = 2; i < N;i++)
    {
        if(N%(chushu*i)==0)
        {
            ans.push(i);
        }
        else
        {
            
        }
    }
    return 0;
} 