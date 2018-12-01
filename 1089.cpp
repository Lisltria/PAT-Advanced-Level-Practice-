#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int list[100];
int comlist[100];
int auxlist[100];
bool cmpare(int a[],int b[])
{
    for (int i = 0; i < N; i++)
    {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}
bool insertSort(int X[])
{
    bool flag = false;
    int D[101];
    for (int i = 0; i < N; i++)
    {
        D[i] = X[i];
    }
    for (int i = 1; i < N; i++)
    {
        if(flag&&!cmpare(D,comlist))
        {
            break;
        }
        if(!flag&&cmpare(D,comlist))
        {
            flag = true;
        }
        if(D[i]<D[i-1])
        {
            for (int j = i; j >= 1; j--)
            {
                if(D[j]<D[j-1])
                {
                    swap(D[j], D[j - 1]);
                }
            }
        }
        
    }
    if(!flag)
        return flag;
    cout << "Insertion Sort" << endl;
    for (int i = 0; i < N; i++)
    {
        if(i!=0)
            cout << " ";
        cout << D[i];
    }
    cout << endl;
    return flag;
}
bool mergeflag = false,finish=false;
void mergeSort(int s,int e,int D[],int a)
{

    int l = s, r = s + a;
    for (int i = s; i <= e; i++)
    {
        if(l <= s + a - 1 && r <= e )
        {
            if( D[l]<=D[r])
            {
                auxlist[i] = D[l];
                l++;
            }
            else
            {
                auxlist[i] = D[r];
                r++;
            }
        }
        else if(l <= s + a - 1 && r > e )
        {
            auxlist[i] = D[l];
            l++;
        }
        else if(l > s + a - 1 && r <= e )
        {
            auxlist[i] = D[r];
            r++;
        }
    }
    for (int i = s; i <= e; i++)
    {
        D[i] = auxlist[i];
    }

    
}
int main(int argc, char const *argv[])
{
    /* code */
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> list[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> comlist[i];
    }
    if(!insertSort(list))
    {
        int t=1;
   
        while(t<N)
        {
            //cout << 2 * t << endl;
            if(finish)
                    break;
            for (int i = 0;; i+=2*t)
            {
                if(i>N-1)
                    break;

                if(i+2*t-1>N-1)
                {
                    mergeSort(i, N-1, list, t);
                }
                else
                {
                    mergeSort(i, i + 2 * t-1, list, t);
                }

                if(i+2*t-1>N-1)
                {
                    break;
                }
            }
            if(mergeflag&&!cmpare(list,comlist))
            {
                finish = true;
                cout << "Merge Sort" << endl;
                for (int i = 0; i < N; i++)
                {
                    if(i!=0)
                        cout << " ";
                    cout << list[i];
                }
                cout << endl;
            }
            if(!mergeflag&&cmpare(list,comlist))
            {
                mergeflag = true;
            }
            t *= 2; 
        }
    }
    return 0;
}
