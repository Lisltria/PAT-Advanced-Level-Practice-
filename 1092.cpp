#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int list[128];

int main(int argc, char const *argv[])
{
    /* code */
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i < s1.size(); i++)
    {
        list[s1[i]] += 1;
    }
    int count = 0;
    for (int i = 0; i < s2.size(); i++)
    {
        if(list[s2[i]]>0)
        {
            count++;
            list[s2[i]]--;
        }
    }
    if(count==s2.size())
    {
        cout << "Yes " << s1.size() - s2.size() << endl;
    }
    else
    {
        cout << "No " << s2.size() - count<< endl;
    }
    return 0;
}
