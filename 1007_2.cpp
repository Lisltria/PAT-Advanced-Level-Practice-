#include <iostream>
using namespace std;

int main(void)
{
    int K;
    int sum=0;
    int max=-1;
    int left=-1,right=-1,_left;
    int first,end;
    
    bool flag,zero_flag;
    cin>>K;

    flag=false;
    zero_flag=true;
    for(int i=0;i<K;i++)
    {
        int t;
        cin>>t;
        sum+=t;
        if(t!=0)zero_flag=false;
        if(i==0)first=t;
        if(i==K-1)end=t;
        
        if(sum<0)
        {
            flag=false;
            sum=0;
            continue;
        }
        else{
            if(sum>=0&&flag==false)
            {
                flag=true;
                _left=t;
            }
        }

        if(sum>max)
        {
            left=_left;
            right=t;
            max=sum;
        }
    }

    if(left==-1&&right==-1)
    {
        left=first;
        right=end;
        max=0;
    }
    if(zero_flag)
        cout<<0<<" "<<first<<" "<<end<<endl;
    else
        cout<<max<<" "<<left<<" "<<right<<endl;
    return 0;
}