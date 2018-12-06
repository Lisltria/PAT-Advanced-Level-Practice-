#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int arry[201];
int heap[201];
int cmp[200];

void remainHeap(int *H,int i,int size)
{
    int iter = i;
    while(iter<=size/2+1)
    {
        if(iter*2<=size&&iter*2+1<=size)
        {
            if(H[iter]>H[iter*2]&&H[iter]>H[iter*2+1])
            {
                break;
            }
            else if(H[iter*2+1]>H[iter*2])
            {
                swap(H[iter * 2 + 1], H[iter]);
                iter = iter * 2 + 1;
            }
            else
            {
                swap(H[iter * 2], H[iter]);
                iter = iter * 2;
            }
        }
        else if(iter*2<=size&&iter*2+1>size)
        {
            if(H[iter]<H[iter*2])
            {
                swap(H[iter * 2], H[iter]);
                iter = iter * 2;
            }
            else
            {
                break;
            }
        }
        else  
        {
            break;
        }
    }
}

void buildHeap(int *H,int size)
{
    for (int i = size / 2+1; i >= 1;i--)
    {
        remainHeap(H, i, size);
    }
}
void keepHeap(int *H,int size)
{
    remainHeap(H, 1, size);
}
bool cmpare(int *A,int *B,int size)
{
    for (int i = 1; i <= size;i++)
    {
        if(A[i]!=B[i])
            return false;
    }
    return true;
}

int main()
{
    int N;

    cin >> N;
    for (int i = 1; i <= N*2;i++)
    {
        heap[i] = -1;
    }
    for (int i = 1; i <= N;i++)
    {
        cin >> arry[i];
        heap[i] = arry[i];
    }
    for (int i = 1; i <= N;i++)
    {
        cin >> cmp[i];
    }

    bool heapFlag = false;
    buildHeap(heap, N);
    for (int i = 1; i < N;i++)
    {
        swap(heap[1], heap[N + 1 - i]);
        keepHeap(heap, N - i);
        if(heapFlag)
        {
            break;
        }
        if(cmpare(cmp,heap,N)&&heapFlag==false)
        {
            heapFlag = true;
        }
    }
    if(heapFlag)
    {
        cout << "Heap Sort" << endl;
        for (int i = 1; i <= N;i++)
        {
            if(i!=1)
                cout << " ";
            cout << heap[i];
        }
        cout << endl;
    }

    bool insertFlag = false;

    for (int i = 2; i <= N;i++)
    {
        for (int j = i; j >= 2;j--)
        {
            if(arry[j]<arry[j-1])
            {
                swap(arry[j], arry[j - 1]);
            }
            else
                break;
        }
        if(insertFlag)
        {
            break;
        }
        if(cmpare(arry,cmp,N)&&insertFlag==false)
        {
            insertFlag = true;
        }
    }
    if(insertFlag)
    {
        cout << "Insertion Sort" << endl;
        for (int i = 1; i <= N;i++)
        {
            if(i!=1)
                cout << " ";
            cout << arry[i];
        }
        cout << endl;
    }

        return 0;
}