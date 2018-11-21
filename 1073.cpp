#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

char num_sign,exp_sign;
string num;
int exp;
int main()
{
    char c;
    cin.get(num_sign);
    while((cin.get(c),c)!='\n'&&c!=EOF)
    {
        if(c=='-'||c=='+')
        {
            exp_sign=c;
            break;
        }
        if(c=='E'||c=='.')continue;
        num.push_back(c);
    }
    cin>>exp;
    if(num_sign=='-')cout<<"-";
    if(num.size()-1==exp&&exp_sign=='+')
    {
        cout<<num;
    }
    else if((num.size()-1>exp&&exp_sign=='+')||(exp==0))
    {
 
        for(int i=0;i<1+exp;i++)
        {
            cout<<num[i];
        }
        cout<<".";
        for(int i=1+exp;i<num.size();i++)
        {
            cout<<num[i];
        }
    }
    else if(num.size()-1<exp&&exp_sign=='+')
    {
        cout<<num;
        for(int i=0;i<exp-num.size()+1;i++)
        {
            cout<<"0";
        }
    }
    else if(exp==1&&exp_sign=='-')
    {
        cout<<"0."<<num;
    }
    else if(exp>1&&exp_sign=='-')
    {
        cout<<"0.";
        for(int i=0;i<exp-1;i++)
        {
            cout<<"0";
        }
        cout<<num;
    }
    cout<<endl;

    return 0;
}