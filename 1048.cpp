#include <iostream>
#include <algorithm>
using namespace std;

int coin[100001];
bool cmp(int a,int b)
{
    return a<b;
}
int main()
{
    int N,M;
    bool findFlag=false;
    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        cin>>coin[i];
    }
    sort(coin+1,coin+1+N,cmp);
    int left=1,right=N,mid;
    
    for(int i=1;i<N;i++)
    {
        left=i+1;
        right=N;
        while(1)
        {
            mid=(left+right)/2;
            if(coin[i]+coin[mid]==M)
            {
                findFlag=true;
                cout<<coin[i]<<" "<<coin[mid]<<endl;
                return 0;
            }
            else if(coin[i]+coin[mid]<M)
            {
                if(mid==left)break;
                left=mid+1;
            }
            else if(coin[i]+coin[mid]>M)
            {
                if(mid==left)break;
                right=mid-1;
            }
        }
    }
    if(!findFlag)cout<<"No Solution"<<endl;
    return 0;
}