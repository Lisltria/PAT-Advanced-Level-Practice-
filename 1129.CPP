#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef struct node
{
    int time;
    int item;
    bool operator < (const node &b)const
    {
         if(time==b.time)
        {
            return item < b.item;
        }
        else 
            return time > b.time;
    }
} Video;
map<Video,Video> q;

int hhh[50001];
int main()
{
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N;i++)
    {
        int t;
        Video tNode;
        cin >> t;
        tNode.time = hhh[t];
        tNode.item = t;
        if(i==0)
        {
            ;
        }
        else
        {
            cout << t<< ":";
            int count = 0;
            map<Video,Video>::iterator iter = q.begin();
            while(count<q.size()&&count<K)
            {
                printf(" %d", iter->second.item);
                iter++;
                count++;
            }
            cout<<endl;
        }
        if(q.find(tNode)==q.end())
        {
            tNode.item = t;
            tNode.time = 1;
            q[tNode] = tNode;
            //printf(" (%d -1) ", tNode.item);
        }
        else
        {
            q.erase(tNode);
            tNode.time++;
            q[tNode] = tNode;
        }
        hhh[t]++;
    }
    return 0;
}