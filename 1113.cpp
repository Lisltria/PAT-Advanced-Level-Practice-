#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 0; i < N / 2;i++)
    {
        sum += v[N - 1 - i] - v[i];
    }
    if(N%2==1)
    {
        sum += v[N / 2];
        cout << "1 " << sum << endl;
    }
    else
    {
        cout << "0 " << sum << endl;
    }
        return 0;
}