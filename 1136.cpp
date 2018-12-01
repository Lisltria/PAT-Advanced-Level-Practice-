#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool isPalindrome(char *s)
{
    int n = strlen(s);
    for (int i = 0; i < n / 2;i++)
    {
        if(s[i]!=s[n-1-i])
        {
            return false;
        }
    }
    return true;
}
void reverseString(char *s)
{
    int n = strlen(s);
    for (int i = 0; i < n / 2;i++)
    {
        swap(s[i], s[n - i - 1]);
    } 
}
void sum(char *a,char *b,char *c)
{
    reverseString(a);
    reverseString(b);
    int addc = 0, i;
    for (i = 0; i < strlen(a) || i < strlen(b);i++)
    {
        int t1, t2;
        t1 = i < strlen(a) ? (a[i] - 48) : 0;
        t2 = i < strlen(b) ? (b[i] - 48) : 0;
        c[i] = ((t1 + t2 + addc) % 10) + 48;
        addc = (t1 + t2 + addc) / 10;
    }
    if(addc!=0)
    {
        c[i] = addc + 48;
        i++;
    }
    c[i] = '\0';
    reverseString(a);
    reverseString(b);
    reverseString(c);
}
int main()
{
    char B[5001],A[5001],C[5001];
    int i = 10;
    bool flag = false;
    scanf("%s", A);
    while(i>0)
    {
        i--;
        if(isPalindrome(A))
        {
            flag = true;
            printf("%s is a palindromic number.\n", A);
            break;
        }
        else
        {
            strcpy(B, A);
            reverseString(B);
            sum(A, B, C);
            printf("%s + %s = %s\n", A, B, C);
            strcpy(A, C);
        }
    }
    if(!flag)
    {
        printf("Not found in 10 iterations.\n");
    }
    return 0;
}