#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    string s,temp;
    int cnt[1001]={0},chCnt=0;
    bool notStucked[128] = {false};
    bool isStucked[128] = {false};
    bool isPrint[128] = {false};
    string ans;
    int K;
    cin >> K;
    cin.get();
    getline(cin, s);
    for (int i = 0; i < s.size();)
    {
        int j;
        temp.push_back(s[i]);
        for (j = i; j < s.size();j++)
        {
            if(s[j]==s[i])
            {
                cnt[chCnt]++;
            }
            else
            {
                break;
            }
        }
        i = j;
        chCnt++;
    }
    for (int i = 0; i < temp.size();i++)
    {
        if(cnt[i]%K!=0)
        {
            notStucked[temp[i]] = true;
        }
    }
    for (int i = 0; i < temp.size();i++)
    {
        if(cnt[i]%K==0&&notStucked[temp[i]]==false)
        {
            isStucked[temp[i]] = true;
            for (int j = 0; j < cnt[i] / K;j++)
            {
                ans.push_back(temp[i]);
            }
            if(isPrint[temp[i]]==false)
            {
                cout << temp[i];
                isPrint[temp[i]] = true;
            }
        }
        else
        {
            for (int j = 0; j < cnt[i] ;j++)
            {
                ans.push_back(temp[i]);
            }
        }
    }
   
    cout << endl;
    cout << ans << endl;
    return 0;
}