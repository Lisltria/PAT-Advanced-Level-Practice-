#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
    double total;
    double price;
    double p_price;
}moon[1001];
bool cmp(struct node a,struct node b)
{
    return a.p_price>b.p_price;
}
int main(int argc, char const *argv[])
{
    /* code */
    int N,pack;
    cin>>N>>pack;
    for(int i=0;i<N;i++)
    {
        cin>>moon[i].total;
    }
    for(int i=0;i<N;i++)
    {
        cin>>moon[i].price;
        moon[i].p_price=100.0*moon[i].price/moon[i].total;
        
    }
    sort(moon,moon+N,cmp);
    int count=0;
    double ans=0.0;
    for(int i=0;i<N;i++)
    {
        if(count>=pack)break;
        if( moon[i].total>=(pack-count) )
        {
            ans+= (pack-count)*moon[i].p_price;
            count=pack;
        }
        else
        {
            count+=moon[i].total;
            ans+=moon[i].price*100;
        }
        if(count>=pack)break;
    }
    printf("%.2lf\n",ans/100);
    return 0;
}
