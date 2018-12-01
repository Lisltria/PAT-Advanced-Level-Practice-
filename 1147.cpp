#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int N, M;
bool cmp_min(int a,int b)
{
    return a < b ? true : false;
}
bool cmp_max(int a,int b)
{
    return a > b ? true : false;
}

int isHeep(int h[],int root,bool (*f)(int ,int))
{
    int statusL, statusR;
    if(root*2>M&&root*2+1>M)
        return 0;
    if(root*2<=M&&f(h[root],h[root*2]))
    {
        statusL = isHeep(h, root * 2, f);
    }else
    {
        statusL = -1;
    }


    if(root*2>M)
    {
        statusL = 0;
    }
    

    if((root*2+1)<=M&&f(h[root],h[root*2+1]))
    {
        statusR = isHeep(h, root * 2+1, f);
    }
    else
    {
        statusR = -1;
    }
    if((root*2+1)>M)
    {
        statusR = 0;
    }
    
    if(statusR==0&&statusL==0)
    {
         
        return 0;
    }
    else
    {

        return -1;
    }
}
bool flag = true;
void postOrder(int h[],int root)
{
    
    if(root*2<=M)
    {
        postOrder(h, root * 2);
    }
    if(root*2+1<=M)
    {
        postOrder(h, root * 2 + 1);
    }

    if(flag)
    {
        cout << h[root];
        flag = false;
    }
    else
    {
        cout << " " << h[root];
    }
}


int main()
{
    
    cin >> N >> M;
    for (int i = 0; i < N;i++)
    {
        int heap[1001];
        int status,status2;
        for (int j = 1; j <= M; j++)
        {
            cin >> heap[j];
        }
        status = isHeep(heap, 1, cmp_min);
        status2 = isHeep(heap, 1, cmp_max);

        if(status==0)
        {
            cout << "Min Heap" << endl;
        }
        else if(status2==0)
        {
            cout << "Max Heap" << endl;
        }
        else 
        {
            cout << "Not Heap" << endl;
        }
        flag = true;
        postOrder(heap, 1);
        cout << endl;
    }
    return 0;
}