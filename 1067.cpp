#include <iostream>
#include <cstdio>
using namespace std;

int list[100001];
int count=0;
void swap(int &a,int &b)
{
    a^=b^=a^=b;
}
void send()
{
    while(list[0]!=0)
    {
        swap(list[0],list[list[0]]);
        count++;
    }
}
int main(int argc, char const *argv[])
{
    int N;
    
    cin>>N;
    for(int i=0;i<N;i++)
    {
        scanf("%d",list+i);
    }
    send();
    for(int i=1;i<N;i++)
    {
        if(list[i]!=i)
        {
            swap(list[0],list[i]);
            count++;
            send();
        }
    }
    cout<<count<<endl;
    return 0;
}
