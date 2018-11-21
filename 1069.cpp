#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool cmp(char a,char b)
{
    return a>b;
}
bool cmp1(char a,char b)
{
    return a<b;
}

int s2int(char *s)
{
    return (s[0]-48)*1000+(s[1]-48)*100+(s[2]-48)*10+(s[3]-48);
}
int main()
{
    /* code */
    char a[10],b[10],ans[10];
    int t;
    cin>>t;
    sprintf(a,"%04d",t);
    do
    {
        sort(a,a+4,cmp);
        strcpy(b,a);
        sort(b,b+4,cmp1);
        int a_num,b_num,ans_num;
        a_num=s2int(a);
        b_num=s2int(b);
        ans_num=a_num-b_num;
        sprintf(ans,"%04d",ans_num);
        printf("%s - %s = %s\n",a,b,ans);
        strcpy(a,ans);
    }while(strcmp(a,"6174")!=0&&strcmp(a,"0000")!=0);
    return 0;
}

