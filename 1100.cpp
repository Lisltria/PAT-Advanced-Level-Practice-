#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

string mars[] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string marsH[] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int main()
{
    int N;
    cin >> N;
    cin.get();
    for (int i = 0; i < N;i++)
    {
        string ss;
        int t;
        getline(cin, ss);
        const char *s=ss.c_str();
        if (s[0] <= '9')
        {
            sscanf(s, "%d", &t);
            if(t<13)
            {
                cout << mars[t] << endl;
            }
            else
            {
                cout << marsH[t / 13 - 1];
                if(t%13==0)
                    cout << endl;
                else
                {
                    cout << " " << mars[t % 13] << endl;
                }
            }
        }
        else
        {
            char t1[50], t2[50];
            int i;
            for (i = 0; i < strlen(s);i++)
            {
                if(s[i]=='\n'||s[i]==' ')
                    break;
                t1[i] = s[i];
            }
            t1[i] = '\0';
            i++;
            for (; i < strlen(s);i++)
            {
                t2[i-strlen(t1)-1] = s[i];
            }
            t2[i - strlen(t1) - 1] = '\0';
            int t = -1;
            if(strlen(t2)==0)
            {
                for (i = 0; i <= 12;i++)
                {
                    if(strcmp(t1,mars[i].c_str())==0)
                    {
                        t = i;
                        break;
                    }
                }
                if(t==-1)
                {
                    for (i = 0; i <= 11;i++)
                    {
                        if(strcmp(t1,marsH[i].c_str())==0)
                        {
                            t = i+1;
                            break;
                        }
                    }
                    t *= 13;
                }
                cout << t << endl;
            }
            else
            {
                for (i = 0; i <= 11;i++)
                {
                    if(strcmp(t1,marsH[i].c_str())==0)
                    {
                        t = i + 1;
                        break;
                    }
                }
                t *= 13;
                for (i = 0; i <= 12;i++)
                {
                    if(strcmp(t2,mars[i].c_str())==0)
                    {
                        t += i;
                        break;
                    }
                }
                cout << t << endl;
            }
        }
    }
    return 0;
}