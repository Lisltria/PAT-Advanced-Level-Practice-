#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int K;
        bool flag = true;
        cin >> K;
        int queen[1001];
        bool column[1001] = {false};
        bool diagonal[2005] = {false};
        bool rdiagonal[2005] = {false};
        for (int j = 1; j <= K;j++)
        {
            cin >> queen[j];
            if(column[queen[j]] == true)
                flag = false;
            if(diagonal[queen[j] + K - j] == true)
                flag = false;
            if(rdiagonal[queen[j]+j-1] == true)
                flag = false;
                
            column[queen[j]] = true;
            diagonal[queen[j] + K - j] = true;
            rdiagonal[queen[j]+j-1] = true;
            //printf(" (%d %d) ", queen[j] + K - j, queen[j] + j - 1);
        }
        if(flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}