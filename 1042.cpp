#include <iostream>
using namespace std;
int map[55];
int ans[55];
int main(int argc, char const *argv[])
{
    /* code */
    int N;
    cin>>N;
    for(int i=1;i<=54;i++)
    {
        cin>>map[i];
    }
    for(int i=1;i<=54;i++)
    {
        int t=i;
        for(int j=0;j<N;j++)
        {
            t=map[t];
        }
        ans[t]=i;
    }
    for(int i=1;i<=54;i++)
    {
        if(ans[i]>52)
        {
            switch (ans[i])
            {
                case 53:cout<<"J1";break;
                case 54:cout<<"J2";break;
            }
        }
        else
        {
            switch((ans[i]-1)/13)
            {
                case 0:cout<<"S"<<(ans[i]%13==0 ? 13:ans[i]%13);break;
                case 1:cout<<"H"<<(ans[i]%13==0 ? 13:ans[i]%13);break;
                case 2:cout<<"C"<<(ans[i]%13==0 ? 13:ans[i]%13);break;
                case 3:cout<<"D"<<(ans[i]%13==0 ? 13:ans[i]%13);break;
            }
        }
        if(i<=53)cout<<" ";
        else cout<<endl;
    }
    return 0;
}
