#include <iostream>
using namespace std;
//
bool city_enable[1001];
bool map[1001][1001],row[1001],col[1001];
int N,M,K;
void search(int i)
{
    if(!city_enable[i])
    {
        city_enable[i]=true;
        for(int j=1;j<=N;j++)
        {
            if(map[i][j])
            {
                search(j);
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    cin>>N>>M>>K;
    for(int i=1;i<=M;i++)
    {
        int a,b;
        cin>>a>>b;
        map[a][b]=map[b][a]=true;
    }
    for(int i=1;i<=K;i++)
    {
        int t;
        cin>>t;
        for(int j=1;j<=N;j++)city_enable[j]=false;
        for(int j=1;j<=N;j++)
        {
            row[j]=map[t][j];
            map[t][j]=false;
            col[j]=map[j][t];
            map[j][t]=false;
        }
        int count=0;
        for(int j=1;j<=N;j++)
        {
            if(j==t)continue;
            if(!city_enable[j])
            {
                search(j);
                count++;
            }
        }
        cout<<count-1<<endl;
        for(int j=1;j<=N;j++)
        {
            
            map[t][j]=row[j];
            
            map[j][t]=col[j];
            
        }
    }

    return 0;
}
