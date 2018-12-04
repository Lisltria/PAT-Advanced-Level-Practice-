#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

typedef struct node
{
    string name;
    int tall;
} person;
vector<person> people;
bool cmp(person &a,person &b)
{
    return a.tall == b.tall ? (a.name < b.name) : (a.tall > b.tall);
}
int main()
{
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N;i++)
    {
        person t;
        cin >> t.name >> t.tall;
        people.push_back(t);
    }
    sort(people.begin(), people.end(), cmp);
    int eachline = N / K;
    int lastline = N - eachline * (K - 1);
    auto iter = people.begin();
    for (int i = 0; i < K;i++)
    {
        int m;
        string ans[10001];
        if(i==0)
        {
            m = lastline;
        }
        else
        {
            m = eachline;
        }
        int left, right;
        right = m / 2;
        right += 1;
        left = right - 1;
        int count = 0;
        while(count<m)
        {
            ans[right] = iter->name;
            right++;
            count++;
            iter++;
            if(count>=m)
                break;
            ans[left] = iter->name;
            left--;
            count++;
            iter++;
        }
        for (int j = 1; j <= m;j++)
        {
            cout << ans[j];
            if(j==m)
                cout << endl;
            else
                cout << " ";
        }
    }
    return 0;
}