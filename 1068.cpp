#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;
int coins[10001];
int dp[101];
bool ssss[10001][101];
vector<int> ans;
bool cmp(int a,int b){return a>b;}
int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        scanf("%d",coins+i);
    }
    sort(coins,coins+N,cmp);
    for(int i=0;i<N;i++)
    {
        for(int j=M;j>=coins[i];j--)
        {
            if(dp[j]<=dp[j-coins[i]]+coins[i])
            {
                dp[j]=dp[j-coins[i]]+coins[i];
                ssss[i][j]=true;
            }
        }
    }
    if(dp[M]==M)
    {
        int i=N,j=M;
        while(i>=0)
        {
            if(ssss[i][j])
            {
                ans.push_back(coins[i]);
                j-=coins[i];
            }
            i--;
        }
        cout<<*(ans.begin());
        for(auto riter=ans.begin()+1;riter!=ans.end();riter++)
        {
            cout<<" "<<*riter;
        }
        cout<<endl;
    }
    else cout<<"No Solution"<<endl;
    
    return 0;
}