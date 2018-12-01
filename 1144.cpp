#include <iostream>
#include <cstdio>
#include <set>
#include <climits>

using namespace std;

set<long> nextNum,nowNum;
int main()
{
    int N;
    int minInput = INT32_MAX, maxInput = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        long t;
        cin >> t;
        if(t>0)
        {
            nowNum.insert(t);
            nextNum.insert(t + 1);
            if(t<minInput)
            {
                minInput = t;
            }
            if(t>maxInput)
            {
                maxInput = t;
            }
        }
    }
   
    {
        long min = INT32_MAX;
        for (set<long>::iterator iter = nextNum.begin(); iter != nextNum.end();iter++)
        {
            if(nowNum.find(*iter)==nowNum.end())
            {
                if(*iter<min)
                {
                    min = *iter;
                }
            }
        }
        if(minInput>1)
        {
            cout << "1" << endl;
        }
        else
        {
            cout << min << endl;
        }
    }
   
    return 0;
}