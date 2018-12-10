#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
typedef struct node
{
	int level;
	int site;
	int time;
	int num;
	int ss;
	char str[40];
}stu;

typedef struct node2
{
	int site;
	int cc;
}stu2;
bool cmp(stu &a,stu &b)
{
	if(a.ss==b.ss)
	{
		return strcmp(a.str,b.str)<0 ? true:false;
	}
	else return a.ss>b.ss;
}
bool cmp2(stu2 &a,stu2 &b)
{
	if(a.cc==b.cc)
	{
		return a.site<b.site;
	}
	else return a.cc>b.cc;
}
int N,M;
vector<stu>sA,sB,sT,time22[1000000];

int site[1000][2];
int main()
{
	cin>>N>>M;
	for(int i=0;i<N;i++)
	{
		stu tt;
		char sss[40];
		int score=0;
		scanf("%s %d\n",sss,&score);
		strcpy(tt.str,sss);
		if(sss[0]=='A')
		{
			tt.level=2;
		}
		else if(sss[0]=='T')
		{
			tt.level=1;
		}
		else if(sss[0]=='B')
		{
			tt.level=3;
		}
		tt.site=(sss[1]-48)*100+(sss[2]-48)*10+(sss[3]-48);
		tt.time=(sss[4]-48)*100000+(sss[5]-48)*10000+(sss[6]-48)*1000+(sss[7]-48)*100+(sss[8]-48)*10+(sss[9]-48);
		tt.num=(sss[10]-48)*100+(sss[11]-48)*10+(sss[12]-48);
		tt.ss=score;
		if(sss[0]=='A')
		{
			sA.push_back(tt);
		}
		else if(sss[0]=='T')
		{
			sT.push_back(tt);
		}
		else if(sss[0]=='B')
		{
			sB.push_back(tt);
		}
		site[tt.site][0]++;
		site[tt.site][1]+=tt.ss;
		time22[tt.time].push_back(tt);
	}
	sort(sA.begin(),sA.end(),cmp);sort(sT.begin(),sT.end(),cmp);sort(sB.begin(),sB.end(),cmp);
	for(int i=1;i<=M;i++)
	{
		int t1,t2;
		char c;
		printf("Case %d: ",i);
		scanf("%d ",&t1);
		if(t1==1)
		{
			cin.get(c);
			printf("%d %c\n",t1,c);
			if(c=='A')
			{
				
				for(vector<stu>::iterator it=sA.begin();it!=sA.end();it++)
				{
					cout<<it->str<<" "<<it->ss<<endl;
				}
			}
			else if(c=='T')
			{
				
				for(vector<stu>::iterator it=sT.begin();it!=sT.end();it++)
				{
					cout<<it->str<<" "<<it->ss<<endl;
				}
			}
			else if(c=='B')
			{
				
				for(vector<stu>::iterator it=sB.begin();it!=sB.end();it++)
				{
					cout<<it->str<<" "<<it->ss<<endl;
				}
			}
			else
			{
				cout<<"NA"<<endl;
			}
		}
		else if(t1==2)
		{
			cin>>t2;
			printf("%d %d\n",t1,t2);
			if(t2<=999&&t2>=101&&site[t2][0]!=0&&t2>=101)
			{
				printf("%d %d\n",site[t2][0],site[t2][1]);
			}
			else
			{
				printf("NA\n");
			}
		}
		else if(t1==3)
		{
			cin>>t2;
			printf("%d %06d\n",t1,t2);
			if(t2<999999&&time22[t2].size()>0)
			{
				int hhhh[1000]={0};
				vector<stu2>ans;
				stu2 tt;
				for(vector<stu>::iterator it=time22[t2].begin();it!=time22[t2].end();it++)
				{
					hhhh[it->site]++;
				}
				for(int j=0;j<=999;j++)
				{
					if(hhhh[j]!=0)
					{
						tt.cc=hhhh[j];
						tt.site=j;
						ans.push_back(tt);
					}
				}
				sort(ans.begin(),ans.end(),cmp2);
				for(int j=0;j<ans.size();j++)
				{
					printf("%d %d\n",ans[j].site,ans[j].cc);
				}
			}
			else
			{
				printf("NA\n");
			}
		}
		else
		{
			char ssss[50];
			cin>>ssss;
			printf("%d %s\nNA\n",t1,ssss);
		}
	}
	return 0;
}