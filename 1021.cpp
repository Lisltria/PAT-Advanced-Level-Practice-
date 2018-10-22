#include <iostream>
using namespace std;

typedef struct node{
    int from,to;
    int last;
}nodes;
nodes edge[20001];
int edge_point[20001];
bool nodes_enable[10001];
int component_count=1;

int start_point[10001];
int start_point_count=0;
int max_level=0;

bool ans[10001];

void search(int n,int level){
    if(!nodes_enable[n]){
        int c;
        int end_flag=false;
        nodes_enable[n]=true;
        c=edge_point[n];
        while(c!=-1)
        {
            if(!nodes_enable[edge[c].to])
            {
                search(edge[c].to,level+1);
                end_flag=true;
            }
            c=edge[c].last;
        }
        if(end_flag==false)
        {
            if(level>max_level)
            {
                max_level=level;
                start_point_count=0;
                start_point[start_point_count]=n;
            }
            else if(level==max_level)
            {
                start_point_count++;
                start_point[start_point_count]=n;
            }
        }
    }
    else{

    }
}
int main(int argc, char const *argv[]){
    
    /* code */
    int N,count=0;
    cin>>N;
    for(int i=0;i<=N;i++){
        edge_point[i]=-1;
    }

    for(int i=1;i<N;i++){
        int t1,t2;
        cin>>t1>>t2;
        edge[count].from=t1;
        edge[count].to=t2;
        edge[count].last=edge_point[edge[count].from];
        edge_point[edge[count].from]=count;
        count++;
        edge[count].from=t2;
        edge[count].to=t1;
        edge[count].last=edge_point[edge[count].from];
        edge_point[edge[count].from]=count;
        count++;
    }


    search(1,1);
    for(int i=1;i<=N;i++)
    {
        if(!nodes_enable[i])
        {
            search(i,1);
            component_count++;
        }
    }
    if(component_count>1)
    {
        cout<<"Error: "<<component_count<<" components"<<endl;
    }
    else
    {
        for(int i=0;i<=start_point_count;i++)
        {
            ans[start_point[i]]=true;
        }
        for(int i=1;i<=N;i++)
        {
            nodes_enable[i]=false;
        }
        max_level=0;
        start_point_count=0;
        search(start_point[0],1);
        
        for(int i=0;i<=start_point_count;i++)
        {
            ans[start_point[i]]=true;
        }
        for(int i=1;i<=N;i++)
        {
            if(ans[i])cout<<i<<endl;
        }
    }
    return 0;
}
