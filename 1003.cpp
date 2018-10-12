#include <iostream>
#include <stdint.h>
#include <queue>
using namespace std;
struct road
{
    int origin;
    int destination;
    int length;
    int the_last;
};
struct node
{
    int F,G,H,city;
    friend bool operator < (node a,node b)
    {
        return a.F > b.F;
    } 
};

road Fstar[100000];
int Fstar_city[500];
int city_team_num[500];
int find_path(int origin, int destination,int n_city,int *D);

int main(int argc, char const *argv[])
{
    /* code */
    int N_city,M_road,FROM,TO,road_num=0;
    int min_distance;
    int city_distance[500];
    cin>>N_city>>M_road>>FROM>>TO;
    for(int i=0;i<N_city;i++)
    {
        cin>>city_team_num[i];
    }
    for(int i=0;i<500;i++)
    {
        Fstar_city[i]=-1;
    }
    for(int i=0;i<M_road;i++)
    {
        int t1,t2,t3;
        cin>>t1>>t2>>t3;

        Fstar[road_num].origin=t1;
        Fstar[road_num].destination=t2;
        Fstar[road_num].length=t3;
            
        if(Fstar_city[t1]==-1)
        {
            Fstar_city[t1]=road_num;
            Fstar[road_num].the_last=-1;
        }
        else
        {
            Fstar[road_num].the_last=Fstar_city[t1];
            Fstar_city[t1]=road_num;
        }
        road_num++;

        Fstar[road_num].origin=t2;
        Fstar[road_num].destination=t1;
        Fstar[road_num].length=t3;
            
        if(Fstar_city[t2]==-1)
        {
            Fstar_city[t2]=road_num;
            Fstar[road_num].the_last=-1;
        }
        else
        {
            Fstar[road_num].the_last=Fstar_city[t2];
            Fstar_city[t2]=road_num;
        }
        road_num++;
    }
    min_distance=find_path(TO,FROM,N_city,city_distance);
    return 0;
}

int Astar(int *rev_D,int min_D,int origin,int destination)
{
    priority_queue<node> q;
    node p;
    int team_count=0;
    int D[500],last_city[500];
    bool city_enable[500];
    for(int i=0;i<500;i++)
    {
        D[i]=INT32_MAX;
        last_city[i]=-1;
        city_enable[i]=false;
    }

    city_enable[origin]=true;
    last_city[origin]=-1;
    p.G=0;
    p.city=origin;
    p.H=rev_D[origin];
    D[origin]=0;
    p.F=p.G+p.H;

    q.push(p);

    while(1)
    {
        if(!q.empty())
        {
            node t;
            t=q.pop();
            city_enable[t.city]=false;

            int r;
            r=Fstar_city[t.city];
            while(r!=-1)
            {
                node next_node;
                next_node.G=Fstar[r].length+t.G;
                next_node.H=rev_D[Fstar[r].destination];
                next_node=Fstar[r].destination;
                next_node.F=next_node.H+next_node.G;
                q.push(next_node);
                city_enable[r]=true;
                r=Fstar[r].the_last;
            }
        }
        else
        {
            break;
        }

    }
    return 0;
}

int find_path(int origin, int destination,int n_city,int *D)
{
    bool enable[500];
    int city_count=0;
    
    for(int i=0;i<500;i++)
    {
        enable[i]=false;
        D[i]=INT32_MAX;
    }
    D[origin]=0;
    while(city_count<n_city)
    {
        int min=INT32_MAX,min_i=-1;
        for(int i=0;i<n_city;i++)
        {
            if(enable[i]==false)
            {
                min=D[i]<min ? (min_i=i,D[i]) : min;
            }
        }
        if(min_i!=-1)
        {
            int r;
            r=Fstar_city[min_i];
            while(r!=-1)
            {
                if( ( (Fstar[r].length+D[min_i]) < D[Fstar[r].destination] ) 
                    && (!enable[Fstar[r].destination]))
                {
                    D[Fstar[r].destination]=Fstar[r].length+D[min_i];
                }
                r=Fstar[r].the_last;
            }
            enable[min_i]=true;
            city_count++;
        }
        else
        {
            break;
        }
    }
    return D[destination];
}