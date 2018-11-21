#include <iostream>
#include <cstdio>
#include <cstdint>
using namespace std;

char numA[20],numB[20],numC[20];

int main(int argc, char const *argv[])
{
    /* code */
    int N;
    long long A,B,C;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>A>>B>>C;
        if(A>0&&B>0)
        {
            if(INT64_MAX-A<=B )
            {
                B=B-(INT64_MAX-A);
                A=INT64_MAX;
                if(A==C&&B>0)
                {
                    cout<<"Case #"<<i+1<<": true"<<endl;
                }
                else if(A==C&&B==0)
                {
                    cout<<"Case #"<<i+1<<": false"<<endl;
                }
                else if(A>C)
                {
                    cout<<"Case #"<<i+1<<": true"<<endl;
                }
            }
            else
            {
                A=A+B;
                if(A>C)
                {
                    cout<<"Case #"<<i+1<<": true"<<endl;
                }
                else
                {
                    cout<<"Case #"<<i+1<<": false"<<endl;
                }
            }
        }
        else if(A<0&&B<0)
        {
            if(INT64_MIN-A>=B)
            {
                B=B-(INT64_MIN-A);
                A=INT64_MIN;
                if(A==C&&B<0)
                {
                    cout<<"Case #"<<i+1<<": false"<<endl;
                }
                else if(A==C&&B==0)
                {
                    cout<<"Case #"<<i+1<<": false"<<endl;
                }
                else if(A<C)
                {
                    cout<<"Case #"<<i+1<<": false"<<endl;
                }
            }
            else
            {
                A=A+B;
                if(A>C)
                {
                    cout<<"Case #"<<i+1<<": true"<<endl;
                }
                else
                {
                    cout<<"Case #"<<i+1<<": false"<<endl;
                }
            }
        }
        else
        {
             A=A+B;
            if(A>C)
            {
                cout<<"Case #"<<i+1<<": true"<<endl;
            }
            else
            {
                cout<<"Case #"<<i+1<<": false"<<endl;
            }
        }
    }
    return 0;
}
