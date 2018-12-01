#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <map>
using namespace std;

int pre[50010], in[50010];
map<int, int> hhh;
typedef struct node
{
    int si, ei;
    int sp, ep;
}status;
stack<status> s;
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> pre[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> in[i];
        hhh[in[i]] = i;
    }

    status first;
    first.si = 0;
    first.ei = N - 1;
    first.sp = 0;
    first.ep = N - 1;
    s.push(first);
    while(!s.empty())
    {
        status now = s.top();
        if(now.si==now.ei)
        {
            cout << pre[now.sp] << endl;
            break;
        }
        else
        {
            status lc, rc;
            int i;

            i = hhh[pre[now.sp]];
            lc.si = now.si;
            lc.ei = i - 1;
            lc.sp = now.sp + 1;
            lc.ep = now.sp + i - now.si;

            rc.si = i + 1;
            rc.ei = now.ei;
            rc.sp = now.sp + i - now.si + 1;
            rc.ep = now.ep;
            
            if(lc.sp<=lc.ep)
            {
                s.push(lc);
            }
            else
            {
                if(rc.sp<=rc.ep)
                {
                    s.push(rc);
                }
            }
        }
    }
    return 0;
}