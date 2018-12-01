#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

bool WornOut[37];
bool Type[37];
bool realType[37];
bool ans[37];
int main(int argc, char const *argv[])
{
    /* code */
    char c;
    string s;
    while((cin.get(c),c)!='\n')
    {
        s.push_back(c);
        if(c=='_')
            Type[36]=true;
        else if(c>='0'&&c<='9')
            Type[c - 48 + 26] = true;
        else if(c>='A'&&c<='Z')
            Type[c - 'A'] = true;
        else if(c>='a'&&c<='z')
            Type[c - 'a'] = true;
        
    }
    while((cin.get(c),c)!='\n'&&c!=EOF)
    {
        if(c=='_')
            realType[36] = true;
        else if(c>='0'&&c<='9')
            realType[c - 48 + 26] = true;
        else if(c>='A'&&c<='Z')
            realType[c - 'A'] = true;
        else if(c>='a'&&c<='z')
            realType[c - 'a'] = true;
    }
    for (int i = 0; i < s.size(); i++)
    {
        c = s[i];
        int h;
        if(c=='_')
            h = 36;
        else if(c>='0'&&c<='9')
            h = c - 48 + 26;
        else if(c>='A'&&c<='Z')
            h = c - 'A';
        else if(c>='a'&&c<='z')
            h = c - 'a';
        if(Type[h]&&!realType[h]&&!ans[h])
        {
            ans[h] = true;
            if(h==36)
            {
                cout << "_";
            }
            else if(h>=26)
            {
                c = h - 26 + 48;
                cout << c;
            }
            else
            {
                c = h + 'A';
                cout << c;
            }
        }
    }

    cout << endl;
    return 0;
}
