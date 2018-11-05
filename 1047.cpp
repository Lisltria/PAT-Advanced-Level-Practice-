#include <iostream>
#include <cstdio>
#include <vector>

#include <algorithm>
using namespace std;

int N,K;
vector<int> course[2501];

bool cmp(int a,int b)
{
    return a<b;
}
int main()
{
    cin>>N>>K;
    for(int i=1;i<=N;i++)
    {
        char s[5];
        int Ni,t1,t;
        cin>>s;
        t=s[0]*1000000+s[1]*10000+s[2]*100+s[3];
        cin>>Ni;
        for(int j=1;j<=Ni;j++)
        {
            scanf("%d",&t1);
            course[t1].push_back(t);
        }
    }
    char s[5];
    s[4]='\0';
    for(int i=1;i<=K;i++)
    {
        cout<<i<<" "<<course[i].size()<<endl;
        sort(course[i].begin(),course[i].end(),cmp);
        for(auto iter=course[i].begin();iter!=course[i].end();iter++)
        {
            int t;
            t=*iter;
            s[0]=t/1000000;
            s[1]=(t/10000)%100;
            s[2]=(t/100)%100;
            s[3]=t%100;
            printf("%s\n",s);
        }
    }

    return 0;
}