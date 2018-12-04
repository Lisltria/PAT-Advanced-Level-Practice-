#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int N;
    double sum=0.0;
    int count = 0;
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        char s[1000];
        cin >> s;
        bool legal = true;
        bool hasOnePoint = false;
        for (int j = 0; j < strlen(s);j++)
        {
            if(s[j]=='-'&&j>0)
            {
                legal = false;
            }
            if(!(s[j]<='9'&&s[j]>='0')&&s[j]!='.'&&s[j]!='-')
            {
                legal = false;
            }
            if(s[j]=='.'&&hasOnePoint==true)
            {
                legal = false;
            } 
            if(s[j]=='.')
            {
                hasOnePoint = true;
            }
        }

        if(legal&&hasOnePoint)
        {
            int j;
            for (j = 0; j < strlen(s);j++)
            {
                if(s[j]=='.')
                    break;
            }
            if(strlen(s)-j>3)
            {
                legal = false;
            }
        }
        double x;
        sscanf(s, "%lf", &x);
        if(abs(x)>1000)
        {
            legal = false;
        }
        if(legal)
        {
            sum += x;
            count++;
        }
        else
        {
            printf("ERROR: %s is not a legal number\n", s);
        }
    }
    if(count==0)
    {
        cout << "The average of 0 numbers is Undefined" << endl;
    }
    else if(count==1)
    {
        printf("The average of %d number is %.2lf\n", count, sum / count);
    }
    else
    {
        printf("The average of %d numbers is %.2lf\n", count, sum / count);
    }
    return 0;
}