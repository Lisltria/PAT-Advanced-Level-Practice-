#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <climits>
using namespace std;

typedef struct node
{
    string from;
    string to;
    int D;
}road;

map<string,int> cities;
vector<road> roads[1011];
int N,M,K,Dt;
string finalpos;
int finalD=-1;;
double finalAvg=1.0*INT32_MAX;;
bool ansexist=false;
void DDD(string origin)
{
    int Dis[1011];
    bool C[1011];
    int count=0;
    string recity;
    double avg=0.0;
    int min=INT32_MAX,cout_avalible=0;
    for(int i=0;i<=N+M;i++)
    {
        Dis[i]=INT32_MAX;
        C[i]=false;
    }
    Dis[cities[origin]]=0;
    C[cities[origin]]=true;
    recity=origin;
    count++;
    while(count<N+M)
    {
        for(auto iter=roads[cities[recity]].begin();iter!=roads[cities[recity]].end();iter++)
        {
            //if(cities[iter->to]>N&&iter->to!=origin)continue;
            if(!C[cities[iter->to]] && Dis[cities[recity]]+iter->D < Dis[cities[iter->to]] )
            {
                Dis[cities[iter->to]]=Dis[cities[recity]]+iter->D;
            }
        }
        int min=INT32_MAX,pos=-1;
        for(int i=1;i<=M+N;i++)
        {
            //if(i!=cities[origin])continue;
            if(Dis[i]<min&&C[i]==false)
            {
                min=Dis[i];
                pos=i;
            }
        }
        if(pos==-1)break;
        C[pos]=true;
        count++;
        if(pos<=N)
        {
            recity=to_string(pos);
        }
        else
        {
            recity="G"+to_string(pos-N);
        }
    }
    avg=0.0;
    min=INT32_MAX;
    cout_avalible=0;
    for(int i=1;i<=N;i++)
    {
        if(Dis[i]<min)
        {
            min=Dis[i];
        }
        avg+=Dis[i];
        if(Dis[i]<=Dt)
        {
            cout_avalible++;
        }
        if(Dis[i]==INT32_MAX)
        {
            break;
        }
    }
    if(cout_avalible==N)
    {
        avg/=N;
        if(min>finalD)
        {
            finalAvg=avg;
            finalD=min;
            finalpos=origin;
            ansexist=true;
        }
        else if(min==finalD)
        {
            if(avg<finalAvg)
            {
                finalAvg=avg;
                finalD=min;
                finalpos=origin;
                ansexist=true;
            }
        }
        //cout<<origin<<endl;
        //printf("%.1lf %.1lf\n",1.0*min,1.0*avg);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int count=1;
    
    cin>>N>>M>>K>>Dt;
    for(int i=1;i<=N;i++)
    {
        string t=to_string(i);
        cities[t]=i;
    }
    for(int i=1;i<=M;i++)
    {
        string t="G"+to_string(i);
        cities[t]=i+N;
    }
    for(int i=0;i<K;i++)
    {
        string t1,t2;
        int t;
        road r;
        cin>>t1>>t2>>t;
        r.from=t1;r.to=t2;r.D=t;
        roads[cities[r.from]].push_back(r);
        r.from=t2;r.to=t1;r.D=t;
        roads[cities[r.from]].push_back(r);
    }
    
    for(int i=1;i<=M;i++)
    {
        string s="G"+to_string(i);
        DDD(s);
    } 
    if(ansexist)
    {
        cout<<finalpos<<endl;
        printf("%.1lf %.1lf\n",1.0*finalD,1.0*finalAvg);
    }
    else
    {
        cout<<"No Solution"<<endl;
    }
    return 0;
}
