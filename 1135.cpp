#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#define Black 1
#define Red -1
using namespace std;

bool flag = true;
int maxCount = -1;
void isRedBlackTree(int *tree,int *RB,int s,int e,int blackCount,int lastColor,int level)
{
    if(flag==false)
        return;
    if(level==1&&RB[s]<0)
    {
        flag = false;
        return;
    }
    else
    {
        if(lastColor==Red&&RB[s]<0)
        {
            flag = false;
            return;
        }
        else
        {
            if(s==e)
            {
                if(RB[s]>0)
                {
                    if(maxCount==-1)
                    {
                        maxCount = blackCount + 2;
                    }
                    else
                    {
                        if(blackCount + 2!=maxCount)
                        {
                            flag = false;
                            return;
                        }
                    }
                }
                else if(RB[s]<0)
                {
                    if(maxCount==-1)
                    {
                        maxCount = blackCount + 1;
                    }
                    else
                    {
                        if(blackCount + 1!=maxCount)
                        {
                            flag = false;
                            return;
                        }
                    }
                }
            }
            else
            {
                int i;
                for (i = s + 1; i <= e;i++)
                {
                    if(tree[i]>tree[s])
                    {
                        break;
                    }
                }
                if(s+1<=i-1)
                {
                    if(RB[s]>0)
                        isRedBlackTree(tree, RB,s + 1, i - 1, blackCount + 1, Black, level + 1);
                    else
                        isRedBlackTree(tree, RB,s + 1, i - 1, blackCount, Red, level + 1);
                }
                else
                {
                    if(RB[s]>0)
                    {
                        if(maxCount==-1)
                        {
                            maxCount = blackCount + 2;
                        }
                        else
                        {
                            if(blackCount + 2!=maxCount)
                            {
                                flag = false;
                                return;
                            }
                        }
                    }
                    else if(RB[s]<0)
                    {
                        if(maxCount==-1)
                        {
                            maxCount = blackCount + 1;
                        }
                        else
                        {
                            if(blackCount + 1!=maxCount)
                            {
                                flag = false;
                                return;
                            }
                        }
                    }
                }
                if(i<=e)
                {
                    if(RB[s]>0)
                        isRedBlackTree(tree, RB, i, e, blackCount + 1, Black, level + 1);
                    else
                        isRedBlackTree(tree, RB, i, e, blackCount , Red, level + 1);
                }
                else
                {
                    if(RB[s]>0)
                    {
                        if(maxCount==-1)
                        {
                            maxCount = blackCount + 2;
                        }
                        else
                        {
                            if(blackCount + 2!=maxCount)
                            {
                                flag = false;
                                return;
                            }
                        }
                    }
                    else if(RB[s]<0)
                    {
                        if(maxCount==-1)
                        {
                            maxCount = blackCount + 1;
                        }
                        else
                        {
                            if(blackCount + 1!=maxCount)
                            {
                                flag = false;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        char s[30];
        int K;
        int tree[31];
        int RB[31];
        cin >> K;
        for (int j = 1; j <= K;j++)
        {
            cin >> s;
            RB[j] = s[0] == '-' ? -1 : 1;
            sscanf(s, "%d", &tree[j]);
            tree[j] = abs(tree[j]);
        }
        flag = true;
        maxCount = -1;
        isRedBlackTree(tree, RB, 1, K, 0, Black, 1);
        if(flag)
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
