#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node
{
    int ID;
    int t;
    int v;
    int r;
}person;
vector<person> sages,noblemen,foolmen,others;

bool cmp(person a,person b)
{
    if((a.v+a.t)==(b.v+b.t))
    {
        if(a.v==b.v)
            return a.ID<b.ID;
        else return a.v>b.v;
    }
    return (a.v+a.t)>(b.v+b.t);
}

int main()
{
    int N,L,H;
    cin>>N>>L>>H;
    for(int i=0;i<N;i++)
    {
        int t1,t2,t3;
        scanf("%d %d %d",&t1,&t2,&t3);
        if(t2<L||t3<L)continue;
        if(t2>=H&&t3>=H)
        {
            person txx;
            txx.ID=t1;
            txx.v=t2;
            txx.t=t3;
            txx.r=1;
            sages.push_back(txx);
        }
        else if(t2>=H&&t3<H)
        {
            person txx;
            txx.ID=t1;
            txx.v=t2;
            txx.t=t3;
            txx.r=2;
            noblemen.push_back(txx);
        }
        else if(t2<H&&t3<H&&t2>=t3)
        {
            person txx;
            txx.ID=t1;
            txx.v=t2;
            txx.t=t3;
            txx.r=3;
            foolmen.push_back(txx);
        }
        else
        {
            person txx;
            txx.ID=t1;
            txx.v=t2;
            txx.t=t3;
            txx.r=4;
            others.push_back(txx);
        }
    }
    sort(sages.begin(),sages.end(),cmp);
    sort(noblemen.begin(),noblemen.end(),cmp);
    sort(foolmen.begin(),foolmen.end(),cmp);
    sort(others.begin(),others.end(),cmp);
    cout<<others.size()+sages.size()+noblemen.size()+foolmen.size()<<endl;
    for(auto iter=sages.begin();iter!=sages.end();iter++)
    {
        printf("%d %d %d\n",iter->ID,iter->v,iter->t);
    }
    for(auto iter=noblemen.begin();iter!=noblemen.end();iter++)
    {
        printf("%d %d %d\n",iter->ID,iter->v,iter->t);
    }
    for(auto iter=foolmen.begin();iter!=foolmen.end();iter++)
    {
        printf("%d %d %d\n",iter->ID,iter->v,iter->t);
    }
    for(auto iter=others.begin();iter!=others.end();iter++)
    {
        printf("%d %d %d\n",iter->ID,iter->v,iter->t);
    }

    return 0;
}