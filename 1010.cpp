//High precision is unnecessary
#include <iostream>
#include <cstring>
using namespace std;

int map[128];
void strrever(char *s)
{
    for(int i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        char c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}

class High_prec_
{
    
public:
    char num[30];
    High_prec_ operator+ (High_prec_ &b);
   
};

High_prec_ High_prec_::operator+ (High_prec_ &b)
{
    High_prec_ sum;
    int add=0;
    int i;

    
    strrever(num);
    strrever(b.num);
    

    for(i=0;  ;i++)
    {
        int t1,t2;
        if(i>=strlen(num) && i>=strlen(b.num))
        {
            break;
        }

        if(i>=strlen(num))
        {
            t1=0;
        }
        else
        {
            t1=map[num[i]];
        }

        if(i>=strlen(b.num))
        {
            t2=0;
        }
        else
        {
            t2=map[b.num[i]];
        }
        sum.num[i]=(t1+t2+add)%10;

        if(sum.num[i]<=9)sum.num[i]+=48;
        else sum.num[i]+='a'-10;

        add=(t1+t2+add)/10; 
    }
 
    if(add!=0)
    {
        sum.num[i]=add+48;
        i++;
    }
    sum.num[i]='\0';
    strrever(sum.num);
    strrever(num);
    strrever(b.num);
    return sum;
}

void mul(High_prec_ &a,int time)
{
    High_prec_ t;
    t=a;
    for(int i=1;i<time;i++)
    {
        a=a+t;
        //cout<<a.num<<endl;
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    char c,s1[11],s2[11];
    int tag,radix;
    for(int i='0';i<='9';i++)
    {
        map[i]=i-'0';
    }
    for(int i='a';i<='z';i++)
    {
        map[i]=i-'a'+10;
    }

    for(int i=0;;i++)
    {
        cin.get(c);
        if(c==' ')
        {
            s1[i]='\0';
            break;
        }
        s1[i]=c;
    }
    for(int i=0;;i++)
    {
        cin.get(c);
        if(c==' ')
        {
            s2[i]='\0';
            break;
        }
        s2[i]=c;
    } 
    cin>>tag>>radix;

    if(tag==2)
    {
        char t_s[11];
        strcpy(t_s,s1);
        strcpy(s1,s2);
        strcpy(s2,t_s);
    }

    High_prec_ num1,num2,ans,cmp;
    ans.num[0]='0';
    ans.num[1]='\0';

    for(int i=0;i<strlen(s1);i++)
    {
        High_prec_ t;
        t.num[0]=s1[i];
        t.num[1]='\0';
        mul(ans,radix);
        ans=ans+t;
        
    }
    
    bool find_flag=false;
    for(int j=2;j<=36;j++)
    {
        cmp.num[0]='0';
        cmp.num[1]='\0';
        for(int i=0;i<strlen(s2);i++)
        {
            High_prec_ t;
            t.num[0]=s2[i];
            t.num[1]='\0';
            mul(cmp,j);
            cmp=cmp+t;
        }
        if(strcmp(ans.num,cmp.num)==0)
        {
            cout<<j<<endl;
            find_flag=true;
            break;
        }
    }
    if(!find_flag)
        cout<<"Impossible"<<endl;
    
    return 0;
}
