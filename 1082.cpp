#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
char number[15];
bool first=true;
char str1[3][10]={"Fu","Yi","Wan"};
char str2[4][10]={"","Shi","Bai","Qian"};
char digit[10][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};


void read(int idx,int left){
    if(left==0)
        return;
    if(number[idx]=='0'){
        bool allZero=true; 
        int cnt=0;
        for(int i=idx;i<idx+left;i++){
            if(number[i]!='0'){
                allZero=false;
                break;
            }
            else
                cnt++;
        }
        if(!allZero){
            printf(" ling");
            read(idx+cnt,left-cnt);
        }
    }
    else{
        if(!first)
            printf(" ");
        else
            first=false;
        printf("%s",digit[number[idx]-'0']);
        if(left>1)
            printf(" %s",str2[left-1]);
        read(idx+1,left-1);
    }
}
int main()
{
    first=true;
    scanf("%s",number);
    int len=strlen(number);
    int left=len;
    int idx=0;
    int a=atoi(number);
    //
    if(a==0){
        printf("ling");
        return 0;
    }
    if(number[0]=='-'){
        first=false;
        printf("Fu");
        left--;
        idx++;
    }
    if(left>=9){
        if(!first){
            printf(" ");
        }
        else
            first=false;
        printf("%s",digit[number[idx]-'0']);
        printf(" Yi");
        left--;
        idx++;
    }

    if(5<=left && left<=8){
        read(idx,left-4);
        idx+=left-4;
        left=4;
        printf(" Wan");
    }

    if(1<=left<=4){
        read(idx,left);
    }
    return 0;
}