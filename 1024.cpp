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

bool palindromicNum(char *s)
{
    bool flag=true;
    for(int i=0;i<strlen(s)/2;i++)
    {
        if(s[i]!=s[strlen(s)-i-1])
        {
            flag=false;
            break;
        }
    }
    return flag;
}
char num[1001],num2[1001],ans[1001];
int main()
{
    
    int add;
    int t=0;
    int i,n;
    bool flag=false;

    cin>>num>>n;
   
    if(palindromicNum(num))
    {
        cout<<num<<endl<<"0"<<endl;
        return 0;
    } 
    for(int j=1;j<=n;j++)
    {
        strcpy(num2,num);
        strrevs(num);
        t=0;
        for(i=0;i<strlen(num);i++)
        {
            t=(num[i]-48)+(num2[i]-48)+t;
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
        if(palindromicNum(ans))
        {
            cout<<ans<<endl<<j<<endl;
            flag=true;
            break;
        }
        strcpy(num,ans);
    }
    if(!flag)
    {
        cout<<ans<<endl<<n<<endl;
    }
    return 0;

}