#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int Np,Ng;
typedef struct node
{
    int W;
    int R;
    int orgin_R;
    int final_R;
    bool s;
}mouse;
mouse mice[1001];
bool cmp(mouse a,mouse b)
{
    return a.R<b.R;
}
bool cmp1(mouse a,mouse b)
{
    return a.orgin_R<b.orgin_R;
}

int main()
{
    cin>>Np>>Ng;
    for(int i=0;i<Np;i++)
    {
        cin>>mice[i].W;
        mice[i].orgin_R=i;
        mice[i].s=false;
        mice[i].final_R=-1;
    }
    for(int i=0;i<Np;i++)
    {
        int t;
        cin>>t;mice[t].R=i;
    }
    sort(mice,mice+Np,cmp);
    int pace=1;
    while(pace<Np)
    {
        int i=0,j,count=0;
        while(i<Np)
        {
            int max=-1,max_p;;
            for(j=0;j<Ng*pace;j++)
            {
                if(i+j>=Np)break;
                if(mice[i+j].s==false)
                {
                    if(mice[i+j].W>max)
                    {
                        max=mice[i+j].W;
                        max_p=i+j;
                    }
                    mice[i+j].s=true;
                }
            }
            mice[max_p].s=false;
            count++;
            i+=j;
        }
        for(i=0;i<Np;i++)
            if(mice[i].s&&mice[i].final_R==-1)
                mice[i].final_R=count+1;
        if(count==1)
        {
            for(i=0;i<Np;i++)
                if(mice[i].final_R==-1)
                    mice[i].final_R=1;
        }
        pace*=Ng;
    }
    for(int i=0;i<Np;i++)
                if(mice[i].final_R==-1)
                    mice[i].final_R=1;
    sort(mice,mice+Np,cmp1);
    printf("%d",mice[0].final_R);
    for(int i=1;i<Np;i++)
    {
       
        printf(" %d",mice[i].final_R);
    }
    cout<<endl;
    return 0;
}
/* 10 3
25 18 0 46 37 3 19 22 57 56
0 1 2 3 4 5 6 7 8 9*/