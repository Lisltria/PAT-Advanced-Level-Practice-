
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long fun1(char *s)
{
    long ans=0;
    ans = s[0] - 48;
    for (int i = 1; i < strlen(s);i++)
    {
        ans *= 10;
        ans += s[i] - 48;
    }
    return ans;
}
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char s[30],s1[30],s2[30];
        long Z,A,B;
        long ans;
        int h;
        cin >> s;
        Z = fun1(s);
        h=(int)(strlen(s) / 2);
        for (int j = 0; j < h; j++)
        {
            s1[j] = s[j];
            s2[j] = s[j + h];
        }
        s1[h] = s2[h] = '\0';
        A = fun1(s1);
        B = fun1(s2);
        if(A*B==0&&Z!=0)
        {
            cout << "No" << endl;
            continue;
        }
        ans = Z / (A * B);
        ans *= A * B;

        if(Z==ans)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}