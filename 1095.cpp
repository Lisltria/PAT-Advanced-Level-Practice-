//用树状数组再做一遍
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
typedef struct node
{
    string ID;
    struct Time
    {
        int hh;
        int mm;
        int ss;
    } time;
    bool state;
    int second;
} recode;

typedef struct{
    string ID;
    int seconds;
} sortNode;

vector<sortNode> sortX;
vector<recode> recodes[10000],sortV;
map<string, int> NUM_ID;
int timeAxis[90000];

void insert(recode r,int *T)
{
    int tt = r.time.ss + r.time.mm * 60 + r.time.hh * 3600;
    T[tt] += r.state ? 1 : -1;
}

void timeCalc(recode s,recode e,sortNode &ans)
{
    int t1 = s.time.ss + s.time.mm * 60 + s.time.hh * 3600;
    int t2 = e.time.ss + e.time.mm * 60 + e.time.hh * 3600;
    int t3 = t2 - t1;
    ans.seconds += t3;
}
bool cmp(recode a,recode b)
{
    return a.second < b.second;
}
bool cmp1(sortNode a,sortNode b)
{
    if(a.seconds == b.seconds)
    {
        return a.ID < b.ID;
    }
    else return a.seconds > b.seconds;
}
int main(int argc, char const *argv[])
{
    /* code */
    int N, K, count = 0;
    cin >> N >> K;
    for (int i = 0; i < N;i++)
    {
        recode t;
        string ts;
        cin >> t.ID;
        scanf("%d:%d:%d ", &t.time.hh, &t.time.mm, &t.time.ss);
        cin >> ts;
        if(ts=="in")
            t.state = true;
        else
            t.state = false;
        t.second = t.time.hh * 3600 + t.time.mm * 60 + t.time.ss;
        sortV.push_back(t);
    }
    sort(sortV.begin(), sortV.end(), cmp);
    for (int i = 0; i < N;i++)
    {
        recode t;
        t = sortV[i];
        if(NUM_ID.find(t.ID)==NUM_ID.end())
        {
            NUM_ID[t.ID] = count;
            recodes[count].push_back(t);
            count++;
        }
        else{
            recodes[NUM_ID[t.ID]].push_back(t);
        }
    }
    for (int i = 0; i < count; i++)
    {
        auto iter = recodes[i].begin();
        while((iter)!=recodes[i].end()&&(iter+1)!=recodes[i].end())
        {
            if(!(iter->state==true&&(iter+1)->state==false))
            {
                recodes[i].erase(iter);
            }
            else
            {
                iter += 2;
            }
        }

    }
    int maxtime = 0;
    sortNode maxrecode;
    for (int i = 0; i < count; i++)
    {
        sortNode t;
        t.seconds = 0;
        while(1)
        {
            if(!recodes[i].empty())
            {
                
                auto in = recodes[i].begin();
                auto out = recodes[i].begin()+1;
                if(in->state==true&&out->state==false)
                {
                    insert(*in, timeAxis);
                    insert(*out, timeAxis);
                    t.ID = in->ID;
                    timeCalc(*in, *out, t);
                    recodes[i].erase(out);
                    recodes[i].erase(in);
                }
                else
                {
                    break;
                }
            }
            else
                break;
        }
        sortX.push_back(t);
    }
    int milestone=0;
    for (int i = 0; i < 90000;i++)
    {
        milestone += timeAxis[i];
        timeAxis[i] = milestone;
    }
    for (int i = 0; i < K; i++)
    {
        int a, b, c;
        int t;
        scanf("%d:%d:%d", &a, &b, &c);
        t = a * 3600 + b * 60 + c;
        cout << timeAxis[t] << endl;
    }
    sort(sortX.begin(), sortX.end(), cmp1);
    cout << sortX.begin()->ID;
    for (int i = 1; i < sortX.size();i++)
    {
        if(sortX[i].seconds==sortX[i-1].seconds)
        {
            cout << " " << sortX[i].ID;
        }
        else
        {
            break;
        }
    }
    int calcctime=sortX.begin()->seconds;
    printf(" %02d:%02d:%02d\n", calcctime / 3600, calcctime % 3600 / 60, calcctime % 3600 % 60);

    return 0;
}
