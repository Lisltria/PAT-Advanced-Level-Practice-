#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct node
{
    int ID;
    int total;
    int ge;
    int p;
    int rank;
    queue<int> applist;
    node(int v):ID(v){}
    node():ID(){}
}person;
int school[100];
vector<person> student;

priority_queue<int,vector<int>,greater<int> > ans[100];

person last[100];
bool cmp(person &a,person &b)//需要使用引用参数
{
    if(a.total==b.total)
    {
        return a.ge>b.ge;
    }
    else return a.total>b.total;
}
bool cmp1(person a, person b) { return a.ID < b.ID; }

int N,K,M;
int main()
{
    cin>>N>>K>>M;
    for(int i=0;i<K;i++)
    {
        cin>>school[i];
        last[i].total = -1;
        last[i].ge = -1;
    }
    for(int i=0;i<N;i++)
    {
        person t(i);
        scanf("%d %d", &t.ge, &t.total);
        t.total+=t.ge;
        for(int j=0;j<M;j++)
        {
            int x;
            scanf("%d", &x);
            t.applist.push(x);
        }
        student.push_back(t);
    }
    sort(student.begin(), student.end(), cmp);
    for (auto iter = student.begin(); iter != student.end();iter++)
    {
        while(!iter->applist.empty())
        {
            if(school[iter->applist.front()]>0||
                (last[iter->applist.front()].total==iter->total&&
                 last[iter->applist.front()].ge==iter->ge)
                )
            {
                ans[iter->applist.front()].push(iter->ID);
                school[iter->applist.front()]--;
                last[iter->applist.front()].total = iter->total;
                last[iter->applist.front()].ge = iter->ge;
                iter->applist.pop();
                break;
            }
            iter->applist.pop();
        }
    }
    for (int i = 0; i < K;i++ )
    {
        bool flag = false;
        while(!ans[i].empty())
        {
            if(!flag)
            {
                flag = true;
            }
            else
                cout << " ";
            cout << ans[i].top();
            ans[i].pop();
        }
        cout << endl;
    }
    return 0;
}