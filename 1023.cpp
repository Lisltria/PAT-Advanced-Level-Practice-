#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

void strrevs(char *s)
{
    for(int i=0;i<strlen(s)/2;i++)
    {
        char t;
        t=s[i];
        s[i]=s[strlen(s)-i-1];
        s[strlen(s)-i-1]=t;
    }
}

int numhash[60],anshash[60];
int main()
{
    char num[22],ans[22];
    int add;
    int t=0;
    int i;

    cin>>num;
    strrevs(num);
    for(i=0;i<strlen(num);i++)
    {
        t=(num[i]-48)*2+t;
        ans[i]=t%10+48;
        t=t/10;
    }
    if(t!=0)
    {
        ans[i]=t+48;
        i++;
        
    }
    ans[i]='\0';
    strrevs(ans);

    for(i=0;i<strlen(num);i++)
    {
        numhash[num[i]]++;
    }
    for(i=0;i<strlen(ans);i++)
    {
        anshash[ans[i]]++;
    }

    bool flag=true;
    for(i='0';i<='9';i++)
    {
        if(anshash[i]!=numhash[i])
            flag=false;
    }

    if(flag)
        cout<<"Yes"<<endl<<ans<<endl;
    else
        cout<<"No"<<endl<<ans<<endl;

    return 0;

}