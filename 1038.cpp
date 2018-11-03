#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct node{
    char s[10];
}num;
num list[10001];

bool cmp(num a,num b)
{
   
    {
        char t_s1[30],t_s2[30];
        strcpy(t_s1,a.s);
        strcat(t_s1,b.s);
        strcpy(t_s2,b.s);
        strcat(t_s2,a.s);
        return strcmp(t_s1,t_s2)<0 ? true:false; 

    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>list[i].s;
    }
    sort(list,list+N,cmp);
    bool f=false;
    int j;
    for(j=0;j<N;j++)
    {
        for(int i=0;i<strlen(list[j].s);i++)
        {
            if(!f)
            {
                if(list[j].s[i]!='0')
                {
                    f=true;
                    cout<<list[j].s[i];
                }
                else
                    continue;
            }
            else
            {
                cout<<list[j].s[i];
            }
        }
        if(f)break;
    }
    if(!f&&N==j)
    {
        cout<<"0";
    }
    for(int i=j+1;i<N;i++)
    {
        cout<<list[i].s;
    } 
    cout<<endl;

    return 0;
}
