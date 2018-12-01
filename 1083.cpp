#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct node
{
    string name;
    string ID;
    int grade;
}p;
vector<p> list;
bool cmp(p a, p b) { return a.grade > b.grade; }
int main(int argc, char const *argv[])
{
    /* code */
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        p t;
        cin >> t.name >> t.ID >> t.grade;
        list.push_back(t);
    }
    int x, y;
    cin >> x >> y;
    sort(list.begin(), list.end(), cmp);
    bool f = false;
    for (auto iter = list.begin(); iter != list.end(); iter++)
    {
        if(iter->grade>=x&&iter->grade<=y)
        {
            cout << iter->name << " " << iter->ID << endl;
            f = true;
        }
    }
    if(!f)
        cout << "NONE" << endl;
    return 0;
}
