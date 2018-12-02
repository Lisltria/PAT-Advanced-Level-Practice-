#include <iostream>
#include <cstdio>
#include <unordered_set>
#include <string>
using namespace std;

unordered_set<string> ans;
int main(int argc, char const *argv[])
{
    /* code */
    int M, K, S;
    int whoIsWinner;
    cin >> M >> K >> S;
    whoIsWinner = S;
    for (int i = 1; i <= M;i++)
    {
        string t;
        cin >> t;
        if(i==whoIsWinner&&ans.find(t)==ans.end())
        {
            cout << t << endl;
            whoIsWinner = whoIsWinner + K;
            ans.insert(t);
        }
        else if(i==whoIsWinner&&ans.find(t)!=ans.end())
        {
            whoIsWinner++;
        }
    }
    if(S>M)
    {
        cout << "Keep going..." << endl;
    }
        return 0;
}
