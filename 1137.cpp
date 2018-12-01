#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef struct node
{
    string ID;
    char IDc[30];
    int Gp;
    int Gm;
    int Gf;
    int G;
    node():Gp(-1),Gm(-1),Gf(-1),G(-1){}
} student;
map<string, int> id2num;
vector<student> students,sortV;
int sC = 0;
int P, M, N;

bool cmp(student &a,student &b)
{
    if(a.G==b.G)
    {
        return strcmp(a.IDc , b.IDc)<0;
    }
    else
        return a.G > b.G;
}
void cpy(string s, char *t)
{
    for (int i = 0; i < s.size();i++)
    {
        t[i] = s[i];
    }
    t[s.size()] = '\0';
}

int main()
{
    cin >> P >> M >> N;
    for (int i = 0; i < P;i++)
    {
        string t;
        int gp;
        cin >> t >> gp;
        if(gp<200)
            continue;
        else
        {
            student newStudent;
            id2num[t] = sC;
            newStudent.Gp = gp;
            newStudent.ID = t;
            cpy(t, newStudent.IDc);
            students.push_back(newStudent);
            sC++;
        }
    }
    for (int i = 0; i < M;i++)
    {
        string t;
        int gm;
        cin >> t >> gm;
        if(id2num.find(t)==id2num.end())
        {
            continue;
        }
        else
        {
            students[id2num[t]].Gm = gm;
        }
    }
    for (int i = 0; i < N;i++)
    {
        string t;
        int gf;
        cin >> t >> gf;
        if(id2num.find(t)==id2num.end())
        {
            continue;
        }
        else
        {
            int h = id2num[t];
            students[h].Gf = gf;
        }
    }
    for (auto it = students.begin(); it != students.end(); it++)
    {
        int flag = true;
        if(it->Gf > -1 && it->Gm >-1)
        {
            it->G = it->Gm > it->Gf ? (it->Gm * 0.4 + it->Gf * 0.6 +0.5) : it->Gf;
        }
        else if(it->Gf == -1 && it->Gm >-1)
        {
            it->G = 0;
            flag = false;
        }
        else if(it->Gf > -1 && it->Gm == -1)
        {
            it->G = it->Gf;
        }

        if(it->G<60)
        {
            flag = false;
        }
        if(!flag)
        {
            
            
        }
        else
        {
            sortV.push_back((*it));
        }
    }
    sort(sortV.begin(), sortV.end(), cmp);
    for (auto it = sortV.begin(); it != sortV.end(); it++)
    {
        printf("%s %d %d %d %d\n", it->IDc, it->Gp, it->Gm, it->Gf, it->G);
    }
    return 0;
}