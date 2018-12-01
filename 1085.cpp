#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, p;
vector<int> list;
int main(int argc, char const *argv[])
{
    /* code */
    cin >> N >> p;
    for (int i = 0; i < N; i++)
    {
        int x;
        scanf("%d", &x);
        list.push_back(x);
    }
    sort(list.begin(), list.end());
    int i=0, j=0;
    double d_p = p;
    double d_t1, d_t2;
    while(i<list.size()&&j<list.size())
    {
        d_t1 = list[j];
        d_t2 = list[i];
        if(d_t1/d_t2<=p)
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    cout << j - i << endl;

    return 0;
}
