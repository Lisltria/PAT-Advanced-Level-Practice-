#include <iostream>
#include <cstdio>
using namespace std;

int N;
int main()
{
    cin >> N;
    double ans = 0;
    for (int i = 1; i <= N;i++)
    {
        double t;
        cin >> t;
        ans =ans+ 1.0*(N + 1 - i) * i * t;
    }
    printf("%.2lf\n", ans);
    return 0;
}