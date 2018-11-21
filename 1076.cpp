#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> users[1001];
int N,L,K;

int BFS(int start)
{
    bool usr_enable[1001]={false};
    int count=0;
    typedef struct node{
        int user;
        int level;
    }Node;
    queue<Node> q;
    Node it;
    it.level=0;it.user=start;usr_enable[start]=true;
    q.push(it);
    while(!q.empty())
    {
        Node t,t2;
        t=q.front();
        q.pop();
        //cout<<t.user<<" ";
        if(t.level>=1&&t.level<=L)count++;
        if(t.level>=L)continue;
        
        for(vector<int>::iterator iter=users[t.user].begin();iter!=users[t.user].end();iter++)
        {
            if(usr_enable[*iter]==false)
            {
                t2.user=*iter;
                t2.level=t.level+1;
                q.push(t2);
                usr_enable[*iter]=true;
            }
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    /* code */
    cin>>N>>L;
    for(int i=1;i<=N;i++)
    {
        int M;
        cin>>M;
        for(int j=0;j<M;j++)
        {
            int t;
            cin>>t;
            users[t].push_back(i);
        }
    }
    cin>>K;
    for(int i=0;i<K;i++)
    {
        int t;
        cin>>t;
        cout<<BFS(t)<<endl;
    }

    return 0;
}
