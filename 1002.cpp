#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//test
struct node{
    double coe;
};

node poly[1001];

int main(int argc, char const *argv[])
{
    /* code */
    for(int i=0;i<=1000;i++)
    {
        poly[i].coe=0.0;
    }
    for(int j=1;j<=2;j++)
    {
        int N;
        cin>>N;
        for(int i=1;i<=N;i++)
        {
            int exp;
            double coe;
            cin>>exp>>coe;
            poly[exp].coe+=coe;
        }
    }

    bool flag=false;
    int count=0;
    for(int i=1000;i>=0;i--)
    {
        if(fabs(poly[i].coe)<0.0001)
        {
            continue;
        }
        else
        {
            count++;
        }
    }
    cout<<count;
    for(int i=1000;i>=0;i--)
    {
        if(fabs(poly[i].coe)<0.0001)
        {
            continue;
        }
        else
        {
            cout<<" "<<i<<" "
                <<setiosflags(ios::fixed)<<setprecision(1)
                <<poly[i].coe;
        }
    }
    cout<<endl;
    return 0;
}


