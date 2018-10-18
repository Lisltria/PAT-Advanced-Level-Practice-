#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//test
struct node{
    double coe;
};
node poly[3001];

struct node2
{
    double coe;
    int exp;
}p1[11];


int main(int argc, char const *argv[])
{
    /* code */
    for(int i=0;i<=3000;i++)
    {
        poly[i].coe=0.0;
    }
    int N1,N2;
    cin>>N1;
    for(int i=1;i<=N1;i++)
    {
        int exp;
        double coe;
        cin>>exp>>coe;
        p1[i].coe=coe;
        p1[i].exp=exp;
    }
    cin>>N2;
    for(int i=1;i<=N2;i++)
    {
        int exp;
        double coe;
        cin>>exp>>coe;
        for(int j=1;j<=N1;j++)
        {
            poly[exp+p1[j].exp].coe+=coe*p1[j].coe;
        }
        
    }


    bool flag=false;
    int count=0;
    for(int i=3000;i>=0;i--)
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
    for(int i=3000;i>=0;i--)
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


