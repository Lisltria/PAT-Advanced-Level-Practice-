#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    char c,s[10];
    string num[10]={
        "zero","one","two","three","four","five",
        "six","seven","eight","nine"
    };
    int sum=0;

    while (cin.get(c))
    {
        if(c>='0'&&c<='9')
        {
            sum+=c-48;
        }
        else{
            break;
        }
    }
    sprintf(s,"%d",sum);
    bool flag=false;
    for(int i=0;i<strlen(s);i++)
    {
        if(!flag)flag=true;
        else cout<<" ";
        cout<<num[s[i]-48];
    }
    cout<<endl;
    return 0;
}
