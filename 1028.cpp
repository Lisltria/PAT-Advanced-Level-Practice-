#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct node{
    char ID[10];
    char NAME[10];
    int grade;
}Student;
Student students[100001];
int N,type;

bool cmp1(Student a,Student b)
{
    return strcmp(a.ID,b.ID)<0 ? true:false;
}
bool cmp2(Student a,Student b)
{
    if(strcmp(a.NAME,b.NAME)==0)
    {
        return strcmp(a.ID,b.ID)<0 ? true:false;
    }
    else
        return strcmp(a.NAME,b.NAME)<0 ? true :false;
}
bool cmp3(Student a,Student b)
{
    if(a.grade==b.grade)
    {
        return strcmp(a.ID,b.ID)<0 ? true:false;
    }
    else
        return a.grade<b.grade;
}
int main(int argc, char const *argv[])
{
    /* code */
    cin>>N>>type;
    for(int i=0;i<N;i++)
    {
        cin>>students[i].ID>>students[i].NAME>>students[i].grade;
    }
    if(type==1)
    {
        sort(students,students+N,cmp1);
    }
    if(type==2)
    {
        sort(students,students+N,cmp2);
    }
    if(type==3)
    {
        sort(students,students+N,cmp3);
    }
    for(int i=0;i<N;i++)
    {
        cout<<students[i].ID<<" "
            <<students[i].NAME<<" "
            <<students[i].grade<<endl;
    }

    return 0;
}
