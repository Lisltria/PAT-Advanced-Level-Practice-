#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
typedef struct 
{
    int left;
    int right;
}nodes;
nodes ans[100001];
int ans_count=0;
int storge[100001];
int min_ans=INT_MAX;
int main()
{
    int N;
    int cost;
    int sum=0;
    int left_point=1,right_point=1;
    cin>>N>>cost;
    for(int i=1;i<=N;i++)
    {
        scanf("%d",storge+i);
    }
    sum=storge[1];
    while(right_point<=N)
    {
        if(sum<cost)
        {
            right_point++;
            sum+=storge[right_point];
        }
        else{
            if(sum<min_ans)
            {
                min_ans=sum;
                ans_count=0;
                ans[ans_count].left=left_point;
                ans[ans_count].right=right_point;
                ans_count++;
                sum-=storge[left_point];
                left_point++;
                
            }
            if(sum==min_ans)
            {
                ans[ans_count].left=left_point;
                ans[ans_count].right=right_point;
                ans_count++;
                sum-=storge[left_point];
                left_point++;
                right_point++;
                sum+=storge[right_point];
            }
            if(sum>min_ans)
            {
                sum-=storge[left_point];
                left_point++;
            }
        }
    }
    for(int i=0;i<ans_count;i++)
    {
        cout<<ans[i].left<<"-"<<ans[i].right<<endl;
    }
    return 0;
}