#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}
int aC[100001],aP[100001];
int main()
{
    int Nc,Np;
    long ans=0;
    scanf("%d",&Nc);
    for(int i=0;i<Nc;i++)
    {
        scanf("%d",aC+i);
    }
    scanf("%d",&Np);
    for(int i=0;i<Np;i++)
    {
        scanf("%d",aP+i);
    }
    sort(aC,aC+Nc,cmp);
    sort(aP,aP+Np,cmp);

    int iter_c=0,iter_p=0;
    while(iter_c<Nc&&iter_p<Np)
    {
        if(aC[iter_c]*aP[iter_p]>0&&aP[iter_p]>0&&aC[iter_c]>0)
        {
            ans+=aC[iter_c]*aP[iter_p];
            iter_c++;
            iter_p++;
        }
        else
        {
            break;
        }
    }
    iter_c=0;iter_p=0;
    while(iter_c<Nc&&iter_p<Np)
    {
        if(aC[Nc-iter_c-1]*aP[Np-iter_p-1]>0&&aP[Np-iter_p-1]<0&&aC[Nc-iter_c-1]<0)
        {
            ans+=aC[Nc-iter_c-1]*aP[Np-iter_p-1];
            iter_c++;
            iter_p++;
        }
        else
        {
            break;
        }
    }
    cout<<ans<<endl;
    return 0;

}