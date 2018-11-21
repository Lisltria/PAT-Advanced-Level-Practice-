#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

bool _hash[11001]={false};
int _hashnum[11001];
bool isPrime(int num)
{
    bool flag=true;
    if(num==2)return true;
    if(num==1)return false;
    if(num<=0)return false;
    for(int i=2;i<=sqrt(num)+1;i++)
    {
        if(num%i==0)
        {
            flag=false;
            break;
        }
    }
    return flag;
}
int main()
{
    int M,N;
    int reM;
    cin>>M>>N;

    for(int i=M;;i++)
    {
        if(isPrime(i))
        {
            reM=i;break;
        }
    }
    for(int i=0;i<N;i++)
    {
        if(i!=0)cout<<" ";
        int t,index;
        bool flag=false;
        cin>>t;
        index=t%reM;
        for(int k=0;k<reM;k++)
        {
            if(!_hash[(index+k*k)%reM])
            {
                _hash[(index+k*k)%reM]=true;
                cout<<(index+k*k)%reM;
                flag=true;
                break;
            }
        }

        if(!flag)cout<<"-";
    }
    cout<<endl;
    return 0;
}