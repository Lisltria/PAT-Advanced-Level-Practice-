#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

typedef struct node
{
    int addr;
    int data;
    int next;
}theNode;
vector<theNode> list,ans;
map<int,int>addr2num;
int addrCount = 0;

int main()
{
    int N, K;
    int origin;
    cin >> origin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        theNode t;
        cin >> a >> b >> c;
        t.addr = a;
        t.data = b;
        t.next = c;
        addr2num[a] = addrCount;
        addrCount++;
        list.push_back(t);
    }

    int iterAddr=origin;
    while(iterAddr!=-1)
    {
        int theNum = addr2num[iterAddr];
        theNode t = list[theNum];
        if(t.data<0)
        {
            ans.push_back(t);
        }
       
        iterAddr = t.next;
    }

     iterAddr=origin;
    while(iterAddr!=-1)
    {
        int theNum = addr2num[iterAddr];
        theNode t = list[theNum];
        if(t.data<0)
        {
            
        }
        else if(t.data>=0&&t.data<=K)
        {
            ans.push_back(t);
        }
       
        iterAddr = t.next;
    }

     iterAddr=origin;
    while(iterAddr!=-1)
    {
        int theNum = addr2num[iterAddr];
        theNode t = list[theNum];
        if(t.data<0)
        {
            
        }
        else if(t.data>=0&&t.data<=K)
        {
            
        }
        else
        {
            ans.push_back(t);
        }
        iterAddr = t.next;
    }
    for (auto iter = ans.begin(); iter != ans.end();iter++)
    {
        if(iter+1==ans.end())
        {
            printf("%05d %d -1\n", iter->addr, iter->data);
        }
        else
        {
            printf("%05d %d %05d\n", iter->addr, iter->data,(iter+1)->addr);
        }
    }

    return 0;
}