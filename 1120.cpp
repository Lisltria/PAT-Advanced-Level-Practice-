#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int N;
    set<int> ans;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t,x=0;
        cin >> t;
        while(t>0)
        {
            x += t % 10;
            t /= 10;
        }
        ans.insert(x);
    }
    cout << ans.size() << endl;
    for (auto iter = ans.begin() ; iter != ans.end(); iter++)
    {
        if(iter != ans.begin())
            cout << " ";
        cout << *iter;
    }
    cout << endl;
    return 0;
}
