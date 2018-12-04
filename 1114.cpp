#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int estate[10000][2]={0,0};
bool hasBeCnt[10000]={false};

typedef struct node
{
    int ID;
    int nS;
    int A;
    int M;
} ansNode;

bool cmp(ansNode &a,ansNode &b)
{
    if(abs(1.0*a.A/a.M-1.0*b.A/b.M)<0.00001)
    {
        return a.ID < b.ID;
    }
    else
        return 1.0*a.A/a.M > 1.0*b.A/b.M;
}

vector<int> edge[10000];
vector<ansNode> ans;
int main(int argc, char const *argv[])
{
    /* code */
    int N;
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        if(B!=-1)edge[A].push_back(B);
        if(C!=-1)edge[A].push_back(C);

        if(C!=-1&&B!=-1)edge[C].push_back(B);
        if(C!=-1)edge[C].push_back(A);

        if(B!=-1)edge[B].push_back(A);
        if(B!=-1&&C!=-1)edge[B].push_back(C);
        int K;
        cin >> K;
        for (int j = 0; j < K;j++)
        {
            int t;
            cin >> t;
            edge[A].push_back(t);
            edge[t].push_back(A);
        }
        int sets, area;
        cin >> sets >> area;
        estate[A][0] = sets;
        estate[A][1] = area;
    }
    for (int i = 0; i <= 9999;i++)
    {
        if(estate[i][0]!=0&&hasBeCnt[i]==false)
        {
            queue<int> q;
            q.push(i);
            int sumS = 0, sumA = 0, minID = 10000, tM = 0;
            
            while(!q.empty())
            {
                int t = q.front();
                tM++;
                if(t<minID)
                {
                    minID = t;
                }
                q.pop();
                hasBeCnt[t] = true;
                sumS += estate[t][0];
                sumA += estate[t][1];
                //printf(" (%d %d) ",sumS, sumA);
                for (auto iter = edge[t].begin(); iter != edge[t].end();iter++)
                {
                    if(hasBeCnt[*iter]==false)
                    {
                        hasBeCnt[*iter] = true;
                        q.push(*iter);
                    }
                }
            }
            //cout << endl;
            ansNode t;
            t.ID = minID;
            t.A = 1.0*sumA/1;
            t.nS = sumS;
            t.M = tM;
            //printf(" (%d %f) \n",t.nS, t.A);
            ans.push_back(t);
            
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << ans.size() << endl;

    for (int i = 0; i < ans.size();i++)
    {
        printf("%04d %d %.3lf %.3lf\n", ans[i].ID, ans[i].M, 1.0*ans[i].nS/ans[i].M, 1.0*ans[i].A/ans[i].M);
    }

    return 0;
}

