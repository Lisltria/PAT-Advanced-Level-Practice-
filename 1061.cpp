#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

string week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
string hour[70]={"00","01","02","03","04","05","06","07","08","09",
                 "10","11","12","13","14","15","16","10","11","12",
                 "13","14","15","16","17","18","19","20","21","22",
                 "23","24"
                };
int main(int argc, char const *argv[])
{
    /* code */
    int i,W=-1,H=-1,M=-1,t;
    char s1[100],s2[100],s3[100],s4[100];
    cin>>s1>>s2>>s3>>s4;
    for(i=0;i<strlen(s1)&&i<strlen(s2);i++)
    {
        if(s1[i]==s2[i]&&s1[i]>='A'&&s1[i]<='G')
        {
            W=s1[i]-'A';
            break;
        }
    }
    t=i+1;
    for(i=t;i<strlen(s1)&&i<strlen(s2);i++)
    {
        if(s1[i]==s2[i]
            &&( (s1[i]>='A'&&s1[i]<='N')||(s1[i]>='0'&&s1[i]<='9') ) 
            )
        {
            H=s1[i]-48;
            break;
        } 
    }
    for(i=0;i<strlen(s3)&&i<strlen(s4);i++)
    {
        if(s3[i]==s4[i]
            &&( (s3[i]>='a'&&s3[i]<='z')||(s3[i]>='A'&&s3[i]<='Z') )
            )
        {
            M=i;
            break;
        } 
    }
    cout<<week[W]<<" "<<hour[H]<<":";
    printf("%02d\n",M);
    return 0;
}
