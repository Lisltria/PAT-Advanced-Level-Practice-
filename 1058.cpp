#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */

    int a,b,c,d,e,f;
    scanf("%d.%d.%d %d.%d.%d",&a,&b,&c,&d,&e,&f);
    if(c+f>=29)
    {
        b+=1;c=c+f-29;
    }
    else c+=f;
    if(b+e>=17)
    {
        a+=1;
        b=b+e-17;
    }
    else b+=e;
    a+=d;
    printf("%d.%d.%d\n",a,b,c);
    return 0;
}
