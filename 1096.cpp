#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

queue<long long> ans;
int main()
{
    long long N;
    long long product = 1;
    long long otherNum;
    int maxSize = 0,lastNum;
    cin >> N;
    for (int i = 1; i <= sqrt(N)+1;)
    {
        if(N%product==0)
        {
            if(ans.size()>maxSize)
            {
                maxSize = ans.size();
                lastNum = ans.back();
            }
            i++;
            ans.push(i);
            product *= i;
            
            
        }
        else
        {
            product /= ans.front();
            ans.pop();
        }
   
    }
    if(maxSize==0)
    {
        cout << "1" << endl
             << N << endl;
    }
    else
    {
        product = 1;
        for (int i = 0; i < maxSize;i++)
        {
            product *= (lastNum - i);
        }

        cout << maxSize << endl;
        for (long long i = lastNum - maxSize + 1; i < lastNum;i++)
        {
            cout << i << "*";
        }
        cout << lastNum << endl;
    }
    return 0;
} 