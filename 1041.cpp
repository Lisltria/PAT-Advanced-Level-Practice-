#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int _hash[100001];
int N;
vector<int> list;

int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int t;
        scanf("%d",&t);
        list.push_back(t);
        _hash[t]++;
    }
    bool flag=false;
    for(vector<int>::iterator iter = list.begin();iter!=list.end();iter++)
    {
        int t;
        t=*iter;
        if(_hash[t]==1)
        {
            flag=true;
            cout<<t<<endl;
            break;
        }
    }
    if(!flag)
    {
        cout<<"None"<<endl;
    }
    return 0;

}