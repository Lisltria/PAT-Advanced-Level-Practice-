#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <cmath>
using namespace std;

unordered_map<int, int> list;

bool isPrime(int x)
{
    for (int i = 2; i <= sqrt(x);i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N;i++)
    {
        int t;
        cin >> t;
        if(i==1)
        {
            list.insert(pair<int, int>(t, 1));
        }
        else if(isPrime(i))
        {
            list.insert(pair<int, int>(t, 2));
        }
        else
        {
            list.insert(pair<int, int>(t, 3));
        }
    }
    int K;
    cin >> K;
    for (int i = 0; i < K;i++)
    {
        int t;
        cin >> t;
        printf("%04d: ", t);
        if(list.find(t)==list.end())
        {
            cout << "Are you kidding?" << endl;
        }
        else if(list[t]==1)
        {
            cout << "Mystery Award" << endl;
            list[t] = 4;
        }
        else if(list[t]==2)
        {
            cout << "Minion" << endl;
            list[t] = 4;
        }
        else if(list[t]==3)
        {
            cout << "Chocolate" << endl;
            list[t] = 4;
        }
        else if(list[t]==4)
        {
            cout << "Checked" << endl;
        }
    }
        return 0;
}