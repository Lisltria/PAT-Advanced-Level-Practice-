#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
long long gcd(long long  a,long long  b)
{
    if(a==0||b==0)
        return 1;
    long long  x = a, y = b;
    if(x<y)
    {
        swap(x, y);
    }
    while(y>0)
    {
        long long  t = x % y;
        x = y;
        y = t;
        if(x<y)
        {
            swap(x, y);
        }
    }
    if(x==0)
        return 1;
    else
        return x;
}
typedef struct node{
    long long numn;
    long long deca;
    long long inte;
    void simple(node &v)
    {
        if(v.deca!=0&&abs(v.numn)>=abs(v.deca))
        {
            if(v.numn*v.deca>0)
                v.inte = 1;
            else
                v.inte = -1;
            int n = abs(v.numn) / abs(v.deca);
            v.numn = abs(v.numn) - n * abs(v.deca);
            v.deca = abs(v.deca);
            v.inte *= n;
        }
        if(v.deca<0)
        {
            v.numn = -v.numn;
            v.deca = -v.deca;
        }
        if(v.deca!=0)
        {
            int n = gcd(abs(v.numn), abs(v.deca));
            v.numn /= n;
            v.deca /= n;
        }
    }

    node operator +(node &v)
    {
        node t;
        t.numn = numn * v.deca + deca * v.numn;
        t.deca = deca * v.deca;
        t.inte = 0;
        simple(t);
        return t;
    }
    node operator -(node &v)
    {
        node t;
        t.numn = numn * v.deca - deca * v.numn;
        t.deca = deca * v.deca;
        t.inte = 0;
        simple(t);
        return t;
    }
    node operator *(node &v)
    {
        node t;
        t.numn = numn * v.numn;
        t.deca = deca * v.deca;
        t.inte = 0;
        simple(t);
        return t;
    }
    node operator /(node &v)
    {
        node t;
        t.numn = numn * v.deca;
        t.deca = deca * v.numn;
        t.inte = 0;
        simple(t);
        return t;
    } 

    node():inte(0){}
}number;

void printNum(number x)
{
    if(x.deca==0)
    {
        printf("Inf");
        return;
    }
    if(x.inte!=0)
    {
        if(x.inte<0)
        {
            if(x.numn!=0)
                printf("(%lld %lld/%lld)", x.inte, x.numn, x.deca);
            else
                printf("(%lld)", x.inte);
        }
        else
        {
            if(x.numn!=0)
                printf("%lld %lld/%lld", x.inte, x.numn, x.deca);
            else
                printf("%lld", x.inte);
        }
        return;
    }
    if(x.inte==0)
    {
        if(x.numn!=0)
        {
            if(x.numn<0)
                printf("(%lld/%lld)", x.numn, x.deca);
            else
                printf("%lld/%lld", x.numn, x.deca);
        }
        else
            printf("0");
    }
}
int main()
{
    number t1,t2,t3,t4;
    char c;
    t3.inte = 0;
    t3.numn = 0;
    t3.deca = 1;
    t4.inte = 0;
    t4.numn = 0;
    t4.deca = 1;
    scanf("%lld", &t1.numn);
    scanf("%c", &c);
    if(c==' ')
    {
        t1.deca = 1;
    }
    else{
        scanf("%lld", &t1.deca);
    }

    scanf("%lld", &t2.numn);
    scanf("%c", &c);
    if(c=='/')
    {
        scanf("%lld", &t2.deca);
    }
    else{
        t2.deca = 1;
    }
    long long tt;
    tt = gcd(abs(t1.numn), abs(t1.deca));
    t1.numn /= tt;
    t1.deca /= tt;
    tt = gcd(abs(t2.numn), abs(t2.deca));
    t2.numn /= tt;
    t2.deca /= tt;

    number ans1, ans2, ans3, ans4;
    ans1 = t1 + t2;
    ans2 = t1 - t2;
    ans3 = t1 * t2;
    ans4 = t1 / t2;
    t3 = t1 + t3;
    t4 = t2 + t4;
    printNum(t3);
    printf(" + ");
    printNum(t4);
    printf(" = ");
    printNum(ans1);
    printf("\n");

    printNum(t3);
    printf(" - ");
    printNum(t4);
    printf(" = ");
    printNum(ans2);
    printf("\n");

    printNum(t3);
    printf(" * ");
    printNum(t4);
    printf(" = ");
    printNum(ans3);
    printf("\n");

    printNum(t3);
    printf(" / ");
    printNum(t4);
    printf(" = ");
    printNum(ans4);
    printf("\n");
    return 0;
}