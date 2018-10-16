/* one test point can not be passed */
#include <iostream>
using namespace std;
int sequence[10001];
int N;

typedef struct node{
    int sum;
    int r;
    int l;
} callback;

callback find_ans(int s,int e)
{
    callback left_ans,right_ans,ans;
    
    if(s<e)
    {
        left_ans=find_ans(s,(s+e)/2);
        right_ans=find_ans((s+e)/2+1,e);
    }
    else if(s==e)
    {
        ans.sum=sequence[s];
        ans.r=s;
        ans.l=e;
        return ans;
    }
    int t_sum=0,max=-1;
    int i=(s+e)/2,j=(s+e)/2;
    int a,b;
    while(i>=s||j<e)
    {
        if(i>=s)
        {
            t_sum+=sequence[i];
            if(t_sum>=max)
            {
                a=i;b=j;max=t_sum;
            }
        }
        j++;
        if(j<=e)
        {
            t_sum+=sequence[j];
            if(t_sum>=max)
            {
                a=i;b=j;max=t_sum;
            }
        }
        i--;
    }
    
    t_sum=max;
    if(t_sum>left_ans.sum&&t_sum>=right_ans.sum)
    {
        ans.sum=t_sum;
        ans.l=a;
        ans.r=b;
    }
    else if(right_ans.sum>=t_sum&&right_ans.sum>left_ans.sum)
    {
        ans.sum=right_ans.sum;
        ans.l=right_ans.l;
        ans.r=right_ans.r;
    }
    else 
    {
        ans.sum=left_ans.sum;
        ans.l=left_ans.l;
        ans.r=left_ans.r;
    }
    return ans;
}
int  main(int argc, char const *argv[])
{
    /* code */
    cin>>N;

    for(int i=0;i<N;i++)
    {
        cin>>sequence[i];
        
    }
    
    callback ans;
    ans=find_ans(0,N-1);
    if(ans.sum>=0)
        cout<<ans.sum<<" "<<sequence[ans.l]<<" "<<sequence[ans.r]<<endl;
    else
        cout<<"0"<<" "<<sequence[0]<<" "<<sequence[N-1]<<endl;
    return 0;
}
