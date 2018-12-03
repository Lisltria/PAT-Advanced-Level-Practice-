#include <iostream>
#include <cstdio>
using namespace std;

int N, M;
bool mapV[201][201];
int main()
{
    cin >> N >> M;
    for (int i = 0; i < M;i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        mapV[t1][t2] = true;
        mapV[t2][t1] = true;
    }
    int K;
    cin >> K;
    for (int i = 0; i < K;i++)
    {
        int n;
        bool flag = true;
        bool v[201] = {false};
        cin >> n;
        if(n!=N+1)
        {
            flag = false;
        }

        int t, last,first;
        cin >> last;
        first = last;
        v[last] = true;
        for (int j = 1; j < n;j++)
        {
            cin >> t;
            if(flag == false)
            {
                continue;
            }
            if(mapV[last][t]==true)
            {
                if(j==n-1)
                {
                    if(t!=first)
                    {
                        flag = false;
                    }
                }
                else
                {
                    if(v[t]==true)
                    {
                        flag = false;
                    }
                    else
                    {
                        v[t] = true;
                    }
                }
            }
            else
            {
                flag = false;
            }
            last = t;
        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}