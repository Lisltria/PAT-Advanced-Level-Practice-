#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct student{
    string name;
    bool male;
    string ID;
    int grade;
}students;
students male[200],female[200];
bool cmp_male(students a, students b)
{
    return a.grade<b.grade;
}
bool cmp_female(students a, students b)
{
    return a.grade>b.grade;
}
int main(int argc, char const *argv[])
{
    /* code */
    int N,N_male=0,N_female=0;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        string t_name,t_ID;
        int t_grade;
        char c;
        cin>>t_name>>c>>t_ID>>t_grade;
        if(c=='M')
        {
            male[N_male].name=t_name;
            male[N_male].male=true;
            male[N_male].ID=t_ID;
            male[N_male].grade=t_grade;
            N_male++;
        }
        else
        {
            female[N_female].name=t_name;
            female[N_female].male=false;
            female[N_female].ID=t_ID;
            female[N_female].grade=t_grade;
            N_female++;
        } 
    }
    sort(male,male+N_male,cmp_male);
    sort(female,female+N_female,cmp_female);
    if(N_female==0)
    {
        cout<<"Absent"<<endl;
    }
    else
    {
        cout<<female[0].name<<" "<<female[0].ID<<endl;
    }

    if(N_male==0)
    {
        cout<<"Absent"<<endl;
    }
    else
    {
        cout<<male[0].name<<" "<<male[0].ID<<endl;
    }

    if(N_male==0||N_female==0)
    {
        cout<<"NA"<<endl;
    }
    else
    {
        cout<<abs(male[0].grade-female[0].grade)<<endl;
    }

    return 0;
}
