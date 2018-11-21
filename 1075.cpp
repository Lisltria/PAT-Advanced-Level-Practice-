#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N,K,M;
typedef struct node{
    int ID,total;
    int c[6];
    int sc[6];
    int perfect;
    bool enable;
    node():total(0),perfect(0),sc({-1,-1,-1,-1,-1,-1}),enable(false){}
}person;
person list[100001];
vector<person> ans;
int problems[6];
bool cmp(person a,person b)
{
    if(a.total==b.total)
    {
        if(a.perfect==b.perfect)
        {
            return a.ID<b.ID;
        }
        return a.perfect>b.perfect;
    }
    else return a.total>b.total;
}
int main(int argc, char const *argv[])
{
    /* code */
    cin>>N>>K>>M;
    for(int i=1;i<=K;i++)
    {
        cin>>problems[i];
    }
    for(int i=1;i<=M;i++)
    {
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
      
        if(list[t1].enable==false)
        {
            person t;
            t.ID=t1;
            t.c[t2]=t3;
            t.sc[t2]=1;  
            t.enable=true;
            list[t1]=t;  
        }
        else
        {
            person t;
            t=list[t1];
            if(t.sc[t2]==-1)
            {
                t.sc[t2]=1;
                t.c[t2]=t3;
            }
            else
            {
                t.sc[t2]++;
                if(t.c[t2]<t3)
                {
                    t.c[t2]=t3;
                }
            }
            list[t1]=t;
        }
    }
    for(int i=1;i<=N;i++)
    {
        if(list[i].enable==true)
        {
            bool flag=false;
            person t;
            t=list[i];
            for(int j=1;j<=K;j++)
            {
                
                if(t.sc[j]!=-1&&t.c[j]!=-1)
                {
                    flag=true;
                }
            }
            for(int j=1;j<=K;j++)
            {

                if(t.sc[j]!=-1&&t.c[j]>=0)
                {
                    t.total+=t.c[j];
                    if(t.c[j]==problems[j])t.perfect++;
                }
            }
            if(flag)ans.push_back(t);
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    int rank=1;
    for(int i=0;i<ans.size();i++)
    {
        if(i>0&&ans[i].total!=ans[i-1].total)
        {
            rank=i+1;
        }
        printf("%d %05d",rank,ans[i].ID);
        cout<<" "<<ans[i].total;
        for(int j=1;j<=K;j++)
        {
            if(ans[i].sc[j]==-1)
            {
                cout<<" -";
            }
            else
            {
                if(ans[i].c[j]==-1)cout<<" 0";
                else cout<<" "<<ans[i].c[j];
            }
        }
        cout<<endl;
    }
    
    return 0;
}
