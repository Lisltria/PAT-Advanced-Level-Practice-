#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> list;
int main()
{
    int N;
    double ans = 0.0;
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        int t;
        cin >> t;
        list.push_back(t);
    }
    sort(list.begin(), list.end());
    ans = list[0];
    for (int i = 1; i < N;i++)
    {
        ans = (ans + list[i]) / 2;
    }
    cout << (int)ans << endl;
    return 0;
}