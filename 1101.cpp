#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node
{
    int d;
    int rank1;
    int rank2;
} num;
vector<num> ans,fans;
bool cmp1(num &a,num &b)
{
    return a.d < b.d;
}
bool cmp2(num &a,num &b)
{
    return a.rank1 < b.rank1;
}
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        num t;
        cin >> t.d;
        t.rank1 = i;
        ans.push_back(t);
    }
    sort(ans.begin(), ans.end(), cmp1);
    for (int i = 0; i < N; i++)
    {
        ans[i].rank2 = i;
    }
    sort(ans.begin(), ans.end(), cmp2);
    int maxRank = -1;
    for (int i = 0; i < N; i++)
    {
        if(ans[i].rank2>maxRank)
        {
            maxRank = ans[i].rank2;
        } 
        if(ans[i].rank2==ans[i].rank1&&ans[i].rank2>=maxRank)
        {
            fans.push_back(ans[i]);
        }
    }
    sort(fans.begin(), fans.end(), cmp1);
    cout << fans.size() << endl;
    for (int i = 0; i < fans.size();i++)
    {
        if(i!=0)
            cout << " ";
        cout << fans[i].d;
    }
    cout << endl;
    return 0;
}