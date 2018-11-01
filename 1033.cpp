#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdint>
using namespace std;

int tank,dist,avg,N;
struct node{
    double price;
    int distance;
}gas_station[502];
bool cmp(struct node a, struct node b)
{
    return a.distance<b.distance;
}
int main()
{
    double ans=0.0;
    int max_endurance;
    cin>>tank>>dist>>avg>>N;
    for(int i=0;i<N;i++)
    {
        cin>>gas_station[i].price>>gas_station[i].distance;
    }
    gas_station[N].price=0.0;
    gas_station[N].distance=dist;
    sort(gas_station,gas_station+N+1,cmp);
    if(gas_station[0].distance>0)
    {
        cout<<"The maximum travel distance = 0.00"<<endl;
        return 0;
    }
    max_endurance=tank*avg;
    double min_price=gas_station[0].price;
    int min_from=gas_station[0].distance;
    double total_price=0.0;
    for(int i=1;i<=N;i++)
    {
        if(gas_station[i].distance<=min_from+max_endurance)
        {
            if(gas_station[i].price<=min_price)
            {
                total_price+=(gas_station[i].distance-min_from)*min_price/avg;
                min_from=gas_station[i].distance;
                min_price=gas_station[i].price;
            }
        }
        else
        {
            int min_j=-1;
            double min_p=1.0*INT32_MAX;
            for(int j=i-1;j>=0;j--)
            {
                if(gas_station[i].distance-max_endurance<=gas_station[j].distance)
                {
                    if(gas_station[j].price<=min_p)
                    {
                        min_p=gas_station[j].price;
                        min_j=j;
                    }
                }
                else 
                {
                    break;
                }
            }
            if(min_j==-1)
            {
                cout<<"The maximum travel distance = ";
                total_price+=max_endurance*min_price/avg;
                printf("%.2f\n",1.0*(gas_station[i-1].distance+max_endurance));
                return 0;
            }
            else{
                total_price+=(gas_station[min_j].distance-min_from)*min_price/avg;
                total_price-=(min_from+max_endurance-gas_station[min_j].distance)*(gas_station[min_j].price-min_price)/avg;
                min_from=gas_station[min_j].distance;
                min_price=gas_station[min_j].price;
            }
            if(gas_station[i].price<=min_price)
            {
                total_price+=(gas_station[i].distance-min_from)*min_price/avg;
                min_from=gas_station[i].distance;
                min_price=gas_station[i].price;
            }
        }
    }
    printf("%.2f\n",total_price);
    return 0;
}