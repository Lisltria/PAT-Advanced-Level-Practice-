#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
int N;

vector<string> cmdlist;
vector<int> datalist;
vector<int> ans;
int cmd_p = 0;
void DFS()
{
    string s;
    int num;
    bool readyForReturn=false;
    if(cmd_p>=cmdlist.size())
        return;
    if(cmd_p<cmdlist.size()&&cmdlist[cmd_p]=="Push")
    {
        num = datalist[cmd_p];
    }

    if(cmd_p+1<cmdlist.size()&&cmdlist[cmd_p+1]=="Push")
    {
        cmd_p++;
        DFS();
    }
    else if(cmd_p+1<cmdlist.size()&&cmdlist[cmd_p+1]=="Pop")
    {
        cmd_p++;
        if(cmd_p+1<cmdlist.size()&&cmdlist[cmd_p+1]=="Push")
        {
            cmd_p++;
            DFS();
        }
        else if(cmd_p+1<cmdlist.size()&&cmdlist[cmd_p+1]=="Pop")
        {
            ans.push_back(num);
            return;
        }
    }

    if(cmd_p+1<cmdlist.size()&&cmdlist[cmd_p+1]=="Push")
    {
        cmd_p++;
        DFS();
    }
    else if(cmd_p+1<cmdlist.size()&&cmdlist[cmd_p+1]=="Pop")
    {
        cmd_p++;
        if(cmd_p+1<cmdlist.size()&&cmdlist[cmd_p+1]=="Push")
        {
            cmd_p++;
            DFS();
        }
        else if(cmd_p+1<cmdlist.size()&&cmdlist[cmd_p+1]=="Pop")
        {
            ans.push_back(num);
            return;
        }
    }
    ans.push_back(num);
    return;
}

int main()
{
    cin >> N;cin.get();
    for (int i = 0; i < 2 * N; i++)
    {
        string s;
        int num;
        cin >> s;
        cin.get();
        if(s=="Push")
        {
            cin >> num;
            cin.get();
            cmdlist.push_back(s);
            datalist.push_back(num);
        }
        else if(s=="Pop")
        {
            num = -1;
            cmdlist.push_back(s);
            datalist.push_back(num);
        }
    }
    DFS();
    if(!ans.empty())
    {
        cout << *ans.begin();
        for (auto i = ans.begin() + 1; i != ans.end(); i++)
        {
            cout << " " << *i;
        }
        cout << endl;
    }
    return 0;
}