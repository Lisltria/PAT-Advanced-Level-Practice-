#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

stack<int> ss;
int treeArr[100005];
int lowbit(int x)
{
    return x&(-x);
}

void update(int p,int num)
{
    int n=p;
    while(n<100005)
    {
        treeArr[n]+=num;
        n+=lowbit(n);
    }
}

int getsum(int p)
{
    int n=p,sum=0;
    while(n>0)
    {
        sum+=treeArr[n];
        n-=lowbit(n);
    }
    return sum;
}

int main()
{
    int Noperate;
    cin>>Noperate;
    for(int i=1;i<=Noperate;i++)
    {
        char s_T[15];
        scanf("%s",s_T);
        if(strcmp(s_T,"Pop")==0)
        {
            if(ss.empty())
            {
                printf("Invalid\n");
            }
            else
            {
                printf("%d\n",ss.top());
                update(ss.top(),-1);
                ss.pop();
            }
        }
        else if(strcmp(s_T,"PeekMedian")==0)
        {
            if(ss.empty())
            {
                printf("Invalid\n");
                
            }
            else
            {
                int left_t=0,right_t=100005;
                int mid_t;
                while(left_t<=right_t)
                {
                    mid_t=left_t+(right_t-left_t)/2;
                    int sum=getsum(mid_t);
                    if(sum>(ss.size()+1)/2)
                    {
                        right_t=mid_t-1;
                    }
                    else if(sum<(ss.size()+1)/2)
                    {
                        left_t=mid_t+1;
                    }
                    else
                    {
                        right_t=mid_t-1;
                    }
                }
                cout<<left_t<<endl;
            }
        }
        else if(strcmp(s_T,"Push")==0)
        {
            int t;
            cin>>t;
            ss.push(t);
            update(t,1);
        }
    }
    return 0;
}