#include <iostream>
#include <cstdio>
#include <unordered_set>
using namespace std;

unordered_set<int> set[51];
int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N;i++)
    {
        int K;
        cin >> K;
        for (int j = 0; j < K;j++)
        {
            int t;
            scanf("%d", &t);
            set[i].insert(t);
        }
    }
    int M;
    cin >> M;
    for (int i = 0; i < M;i++)
    {
        int t1, t2, count = 0;

        cin >> t1 >> t2;
        for (auto iter = set[t1].begin(); iter != set[t1].end();iter++)
        {
            if(set[t2].find(*iter)!=set[t2].end())
            {
                count++;
            }
           
        }
       
        double ans = 0.0;
        char c = '%';
        ans = 100.0 * count / (set[t1].size() + set[t2].size() - count);
        printf("%.1lf%c\n", ans,c);
    }
    return 0;
}