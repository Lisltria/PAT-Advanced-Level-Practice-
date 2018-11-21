#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
char num1[200],num2[200];
int N;

void clearZero(vector<char> &n)
{
    for(auto iter=n.begin();iter!=n.end();)
    {
        if((*iter)=='0')
        {
            n.erase(iter);
            //cout<<*iter<<" ";
        }
        else
        {
            //cout<<*iter<<" ";
            break;
        }
    }
}

int find(char *n)
{
    int i,j;
    for(i=0;i<strlen(n);i++)
    {
        if(n[i]=='.')break;
    }
    if(i==strlen(n))
    {
        for(j=0;j<i;j++)
        {
            if(n[j]!='0')break;
        }
        return i-j;
    }
    else
    {
        for(j=0;j<i;j++)
        {
            if(n[j]!='0')break;
        }
        if(j==i)
        {
            for(j=i+1;j<strlen(n);j++)
            {
                if(n[j]!='0')break;
            }
            return -j+(i+1);
        }
        else
        {
            return i-j;
        }
    }
}

bool zeroCheck(vector<char> n)
{
    for(auto iter=n.begin();iter!=n.end();iter++)
    {
        if(*iter!='0')return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<char> n1,n2;
    bool pointF1=false,pointF2=false;
    int p1,p2;
    char ans1[200],ans2[200];
    cin>>N>>num1>>num2;
    for(int i=0;i<strlen(num1);i++)
    {
        if(num1[i]!='.')n1.push_back(num1[i]);
        else {pointF1=true;}
        
    }
    for(int i=0;i<strlen(num2);i++)
    {
        if(num2[i]!='.')n2.push_back(num2[i]);
        else {pointF2=true;}
       
    }
    clearZero(n1);
    clearZero(n2);
    if(pointF1)
    {
        reverse(n1.begin(),n1.end()); 
        clearZero(n1);
        reverse(n1.begin(),n1.end());
    }
    if(pointF2)
    {
        reverse(n2.begin(),n2.end());
        clearZero(n2);
        reverse(n2.begin(),n2.end());
    }
   
    p1=find(num1);
    p2=find(num2);
    if(zeroCheck(n1))p1=0;
    if(zeroCheck(n2))p2=0;

    for(int i=0;i<N;i++)
    {
        if(i<n1.size())
        {
            ans1[i]=n1[i];
        }
        else
        {
            ans1[i]='0';
        }
        if(i<n2.size())
        {
            ans2[i]=n2[i];
        }
        else
        {
            ans2[i]='0';
        }
    }
    ans2[N]=ans1[N]='\0';
    if(p1==p2&&strcmp(ans1,ans2)==0)
    {
        cout<<"YES 0."<<ans1<<"*10^"<<p1<<endl;
    }
    else
    {
        cout<<"NO 0."<<ans1<<"*10^"<<p1<<" 0."<<ans2<<"*10^"<<p2<<endl;
    }

    return 0;
}
