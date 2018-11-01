#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;
int  N,K;
int people_count=0;
map<string,int> gang;
map<int,string> gang_rev;
bool relation[2001][2001];
int weight[2001];

int weightcount=0;
int maxweight=-1;
string max_head;
int gangcount=0;
int headcount=0;
bool search_enable[2001];
void search(int a)
{
    map<int,string>::iterator t;
    search_enable[a]=true;
    gangcount++;
    weightcount+=weight[a];
    if(weight[a]>maxweight)
    {
        maxweight=weight[a];
        t=gang_rev.find(a);
        max_head=(*t).second;
    }
    for(int i=1;i<=people_count;i++)
    {
        if(a==i)continue;
        if(relation[a][i]==true&&search_enable[i]==false)
        {
            search(i);
        }
    }
}

int main()
{
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        string t1,t2;
        int minutes;
        cin>>t1>>t2>>minutes;
        map<string,int>::iterator it1,it2;
        it1=gang.find(t1);
        if(it1==gang.end())
        {
            people_count++;
            gang[t1]=people_count;
            //it1=gang[t1];
            it1=gang.find(t1);
        }

        it2=gang.find(t2);
        if(it2==gang.end())
        {
            people_count++;
            gang[t2]=people_count;
            //it2=gang[t2];
            it2=gang.find(t2);
        }
        relation[(*it1).second][(*it2).second]=true;
        relation[(*it2).second][(*it1).second]=true;
        weight[(*it1).second]+=minutes;
        weight[(*it2).second]+=minutes;
    }
    map<string, int>::iterator iter;  
  
    for(iter = gang.begin(); iter != gang.end(); iter++)  
    {
        gang_rev[iter->second]=iter->first;
    }
    map<string,int>ans;

    for(int i=1;i<=people_count;i++)
    {
        gangcount=0;
        weightcount=0;
        maxweight=-1;
        if(search_enable[i]==false)
        {
            
            search(i);
            if(weightcount>K*2&&gangcount>=3)
            {
                headcount++;
                //cout<<max_head<<" "<<gangcount<<endl;
                ans[max_head]=gangcount;
            }

        }
    }
    cout<<headcount<<endl;  
  
    for(iter = ans.begin(); iter != ans.end(); iter++)  
    {
        cout<<iter->first<<" "<<iter->second<<endl;
    }

    return 0;


}