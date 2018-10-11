#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//test33
void strrever(char *s)
{
    for(int i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        char c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}

int main()
{
    /* code */
    /* A+B Format */
    long int A,B,SUM,n;
    char ans[10],out[12];
    cin>>A>>B;
    SUM=A+B;
    sprintf(ans,"%ld",SUM);
    strrever(ans);
    n=0;
    for(int i=0;i<strlen(ans);i++)
    {
        out[n]=ans[i];
        n++;
        if((i+1)%3==0 && ans[i]!='-' && ans[i+1]!='-' && i!=strlen(ans)-1)
        {
            out[n]=',';
            n++;
        }
    }
    out[n]='\0';
    strrever(out);
    cout<<out<<endl;

    return 0;
}
