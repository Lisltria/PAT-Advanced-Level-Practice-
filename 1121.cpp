#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
unordered_map<int,int> couples;
unordered_set<int> q;
vector<int> ans;
int main(int argc, char const *argv[])
{
    /* code */
    int N;
    cin>>N;
    for (int i = 0; i < N;i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        couples[t1] = t2;
        couples[t2] = t1;
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int t;
        cin >> t;
        q.insert(t);
    }
    for (auto iter = q.begin(); iter != q.end();iter++)
    {
        int p1 = *iter;
        if(couples.find(p1)==couples.end())
        {
            ans.push_back(p1);
        }
        else
        {
            int p2 = couples[p1];
            if(q.find(p2)==q.end())
            {
                ans.push_back(p1);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    if(ans.size()>0)
    {
        for (auto iter = ans.begin() ; iter != ans.end(); iter++)
        {
            if(iter != ans.begin())
                cout << " ";
            printf("%05d", *iter);
        }
        cout << endl;
    }
    return 0;
}
