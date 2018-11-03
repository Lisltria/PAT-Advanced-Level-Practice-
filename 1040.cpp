
#include<iostream>
#include<string>
using namespace std;
bool Symmetric(string &str,int s,int len)
{
    int i,j,k;
    for(i=s;i<len/2+s;i++)
    {
        if(str[i]!=str[s+len-(i-s)-1]) return false;
    }
    return true;
}
int main()
{
    string str;
    getline(cin,str);
    int maxlen=1;
    int i,j,k;
    for(i=0;i<str.size();i++)
    {
        for(j=1;j<=str.size()-i;j++)
        {
            if(Symmetric(str,i,j)&&j>maxlen) maxlen=j;
        }
    }
    cout<<maxlen<<endl;
    return 0;
}

 
