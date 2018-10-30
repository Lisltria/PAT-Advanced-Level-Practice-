#include <iostream>
#include <cstdio>
#include <cstdint>
using namespace std;

int N,M,S,D;
struct node{
    int length;
    int last_city;
    int dis;
    int to;
}adjacency_list[20000];
int road_count=0;
int city[500];
int dist_rev[500];
int min_road;

int dijkstra(int D[],int from,int to)
{
    bool city_enable[500]={false};
    int city_count=0,closet_city;
    
    closet_city=from;
    for(int i=0;i<N;i++)
    {
        D[i]=INT32_MAX;
    }
    D[from]=0;
    city_enable[from]=true;
    city_count++;
    while(city_count<N)
    {
        int t=city[closet_city];
        while(t>0)
        {
            if(  city_enable[adjacency_list[t].to]==false
               &&adjacency_list[t].dis+D[closet_city]<D[adjacency_list[t].to]
               )
               {
                   D[adjacency_list[t].to]=adjacency_list[t].dis+D[closet_city];
                   
               }
            t=adjacency_list[t].last_city;
        }
        int min_t=INT32_MAX,min_i=-1;
        for(int i=0;i<N;i++)
        {
            if(city_enable[i]==false)
            {
                if(D[i]<min_t)
                {
                    min_t=D[i];
                    min_i=i;
                }
            }   
        }
        if(min_i!=-1)
        {
            closet_city=min_i;
            city_enable[closet_city];
            city_count++;
        }
        else{
            break;
        }
    }
    return D[to];
}
int ans_path[50000],path_length;
int ans_path_f[50000],path_length_f;
int ans_lenght,ans_cost=INT32_MAX;
void path_find(int level,int cost,int has_cost,int local,int dest)
{
    if(has_cost+dist_rev[local]>min_road)
    {
        return ;
    }
    if(local==dest)
    {  
        if(cost<ans_cost)
        {
            ans_cost=cost;
            ans_lenght=has_cost;
            path_length_f=level;
            for(int i=0;i<path_length_f;i++)
            {
                ans_path_f[i]=ans_path[i];
            }
        }
        return ;
    }
    int t;
    t=city[local];
    while(t>0)
    {
        if(has_cost+adjacency_list[t].dis+dist_rev[adjacency_list[t].to]<=min_road)
        {
            ans_path[level]=adjacency_list[t].to;
            path_find(level+1,
                    cost+adjacency_list[t].length,
                    has_cost+adjacency_list[t].dis,
                    adjacency_list[t].to,
                    dest);
        }
        t=adjacency_list[t].last_city;
    }
}

int main()
{
    scanf("%d %d %d %d",&N,&M,&S,&D);
    for(int i=0;i<N;i++)
    {
        city[i]=-1;
    }
    for(int i=0;i<M;i++)
    {
        int city1,city2,dist,cost;
        scanf("%d %d %d %d",&city1,&city2,&dist,&cost);

        adjacency_list[road_count].last_city=city[city1];
        adjacency_list[road_count].length=cost;
        adjacency_list[road_count].dis=dist;
        adjacency_list[road_count].to=city2;
        city[city1]=road_count;
        road_count++;

        adjacency_list[road_count].last_city=city[city2];
        adjacency_list[road_count].length=cost;
        adjacency_list[road_count].dis=dist;
        adjacency_list[road_count].to=city1;
        city[city2]=road_count;
        road_count++;
    }

    
    min_road=dijkstra(dist_rev,D,S);
    //cout<<min_road;
    ans_path[0]=S;
    path_find(1,0,0,S,D);
    for(int i=0;i<path_length_f;i++)
    {
        cout<<ans_path_f[i]<<" ";
    }
    cout<<ans_lenght<<" "<<ans_cost<<endl;
    return 0;

}
