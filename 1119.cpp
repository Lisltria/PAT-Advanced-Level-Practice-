#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int post[30];
int pre[30];
int N;
vector<int> ans;
bool isUnique = true;
bool outflag = false;
void build(int sq,int eq,int sh,int eh)
{
    if(sq==eq)
    {
        ans.push_back( pre[sq] );
    }
    else
    {
        
        if(pre[sq+1]==post[eh-1])
        {
            isUnique = false;
            //cout << "NOOOO" << endl;
            ans.push_back( pre[sq] );
            build(sq + 1, eq, sh, eh-1);
        }
        else
        {
            int i, j;
            for (i = sh; i <= eh - 1;i++)
            {
                if(post[i]==pre[sq+1])
                {
                    break;
                }
            }
            for (j = sq+1; j <= eq ;j++)
            {
                if(post[eh-1]==pre[j])
                {
                    break;
                }
            }
            i = i - sh + 1;
            j = j - (sq + 1) + 1;
            if(sq + 1<=sq + i)
                build(sq + 1, sq + i, sh, sh + i - 1);
            ans.push_back( pre[sq] );
            if(sq + i + 1<=eq)
                build(sq + i + 1, eq, sh + i, eh - 1);
        }
    }
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N;i++)
        cin >> pre[i];
    for (int i = 0; i < N;i++)
        cin >> post[i];
    build(0, N - 1, 0, N - 1);    
    if(isUnique)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    for (int i = 0; i < N;i++)
    {
        if(outflag)
            cout << " ";
        else
            outflag = true;
        cout << ans[i];
    }
    cout << endl;
    return 0;
}