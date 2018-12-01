#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int words[101];
int status[101];

int fun(int i,int j)
{
	if(status[i]==0&&status[j]==0)
	{
		return i;
	}
	else if(status[i]==-1&&status[j]==0)
	{
		return i;
	}
	else if(status[i]==0&&status[j]==-1)
	{
		return j;
	}
	else if(status[i]==1&&status[j]==0)
	{
		return j;
	}
	else if(status[i]==0&&status[j]==1)
	{
		return i;
	}
	else if(status[i]==1&&status[j]==-1)
	{
		return j;
	}
	else if(status[i]==-1&&status[j]==1)
	{
		return i;
	}
	return 102;
}

int main()
{
	int N,ans1=101,ans2=101;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> words[i];
	}
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			bool flag = true;
			for (int k = 1; k <= N; k++)
			{
				status[k] = 0;
			}
			for (int k = 1; k <= N; k++)
			{
				if(k==i||k==j)
					continue;
				if(status[abs(words[k])]==0||
				(status[abs(words[k])]==1&&words[k] > 0)||
				(status[abs(words[k])]==-1&&words[k] < 0)
				)
				{
					status[abs(words[k])] = words[k] > 0 ? 1 : -1;
				}
				else
				{
					flag = false;
					break;
				}
			}
			if(!flag)
				continue;
			if(status[abs(words[i])]==0||
				(status[abs(words[i])]==1&&words[i] < 0)||
				(status[abs(words[i])]==-1&&words[i] > 0)
				)
			{
				status[abs(words[i])] = words[i] < 0 ? 1 : -1;
			}
			else
			{
				continue;
			}
			if(status[abs(words[j])]==0||
				(status[abs(words[j])]==1&&words[j] < 0)||
				(status[abs(words[j])]==-1&&words[j] > 0)
				)
			{
				status[abs(words[j])] = words[j] < 0 ? 1 : -1;
			}
			else
			{
				continue;
			}
			int countW=0, w=101,wt=101;
			for (int k = 1; k <= N; k++)
			{
				if(k==i||k==j)
					continue;
				if(status[k]==-1)
				{
					countW++;
					w = k;
				}
				if(wt==101&&status[k]==0)
				{
					wt = k;
				}
			}
			if(countW==1||(countW==0&&wt!=101))
			{
				int anst1 = (countW == 0 ? wt : w), anst2 = fun(i, j);
				if(anst1>anst2)
					swap(anst1, anst2);
				if(anst1<=100&&anst2<=100)
				{
					if(anst1<ans1||(anst1==ans1&&anst2<ans2))
					{
						ans1 = anst1;
						ans2 = anst2;
					}
				}
			}
		}
	}
	if(ans1==101||ans2==101)
	{
		cout << "No Solution" << endl;
	}
	else
	{
		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}