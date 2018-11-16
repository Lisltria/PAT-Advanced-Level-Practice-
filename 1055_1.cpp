#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N,K;
typedef struct node
{
    char name[20];
    int age;
    int worth;
}person;
vector<person>Forbes[202];

bool cmp(person a,person b)
{
    if(a.worth==b.worth)
    {
        if(a.age==b.age)
        {
            return strcmp(a.name,b.name)<0 ? true:false;
        }
        return a.age<b.age;
    }
    else
    {
        return a.worth>b.worth;
    }
}
int main()
{
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        person t;
        scanf("%s %d %d",t.name,&t.age,&t.worth);
        Forbes[t.age].push_back(t);
    }
    
    for(int i=0;i<K;i++)
    {
        int num,Amin,Amax;
        cout<<"Case #"<<i+1<<":"<<endl;
        
        vector<person>list;
        cin>>num>>Amin>>Amax;
        for(int j=Amin;j<=Amax;j++)
        {
            for(auto iter=Forbes[j].begin();iter!=Forbes[j].end();iter++)
            {
                person t=(*iter);
                list.push_back(t);
            }
        }
        if(list.empty())
        {
            cout<<"None"<<endl;
        }
        else
        {
            int count=0;
            sort(list.begin(),list.end(),cmp);
            for(auto iter=list.begin();iter!=list.end();iter++)
            {
                count++;
                cout<<(*iter).name<<" "<<(*iter).age<<" "<<(*iter).worth<<endl;
                if(count==num)break;
            }
        }
    }
    return 0;
}