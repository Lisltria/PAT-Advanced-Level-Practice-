#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N;
double P,r;
vector<int> chain[100010];
double product[100010];
double power[100010];
bool enable[100010]={false};
typedef struct node{
    int ID;
    int level;
}sale;
queue<sale> q;

void fillpow(int time)
{
    double it=1.0+r/100;
    power[0]=P;
    for(int i=1;i<=time;i++)
    {
        power[i]=power[i-1]*it;
    }
}

double calc(int time)
{
    return power[time];
}
int main()
{
    cin>>N>>P>>r;
    double ans=0.0;
    fillpow(N);
    for(int i=0;i<N;i++)
    {
        int t;
        scanf("%d",&t);
        if(t!=0)
        {
            for(int j=0;j<t;j++)
            {
                int x;
                scanf("%d",&x);
                chain[i].push_back(x);
            }
        }
        else
        {
            scanf("%lf",product+i);
        }
    }
    //BFS
    
    sale first,x;
    first.ID=0;
    vector<int>::iterator iter;
    first.level=0;
    q.push(first);
    enable[first.ID]=true;
    while(!q.empty())
    {
        sale t;
        t=q.front();
        q.pop();
        if(chain[t.ID].empty())
        {
            ans+=product[t.ID]*calc(t.level);
        }
        else 
        {
            for(iter=chain[t.ID].begin();iter!=chain[t.ID].end();iter++)
            {
                x.level=t.level+1;
                x.ID=*iter;
                q.push(x);
            }
        }
    }
    
    printf("%.1lf\n",ans);

    return 0;
}