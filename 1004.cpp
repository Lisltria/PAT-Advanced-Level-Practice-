#include <iostream>
using namespace std;

struct node{
    int last;
    int child;
};
node tree[201];
int pedigree_tree[101];
void BFS();
int  main(int argc, char const *argv[])
{
    /* code */
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int N,M;
    int count=0;
    
    cin>>N>>M;
    if(N==0)
    {
        fclose(stdin);
        fclose(stdout);
        return 0;    
    }
    for(int i=1;i<=100;i++)
    {
        pedigree_tree[i]=-1;
    }
    for(int i=1;i<=M;i++)
    {
        int from,k,to;
        
        cin>>from>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>to;
            tree[count].child=to;
            tree[count].last=pedigree_tree[from];
            pedigree_tree[from]=count;
            count++;
        }
    }
    BFS();
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}

void BFS()
{
    int ans[101];
    struct  queue{
        int num;
        int level;
    }q[502];
    int head=0,rear=0;

    for(int i=0;i<101;i++)
    {
        ans[i]=-1;
    }
    ans[1]=1;
    q[head].level=1;
    q[head].num=01;
    rear++;
    while(head<rear)
    {
        queue t,p;
        t=q[head];
        head++;

        bool flag=false;
        int r;
        flag=false;
        r=pedigree_tree[t.num];
        while(r!=-1)
        {
            flag=true;
            p.num=tree[r].child;
            p.level=t.level+1;
            q[rear]=p;
            rear++;
            if(ans[p.level]==-1)
            {
                ans[p.level]=1;
            }
            else{
                ans[p.level]++;
            }
            r=tree[r].last;
        }
        if(flag)
        {
            ans[t.level]--;
        }
    }
    cout<<ans[1];
    for(int i=2;i<=100;i++)
    {
        if(ans[i]!=-1)
        {
            cout<<" "<<ans[i];
        }
    }
    cout<<endl;
}