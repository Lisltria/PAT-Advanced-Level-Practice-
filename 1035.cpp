#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef struct node{
    char name[20];
    char password[20];
    bool change;
}user;
vector<user>list;
int change_count=0;
bool ffff(char *s)
{
    bool change_flag=false;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='1')
        {
            s[i]='@';
            change_flag=true;
        }
        if(s[i]=='0')
        {
            s[i]='%';
            change_flag=true;
        }
        if(s[i]=='l')
        {
            s[i]='L';
            change_flag=true;
        }
        if(s[i]=='O')
        {
            s[i]='o';
            change_flag=true;
        }
    }
    return change_flag;
}
int main()
{
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        user t;
        cin>>t.name;
        cin>>t.password;
        t.change=false;
        if(ffff(t.password))
        {
            change_count++;
            list.push_back(t);
        }
    }
    if(change_count==0)
    {
        if(N==1)
        {
            cout<<"There is 1 account and no account is modified"<<endl;
        }
        else{
            cout<<"There are "<<N<<" accounts and no account is modified"<<endl;
        }
    }
    else
    {
        cout<<change_count<<endl;
        
        for(auto iter=list.begin();iter!=list.end();iter++)
        {
            cout<<iter->name<<" "<<iter->password<<endl;
        }
    }
    return 0;
}