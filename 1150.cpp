#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

int map[201][201];

int main()
{
    int N, M,K;
    cin >> N >> M;

    for (int i = 0; i < N;i++)
    {
        for (int j = 0; j < N;j++)
        {
            map[i][j] = INT32_MAX;
        }
    }

    for (int i = 0; i < M;i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        if(map[t1][t2]==0||map[t1][t2]>t3)
        {
            map[t1][t2] = t3;
        }
        if(map[t2][t1]==0||map[t2][t1]>t3)
        {
            map[t2][t1] = t3;
        }
    }

    cin >> K;
    int min=INT32_MAX, mini;
    for (int i = 0; i < K; i++)
    {
        int cities[201];
        bool isNA = false;
        for (int j = 0; j <= N;j++)
        {
            cities[j] = 0;
        }

        int nCity, tCity, iterCity, sum = 0;
        int first=-1, end=-1;
        cin >> nCity;
        for (int j = 0; j < nCity; j++)
        {
            cin >> tCity;
            if(first==-1)
            {
                first = tCity;
            }
            end = tCity;
            if(j==0)
            {
                iterCity = tCity;
                cities[tCity] += 1;
                continue;
            }
            else
            {
                if(map[iterCity][tCity]==INT32_MAX)
                {
                    isNA = true;
                }
                sum += map[iterCity][tCity];
                cities[tCity] += 1;
                iterCity = tCity;
            }
        }
        bool isSimple = true, isCycle = true, isAll = true;
        
        if(first!=end)
            isCycle = false;
        else
            cities[end] -= 1;
        for (int j = 1; j <= N; j++)
        {
            if(cities[j]==0)
            {
                isAll = false;
            }
            if(cities[j]>1)
            {
                isSimple = false;
            }
        }

        if(nCity==1)
        {
            printf("Path %d: 0 (TS simple cycle)", i + 1);
        }
        else
        {
            printf("Path %d: ", i + 1);
            if(isNA)
            {
                printf("NA (Not a TS cycle)\n");
            }
            else if(!isCycle||!isAll)
            {
                printf("%d (Not a TS cycle)\n",sum);
            }
            else if(!isSimple)
            {
                printf("%d (TS cycle)\n",sum);
                if(sum<min)
                {
                    min = sum;
                    mini = i + 1;
                }
            }
            else
            {
                if(sum<min)
                {
                    min = sum;
                    mini = i + 1;
                }
                printf("%d (TS simple cycle)\n",sum);
            }
        }


    }
    printf("Shortest Dist(%d) = %d\n", mini, min);
    return 0;
}