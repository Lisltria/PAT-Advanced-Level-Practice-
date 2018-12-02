#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> vs[501];
int setCnt=1;
int setEV[501];

int v[501];
int N,M;
int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        v[t1]++;
        v[t2]++;
        if(setEV[t1]==0&&setEV[t2]==0)
        {
            vs[setCnt].push_back(t1);
            vs[setCnt].push_back(t2);
            setEV[t1] = setCnt;
            setEV[t2] = setCnt;
            setCnt++;
        }
        else if(setEV[t1]!=0&&setEV[t2]==0)
        {
            vs[setEV[t1]].push_back(t2);
            setEV[t2] = setEV[t1];
        }
        else if(setEV[t1]==0&&setEV[t2]!=0)
        {
            vs[setEV[t2]].push_back(t1);
            setEV[t1] = setEV[t2];
        }
        else if(setEV[t1]!=0&&setEV[t2]!=0&&setEV[t1]!=setEV[t2])
        {
            int tt;
            for (vector<int>::iterator iter = vs[setEV[t2]].begin(); iter != vs[setEV[t2]].end();iter++)
            {
                tt = *iter;
                if(tt==t2)
                    continue;
                setEV[tt] = setEV[t1];
                vs[setEV[t1]].push_back(tt);
            }
            vs[setEV[t2]].clear();
            setEV[t2] = setEV[t1];
        }
    }
    int CntMultiSet = 0;
    bool flag = true;
    for (int i = 1;i<setCnt;i++)
    {
        if(vs[i].size()>=2)
        {
            CntMultiSet++;
        }
    }
    if(CntMultiSet>=2)
    {
        flag = false;
    }
    int odd = 0;
    int even = 0;
    for (int i = 1; i <= N;i++)
    {
        if(i==1)
            cout << v[i];
        else
            cout << " " << v[i];
        if(v[i]%2==1)
            odd++;
        if(v[i]>0&&v[i]%2==0)
            even++;
    }
    cout << endl;
    if(flag==false)
    {
        cout << "Non-Eulerian" << endl;
    }
    else if(odd==0)
    {
        cout << "Eulerian" << endl;
    }
    else if(odd==2)
    {
        cout << "Semi-Eulerian" << endl;
    }
    else
    {
        cout << "Non-Eulerian" << endl;
    }
    return 0;
}