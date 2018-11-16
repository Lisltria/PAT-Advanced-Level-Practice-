#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N,K;
typedef struct node
{
    char name[20];
    int age;
    int worth;
}person;
vector<person>Forbes[202];
vector<person>list;
bool cmp(person a,person b)
{
    if(a.worth==b.worth)
    {
        if(a.age==b.age)
        {
            return strcmp(a.name,b.name)<0 ? true:false;
        }
        return a.age<b.age;
    }
    else
    {
        return a.worth>b.worth;
    }
}
int main()
{
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        person t;
        scanf("%s %d %d",t.name,&t.age,&t.worth);
        //Forbes[t.age].push_back(t);
        list.push_back(t);
    }
    sort(list.begin(),list.end(),cmp);
    for(auto iter=list.begin();iter!=list.end();iter++)
    {
        person t=*iter;
        Forbes[t.age].push_back(t);
    }
           
    for(int i=0;i<K;i++)
    {
        int num,Amin,Amax;
        bool flag=false;
        cin>>num>>Amin>>Amax;
        cout<<"Case #"<<i+1<<":"<<endl;
        vector<person>::iterator iter[202];
        vector<person>::iterator iter_t;

        for(int j=Amin;j<=Amax;j++)
        {
            if(Forbes[j].empty())continue;
            flag=true;
        }
        if(!flag)
        {
            cout<<"None"<<endl;
            continue;
        }
        for(int j=1;j<=200;j++)
        {
            iter[j]=Forbes[j].begin();
        }
        for(int j=0;j<num;j++)
        {
            
            int max_worth=-100000000;
            int max_k=-1;
            
            for(int k=Amin;k<=Amax;k++)
            {
                if(iter[k]==Forbes[k].end())continue;
                if(iter[k]->worth>max_worth)
                {
                    max_worth=iter[k]->worth;
                    iter_t=iter[k];
                    max_k=k;
                }
            }
            if(max_k==-1)break;
            else
            {
                cout<<(*iter_t).name<<" "<<(*iter_t).age<<" "<<(*iter_t).worth<<endl;
                iter[max_k]++;
            }
        }
    } 
    return 0;
}