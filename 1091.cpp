#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
//过大的数据规模使用BFS
int M, N, L, T;
bool brain[70][1300][130];
int count = 0;
typedef struct node
{
    int cen;
    int hen;
    int zon;
} pos;
queue<pos> ss;
void DFS(int l,int x,int y)
{
    pos t;
    t.cen = l;
    t.hen = x;
    t.zon = y;
    
    ss.push(t);
    while(!ss.empty())
    {
        pos p = ss.front();
        ss.pop();
        brain[p.cen][p.hen][p.zon] = false;
        count++;
        t = p;
        if(t.cen+1<60&&brain[t.cen+1][t.hen][t.zon])
        {
            t.cen++;
            brain[t.cen][t.hen][t.zon] = false;
            ss.push(t);
        }
        t = p;
        if(t.hen+1<1286&&brain[t.cen][t.hen+1][t.zon])
        {
            t.hen += 1;
            brain[t.cen][t.hen][t.zon] = false;
            ss.push(t);
        }
        t = p;
        if(t.zon+1<128&&brain[t.cen][t.hen][t.zon+1])
        {
            t.zon += 1;
            brain[t.cen][t.hen][t.zon] = false;
            ss.push(t);
        }
        t = p;
        if(t.cen-1>=0&&brain[t.cen-1][t.hen][t.zon])
        {
            t.cen -= 1;
            brain[t.cen][t.hen][t.zon] = false;
            ss.push(t);
        }
        t = p;
        if(t.hen-1>=0&&brain[t.cen][t.hen-1][t.zon])
        {
            t.hen -= 1;
            brain[t.cen][t.hen][t.zon] = false;
            ss.push(t);
        }
        t = p;
        if(t.zon-1>=0&&brain[t.cen][t.hen][t.zon-1])
        {
            t.zon -= 1;
            brain[t.cen][t.hen][t.zon] = false;
            ss.push(t);
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int ans = 0;
    cin >> M >> N >> L >> T;
    for (int k = 0; k < L; k++)
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int t;
                scanf("%d", &t);
                brain[k][i][j] = t == 1 ? true : false;
            }
        }
    }
    for (int k = 0; k < L; k++)
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                
                if(brain[k][i][j])
                {
                    count = 0;
                    DFS(k, i, j);
                    if(count>=T)
                    {
                        ans += count;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
