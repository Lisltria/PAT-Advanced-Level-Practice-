#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
long long jinzhi(char str[],long long radix);
int maxstr(char str[]);
long long BinSear(long long target,char str[],long long low,long long high);
int compare(char str[],long long radix,long long target);

int main()
{
	char N1[11]={0};
	char N2[11]={0};
	int tag;
	long long radix;//此处输入有可能超过int表示范围 
	cin>>N1>>N2>>tag>>radix;
	
    if(tag==2)
    {
        char t[12];
        strcpy(t,N1);
        strcpy(N1,N2);
        strcpy(N2,t);
    }

	long long low,high,heji=0;
	
	heji=jinzhi(N1,radix);
	long long temp=(long long)maxstr(N2)+1;//此处temp最小值为2，最大值为36 
	if(heji<=temp)//如果了heji比temp还要小 
	{
		long long linshi=BinSear(heji,N2,temp,36);//待求进制数介于temp到36之间 
		if(linshi==-1)
			cout<<"Impossible";
		else
			cout<<linshi;
	}
	else
	{
		low=2;
		high=heji+1;
		long long result=BinSear(heji,N2,low,high);	
		if(result==-1)
			cout<<"Impossible";
		else
			cout<<result;
	}	

	return 0;
}
int compare(char str[],long long radix,long long target)
{
	int length=strlen(str);
	long long sum=0;
	for(int i=0;i<length;i++)
	{
		if(str[i]<58)
			sum=sum*radix+(str[i]-48);
		else
			sum=sum*radix+(str[i]-87);
		if(sum>target||sum<0)//sum<0是因为有可能目标数太大了，导致long long也不够存储，超过计算机存储范围，就会变为复数 
			return 1;        //非常重要，错误点
	}

	if(sum>target)
		return 1;
	else if(sum<target)
		return -1;	
	else
		return 0;//sum等于target 

}

long long BinSear(long long target,char str[],long long low,long long high)
{
	long long mid=low;
	while(low<=high)
	{
		if(compare(str,mid,target)==1)
			high=mid-1;
		else if(compare(str,mid,target)==-1)
			low=mid+1;
		else
			return mid;	
		mid=(low+high)/2;//缩小查找范围 
	}
	return -1;	
}

long long jinzhi(char str[],long long radix)
{
	int length=strlen(str);
	long long sum=0;
	for(int i=0;i<length;i++)
		if(str[i]<58)
		sum=sum*radix+(str[i]-48);
		else
		sum=sum*radix+(str[i]-87);
	return sum;	
} 
int maxstr(char str[])//进制最小数量必须所包含最大数字大1，例如出现有f，则至少是16进制，如出现7，至少是8进制 
{
	int length=strlen(str);
	int max=0;
	for(int i=0;i<length;i++)
	{
		if(str[i]<58&&str[i]-48>max)
		max=str[i]-48;
		else if(str[i]-87>max)
		max=str[i]-87;
	}
	if(max>1)
		return max;
	else
		return 1;//如果字符串内容全都是0,那么最大值应该是1才对 
}
