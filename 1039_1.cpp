#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N,K;
vector<int> student[190000];

int main()
{
    cin>>N>>K;
    for(int i=0;i<K;i++)
    {
        int course_num,t_stu_num,t;
        char s[5];
        cin>>course_num>>t_stu_num;
        for(int j=0;j<t_stu_num;j++)
        {
            scanf("%s",s);
            t=(s[0]-'A')*26*26*10+(s[1]-'A')*26*10+(s[2]-'A')*10+(s[3]-'0');
            student[t].push_back(course_num);
        }
    }
    for(int i=0;i<N;i++)
    {
        char s[5];
        int t;
        scanf("%s",s);
        cout<<s;
        t=(s[0]-'A')*26*26*10+(s[1]-'A')*26*10+(s[2]-'A')*10+(s[3]-'0');
        if(student[t].size()==0)
        {
            cout<<" 0"<<endl;
        }
        else{
            sort(student[t].begin(),student[t].end());
            cout<<" "<<student[t].size();
            for(vector<int>::iterator iter=student[t].begin();iter!=student[t].end();iter++)
            {
                cout<<" "<<(*iter);
            }
            cout<<endl;
        }
    }
    return 0;
}

