#include <iostream>
#include <cstdio>
using namespace std;
//本题可以用map和stack来做，复习时要练习
int start_position1,start_position2,N;
struct node{
    char data;
    int next;
}memory[100001];

bool read[100001];
int main(int argc, char const *argv[])
{
    /* code */

    cin>>start_position1>>start_position2>>N;
    for(int i=0;i<N;i++)
    {
        int p1;
        cin>>p1;
        cin>>memory[p1].data;
        cin>>memory[p1].next;
    }
    int t=start_position1;
    while(t!=-1)
    {
        read[t]=true;
        t=memory[t].next;
    }
    t=start_position2;
    while(t!=-1)
    {
        if(read[t])
        {
            printf("%05d\n",t);
            return 0;
            break;
        }
        t=memory[t].next;
    }
    cout<<"-1"<<endl;
    return 0;
}
