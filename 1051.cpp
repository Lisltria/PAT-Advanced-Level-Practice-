#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

stack<int>seq;
int main(int argc, char const *argv[])
{
    /* code */
    int M,N,K;
    cin>>M>>N>>K;
    for(int i=1;i<=K;i++)
    {
        int k=1;
        bool flag=true;
        while(!seq.empty())seq.pop();
        for(int j=1;j<=N;j++)
        {
            int t;
            scanf("%d",&t);
            if(!flag)continue;

            if((seq.empty()||seq.top()<t) && t>=k)
            {
                while(k<=t)
                {
                    seq.push(k);
                    k++;
                }
                if(seq.size()>M)
                {
                    flag=false;
                }
                seq.pop();
            }
            else if(!seq.empty()&&seq.top()==t)
            {
                seq.pop();
            }
            else flag=false;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
