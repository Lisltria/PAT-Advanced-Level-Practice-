#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int N,M;
typedef struct node
{
    int from, to;
    int len, time;
} street;
vector<street> edge[501];

vector<int> ansLenPath;
int dijLen(int s,int e)
{
    bool nodeEn[500] = {false};
    int path[500] = {0};
    int DD[500];
    int DDD[500];
    int refresh;
    int count = 0;
    for (int i = 0; i < N;i++)
    {
        DD[i] = INT32_MAX;
        DDD[i] = INT32_MAX;
        path[i] = -1;
    }

    refresh = s;
    nodeEn[s] = true;
    DD[refresh] = 0;
    DDD[refresh] = 0;
    while(count<N)
    {
        nodeEn[refresh] = true;
        for (auto iter = edge[refresh].begin(); iter != edge[refresh].end();iter++)
        {
            if(nodeEn[iter->to]==false)
            {
                if(DD[iter->to]>DD[refresh]+iter->len)
                {
                    DD[iter->to] = DD[refresh] + iter->len;
                    DDD[iter->to] = DDD[refresh] + iter->time;
                    path[iter->to] = refresh;
                }
                else if(DD[iter->to]==DD[refresh]+iter->len
                        &&DDD[iter->to]>DDD[refresh]+iter->time)
                {
                    DD[iter->to] = DD[refresh] + iter->len;
                    DDD[iter->to] = DDD[refresh] + iter->time;
                    path[iter->to] = refresh;
                }
            }
        }

        int min = INT32_MAX, mini = -1, mino = INT32_MAX;
        for (int i = 0; i < N;i++)
        {
            if(nodeEn[i]==false)
            {
                if(DD[i]<min)
                {
                    min = DD[i];
                    mini = i;
                    mino = DDD[i];
                }
                else if(DD[i]==min&&DDD[i]<mino)
                {
                    min = DD[i];
                    mini = i;
                    mino = DDD[i];
                }
            }
        }
        if(mini==-1)
            break;
        refresh = mini;
        count++;
    }
    int iter = e;
    while(iter!=-1)
    {
        ansLenPath.push_back(iter);
        iter = path[iter];
    }
    reverse(ansLenPath.begin(), ansLenPath.end());
    return DD[e];
}

vector<int> ansTimePath;
int dijTime(int s,int e)
{
    bool nodeEn[500] = {false};
    int path[500] = {0};
    int DD[500];
    int DDD[500];
    int refresh;
    int count = 0;
    for (int i = 0; i < N;i++)
    {
        DD[i] = INT32_MAX;
        DDD[i] = INT32_MAX;
        path[i] = -1;
    }

    refresh = s;
    nodeEn[s] = true;
    DD[refresh] = 0;
    DDD[refresh] = 0;
    while(count<N)
    {
        nodeEn[refresh] = true;
        for (auto iter = edge[refresh].begin(); iter != edge[refresh].end();iter++)
        {
            if(nodeEn[iter->to]==false)
            {
                if(DD[iter->to]>DD[refresh]+iter->time)
                {
                    DD[iter->to] = DD[refresh] + iter->time;
                    DDD[iter->to] = DDD[refresh] + iter->len;
                    path[iter->to] = refresh;
                }
               
            }
        }

        int min = INT32_MAX, mini = -1, mino = INT32_MAX;
        for (int i = 0; i < N;i++)
        {
            if(nodeEn[i]==false)
            {
                if(DD[i]<min)
                {
                    min = DD[i];
                    mini = i;
                    mino = DDD[i];
                }
                else if(DD[i]==min&&DDD[i]<mino)
                {
                    min = DD[i];
                    mini = i;
                    mino = DDD[i];
                }
            }
        }
        if(mini==-1)
            break;
        refresh = mini;
        count++;
    }
    int iter = e;
    while(iter!=-1)
    {
        ansTimePath.push_back(iter);
        iter = path[iter];
    }
    reverse(ansTimePath.begin(), ansTimePath.end());
    return DD[e];
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int v1, v2, one_way, l, t;
        street temp;
        cin >> v1 >> v2 >> one_way >> l >> t;
        temp.from = v1;
        temp.to = v2;
        temp.len = l;
        temp.time = t;
        edge[v1].push_back(temp);
        if(one_way==0)
        {
            temp.from = v2;
            temp.to = v1;
            edge[v2].push_back(temp);
        }
    }
    int start, end;
    cin >> start >> end;
    int ansLen = dijLen(start, end);
    int ansTime = dijTime(start, end);
    bool flag = true;
    if(ansLenPath.size()==ansTimePath.size())
    {
        for (int i = 0; i < ansLenPath.size();i++)
        {
            if(ansLenPath[i]!=ansTimePath[i])
            {
                flag = false;
                break;
            }
        }
    }
    else
    {
        flag = false;
    }
    if(flag)
    {
        printf("Distance = %d; Time = %d: ", ansLen, ansTime);
        for (int i = 0; i < ansLenPath.size();i++)
        {
            if(i!=0)
            {
                cout << " -> ";
            }
            cout << ansLenPath[i];
        }
        cout << endl;
    }
    else
    {
        printf("Distance = %d: ", ansLen);
        for (int i = 0; i < ansLenPath.size();i++)
        {
            if(i!=0)
            {
                cout << " -> ";
            }
            cout << ansLenPath[i];
        }
        cout << endl;
        printf("Time = %d: ", ansTime);
        for (int i = 0; i < ansTimePath.size();i++)
        {
            if(i!=0)
            {
                cout << " -> ";
            }
            cout << ansTimePath[i];
        }
        cout << endl;
    }
    return 0;
}