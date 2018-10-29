#include <iostream>
#include <queue>
using namespace std;

queue<long int> q,p;

int main()
{
    int N,M,count=0,ans,mid;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        long int t;
        cin>>t;
        q.push(t);
    }
    cin>>M;
    mid=1.0*(N+M)/2+0.5;
    for(int i=1;i<=M;i++)
    {
        long int t;
        cin>>t;
        p.push(t);
        if(!q.empty()&&!p.empty()&&q.front()<=p.front())
        {
            count++;
            if(count==mid)
            {
                cout<<q.front()<<endl;
                break;
            }
            q.pop();  
        }
        if(!q.empty()&&!p.empty()&&q.front()>p.front())
        {
            count++;
            if(count==mid)
            {
                cout<<p.front()<<endl;
                break;
            }
            p.pop();
        }
        if(!q.empty()&&p.empty())
        {
            count++;
            if(count==mid)
            {
                cout<<q.front()<<endl;
                break;
            }
            q.pop();
        }
        if(q.empty()&&!p.empty())
        {
            count++;
            if(count==mid)
            {
                cout<<p.front()<<endl;
                break;
            }
            p.pop();
        }
    }
    return 0;
}