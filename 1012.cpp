#include <iostream>
using namespace std;

#define g_C rank_C
#define g_M rank_M
#define g_E rank_E
#define g_A rank_A

typedef struct node{
    int rank_C;
    int rank_M;
    int rank_E;
    int rank_A;
    int ID;
    bool enable;
}nodes;
nodes results[1000000];
nodes sort_list[1000000];

int signal(int v)
{
    if(v>0)return 1;
    if(v<0)return -1;
    else return 0;
}


int compare(nodes n1,nodes n2,int types)
{
    switch(types)
    {
        case 1 :
                    return signal(n1.g_A-n2.g_A);
                break;
        case 2 :
                    return signal(n1.g_C-n2.g_C); 
                break;
        case 3 :
                    return signal(n1.g_M-n2.g_M);
                break;
        case 4 :
                    return signal(n1.g_E-n2.g_E);
                break;        
    }
    return 0;
}

void sort(nodes list[],int l,int r,int types)
{
    int i,j;
    nodes x;
    nodes t;
    if(l>=r)return ;
    x=list[r];

    
    j=l-1;
    for(i=l;i<r;i++)
    {
        if(compare(list[i],x,types)>=0)
        {
            j++;
            
            t=list[i];
            list[i]=list[j];
            list[j]=t;
           
        }
    }
    t=list[r];
    list[r]=list[j+1];
    list[j+1]=t;
   

    sort(list,l,j,types);
    sort(list,j+2,r,types);
}

int main(int argc, char const *argv[])
{
    /* code */
    int N,M;
    cin>>N>>M;
    for(int i=0;i<1000000;i++)
    {
        results[i].enable=false;
    }
    for(int i=0;i<N;i++)
    {
        int t_ID,t_C,t_M,t_E;
        cin>>t_ID>>t_C>>t_M>>t_E;
        sort_list[i].ID=t_ID;
        sort_list[i].g_C=t_C;
        sort_list[i].g_M=t_M;
        sort_list[i].g_E=t_E;
        sort_list[i].g_A=1.0*(t_C+t_M+t_E)/3.0+0.5;
    }

    sort(sort_list,0,N-1,1);
    long count=1;

    for(int i=0;i<N;i++)
    {
        if(i!=0&&sort_list[i-1].g_A>sort_list[i].g_A)
        {
            count=i+1;
        }
        results[sort_list[i].ID].rank_A=count;
        results[sort_list[i].ID].enable=true;
    }
    
    sort(sort_list,0,N-1,2);
    count=1;
    for(int i=0;i<N;i++)
    {
        if(i!=0&&sort_list[i-1].g_C>sort_list[i].g_C)
        {
            count=i+1;
        }
        results[sort_list[i].ID].rank_C=count;
    }
    sort(sort_list,0,N-1,3);
    count=1;
    for(int i=0;i<N;i++)
    {
        if(i!=0&&sort_list[i-1].g_M>sort_list[i].g_M)
        {
            count=i+1;
        }
        results[sort_list[i].ID].rank_M=count;
    }
    sort(sort_list,0,N-1,4);
    count=1;
    for(int i=0;i<N;i++)
    {
        if(i!=0&&sort_list[i-1].g_E>sort_list[i].g_E)
        {
            count=i+1;
        }
        results[sort_list[i].ID].rank_E=count;
    }

    for(int i=0;i<M;i++)
    {
        int t_ID;
        cin>>t_ID;
        if(results[t_ID].enable==false)
        {
            cout<<"N/A"<<endl;
            continue;
        }
        if(  results[t_ID].rank_A <= results[t_ID].rank_C
           &&results[t_ID].rank_A <= results[t_ID].rank_M
           &&results[t_ID].rank_A <= results[t_ID].rank_E
           )
           {
               cout<< results[t_ID].rank_A << " A" << endl;
           }
        else if(  results[t_ID].rank_C <  results[t_ID].rank_A
           &&results[t_ID].rank_C <= results[t_ID].rank_M
           &&results[t_ID].rank_C <= results[t_ID].rank_E
           )
           {
               cout<< results[t_ID].rank_C << " C" << endl;
           }
        else if(  results[t_ID].rank_M <  results[t_ID].rank_A
           &&results[t_ID].rank_M <  results[t_ID].rank_C
           &&results[t_ID].rank_M <= results[t_ID].rank_E
           )
           {
               cout<< results[t_ID].rank_M << " M" << endl;
           }
        else if(  results[t_ID].rank_E<results[t_ID].rank_A
           &&results[t_ID].rank_E<results[t_ID].rank_C
           &&results[t_ID].rank_E<results[t_ID].rank_M
           )
           {
               cout<< results[t_ID].rank_E << " E" << endl;
           }
    }

    return 0;
}
