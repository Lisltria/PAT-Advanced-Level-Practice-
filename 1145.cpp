#include <iostream>
#include <cstdio>
#include <set>
#include <climits>
#include <cmath>
int hh[20001];
using namespace std;
int Tsize, N, M;

bool isPrime(int num)
{
    bool flag=true;
    if(num==2)return true;
    if(num==1)return false;
    if(num<=0)return false;
    for(int i=2;i<=sqrt(num)+1;i++)
    {
        if(num%i==0)
        {
            flag=false;
            break;
        }
    }
    return flag;
}
int find(int x)
{
    if(x==1)
        return 2;
    for (int i = x; ; i++)
    {
        if(isPrime(i))
        {
            return i;
        }
    }
}
int main()
{
    cin >> Tsize >> N >> M;
    Tsize = find(Tsize);

    for (int i = 0; i < N;i++)
    {
        int t;
        cin >> t;
        bool inputFlag = false;
        for (int j = 0; j < Tsize; j++)
        {
            if(hh[(t%Tsize+j*j)%Tsize]==0)
            {
                hh[(t % Tsize + j * j) % Tsize] = t;
                inputFlag = true;
                break;
            }
        }
        if(!inputFlag)
        {
            cout << t << " cannot be inserted." << endl;
        }
    }
    int count = 0;
    for (int i = 0; i < M;i++)
    {
        int t;
        bool f=false;
        cin >> t;
        for (int j = 0; j <=Tsize; j++)
        {
            
            if(hh[(t%Tsize+j*j)%Tsize]!=t&&hh[(t%Tsize+j*j)%Tsize]!=0)
            {
                count++;
            }
            else
            {
                count++;
                break;
                        }

        }
    }
    printf("%.1f\n", 1.0 * count / M);
    return 0;
}