#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> ans;
int main()
{
    int D, N;
    cin >> D >> N;
    ans.push_back(D);
    for (int i = 1; i <= N-1;i++)
    {
        vector<int> t;
        vector<int>::iterator iter = ans.begin();
        int count = 1;

        for (iter = ans.begin(); ;)  
        {
            if((iter + 1) == ans.end()||(iter ) == ans.end())
            {
                break;
            }
            if (*iter != *(iter + 1))
            {
                t.push_back(*iter);
                t.push_back(count);
                count = 1;
                iter++;
            }
            else
            {
                iter++;
                count++;
            }
        }
        t.push_back(*iter);
        t.push_back(count);
        ans.clear();
        for (auto iter2 = t.begin(); iter2 != t.end();iter2++)
        {
            ans.push_back(*iter2);
  
        }
    }
    for (auto iter2 = ans.begin(); iter2 != ans.end();iter2++)
    {
            
        cout << *iter2;
    }
    return 0;
}