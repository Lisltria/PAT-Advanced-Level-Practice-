#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int N,K;

typedef struct node{
    int course_num;
    int last;
}course;
course courses[500001];
int students[40001];
int course_count=0;
int student_count=0;
int sort_list[3000];
map<string, int>student_num;
int main(int argc, char const *argv[])
{
    /* code */
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        students[i]=-1;
    }
    for(int i=0;i<K;i++)
    {
        int t_course_num,t_stu_num;
        int record;
        cin>>t_course_num>>t_stu_num;
        for(int j=0;j<t_stu_num;j++)
        {
            string t_s;
            cin>>t_s;
            
            if(student_num.find(t_s)==student_num.end())
            {
                student_num[t_s]=student_count;
                record=student_count;
                student_count++;
            }
            else{
                record=student_num[t_s];
            }
            courses[course_count].course_num=t_course_num;
            courses[course_count].last=students[record];
            students[record]=course_count;
            course_count++;
        }
    }
    for(int i=0;i<N;i++)
    {
        string t_s;
        int record,tt;
        map<string, int>::iterator iter;
        cin>>t_s;
        iter=student_num.find(t_s);
        if(iter==student_num.end())
        {
            cout<<t_s<<" 0"<<endl;
        }
        else
        {
            int sort_count=0;
            record=iter->second;
            cout<<iter->first<<" ";

            tt=students[record];
            while(tt>=0)
            {
                if(sort_count>0&&sort_list[sort_count-1]==courses[tt].course_num)
                {
                    continue;
                }
                else
                { 
                    sort_list[sort_count]=courses[tt].course_num;
                    sort_count++;
                }
                tt=courses[tt].last;
            }
            sort(sort_list,sort_list+sort_count);
            cout<<sort_count;
            for(int j=0;j<sort_count;j++)
            {
                cout<<" "<<sort_list[j];
            }
            cout<<endl;
        }

    }
    return 0;
}
