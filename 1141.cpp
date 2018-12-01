#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

typedef struct node
{
    string name;
    int Ns;
    int total;
    int B, A, T;
} school;
vector<school> schools;
map<string, int> s2n;
int N,schoolCount=0;


bool cmp(school a,school b)
{
    int x, y;
    x = (int)a.total;
    y = (int)b.total;
    if(x==y)
    {
        if(a.Ns==b.Ns)
        {
            return a.name < b.name;
        }
        else
            return a.Ns < b.Ns;
    }
    else
        return x > y;
}

bool cmp1(school a,school b)
{
    int x, y;
    x = (int)a.total;
    y = (int)b.total;
    if(x==y)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    cin >> N;
    for (int j = 0; j < N;j++)
    {
        string tID;
        double s;
        string tName;
        cin >> tID >> s >> tName;
        
        for (int i = 0; i < tName.size();i++)
        {
            if(tName[i]<97)
            {
                tName[i] += ('a' - 'A');
            }
        }

        if(s2n.find(tName)==s2n.end())
        {
            s2n[tName] = schoolCount;
            school tSchool;
            tSchool.name = tName;
            tSchool.Ns = 1;
            tSchool.B = tSchool.A = tSchool.T = 0;
            if(tID[0]=='B')
            {
                tSchool.B = s;
            }
            else if(tID[0]=='T')
            {
                tSchool.T = s;
            }
            else
            {
                tSchool.A = s;
            }
            
            schools.push_back(tSchool);
            schoolCount++;
        }
        else
        {
            int tNum = s2n[tName];
            schools[tNum].Ns++;
            if(tID[0]=='B')
            {
                schools[tNum].B += s;
            }
            else if(tID[0]=='T')
            {
                schools[tNum].T += s;
            }
            else
            {
                schools[tNum].A += s;
            }
        }
    }
    for (int i = 0; i < schools.size();i++)
    {
        schools[i].total = schools[i].B / 1.5 + schools[i].T * 1.5 + schools[i].A;
    }
    sort(schools.begin(), schools.end(), cmp);
    int rank = 1;
    cout << schools.size() << endl;
    for (int i = 0; i < schools.size();i++)
    {
        if(i!=0&&!cmp1(schools[i],schools[i-1]))
        {
            rank = i + 1;
        }
       
        cout << rank << " " << schools[i].name;
        int t = schools[i].total;
        cout << " " << t<<" "<<schools[i].Ns<<endl;
        
    }

    return 0;
}