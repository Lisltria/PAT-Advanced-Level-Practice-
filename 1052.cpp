#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef struct 
{
    int adr;
    int key;
    int next;
}node;
map<int,node>memory;
vector<node>ans;
bool cmp(node a,node b)
{
    return a.key<b.key;
}
int main()
{
    int N;
    int Start;
    cin>>N>>Start;
    for(int i=1;i<=N;i++)
    {
        node t;
        cin>>t.adr>>t.key>>t.next;
        memory[t.adr]=t;
    }
    int iter=Start;
    while(iter!=-1)
    {
        if(memory.find(iter)==memory.end())break;
        ans.push_back(memory[iter]);
        iter=memory.find(iter)->second.next;
    }
    
    if(ans.empty())
    {
        printf("0 -1\n");
        return 0;
    }
    else
    {
        sort(ans.begin(),ans.end(),cmp);

        printf("%d %05d\n",ans.size(),(ans.begin())->adr);
    }
    for(auto i=ans.begin();i!=ans.end();i++)
    {
        int t;
        auto j=i+1;
        if(j!=ans.end())
        {
            t=j->adr;
            printf("%05d %d %05d\n",i->adr,i->key,t);
        }
        else 
        {
            t=-1;
            printf("%05d %d %d\n",i->adr,i->key,t);
        }
        
    }

    return 0;
}