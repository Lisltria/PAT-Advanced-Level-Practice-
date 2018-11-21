#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
using namespace std;

typedef struct node
{
    int from;
    int data;
    int next;
}link;

map<int,link> list;
vector<link> temp,ans;
int main(int argc, char const *argv[])
{
    /* code */
    int start_point;
    int N,K;
    cin>>start_point>>N>>K;
    for(int i=0;i<N;i++)
    {
        int t1,d1,n1;
        link t;
        cin>>t1>>d1>>n1;
        t.from=t1;
        t.data=d1;t.next=n1;
        list[t1]=t;
    }
    int mem=start_point;
    while(mem!=-1)
    {
        temp.push_back(list[mem]);
        if(temp.size()==K)
        {
            auto riter=temp.rbegin();
            for(;riter!=temp.rend();riter++)
            {
               ans.push_back(*riter);

            }
            temp.clear();
        }
        mem=list[mem].next;
    }
    if(temp.size()!=0)
    {
        for(auto riter=temp.begin();riter!=temp.end();riter++)
        {
            ans.push_back(*riter);
        }
        temp.clear();
    }

    for(auto riter=ans.begin();riter!=ans.end();riter++)
    {
        auto iter=riter+1;
        if(iter!=ans.end())
            printf("%05d %d %05d\n",riter->from,riter->data,iter->from);
        else
            printf("%05d %d -1\n",riter->from,riter->data);
 
    }
    return 0;
}
