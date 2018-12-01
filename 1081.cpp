#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

long  gcd(long  a,long  b)
{
    long  x = a, y = b;
    if(x<y)
    {
        swap(x, y);
    }
    while(y>0)
    {
        long  t = x - y;
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

typedef struct node
{
    long  integer;
    long  numerator;
    long  denominator;
    node& operator +(node &v)
    {
        long  n;
        node t;
        t.integer = integer;
        if(abs(v.numerator)>=abs(v.denominator)){
            n = v.numerator / v.denominator;
            t.integer += n;
            v.numerator -= n * v.denominator;
        }
        t.numerator = denominator * v.numerator + numerator * v.denominator;
        t.denominator = denominator * v.denominator;
        n = gcd(abs(t.numerator), abs(t.denominator));
        t.numerator /= n;
        t.denominator /= n;
        
        if(abs(t.numerator)>=abs(t.denominator)){
            n = t.numerator / t.denominator;
            t.integer += n;
            t.numerator -= n * t.denominator;
        }
        integer = t.integer;
        numerator = t.numerator;
        denominator = t.denominator;
        return *this;
    }
    node():integer(0){}
} rational;
int main(int argc, char const *argv[])
{
    /* code */
    int N;
    rational ans;
    ans.integer = 0;
    ans.numerator = 0;
    ans.denominator = 1;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        long  x, y;
        char c;
        rational t;
        scanf("%ld", &x);
        scanf("%c", &c);
        if(c=='\n'||c==' ')
        {
            y = 1;
        }
        else scanf("%ld", &y);
        t.integer = 0;
        t.numerator = x;
        t.denominator = y;
        ans + t;
    }
    if(ans.integer!=0)
        printf("%ld", ans.integer);
    if(ans.numerator!=0)
    {
        if(ans.integer!=0)
        {
            printf(" ");
        }
        printf("%ld/%ld", ans.numerator, ans.denominator);
    }
    if(ans.integer==0&&ans.numerator==0)
        cout << "0";
    printf("\n");
    return 0;
}
