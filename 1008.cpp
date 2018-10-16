#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int N,ans=0,e=0;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int t;
        cin>>t;
        ans += t > e ? (t-e)*6 : (e-t)*4;
        e=t;
        ans += 5;
    }
    cout<<ans<<endl;
    return 0;
}
