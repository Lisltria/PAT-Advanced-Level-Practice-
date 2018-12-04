#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> ans[1001];
typedef struct node
{
    int data;
    node* lc;
    node* rc;
} tN;
vector<tN> tree;
int maxL = 0;
tN* insert(tN *r,int num,int level)
{
    if(r==NULL)
    {
        r = new tN();
        r->data = num;
        r->lc = NULL;
        r->rc = NULL;
        ans[level].push_back(num);

        if(level>maxL)
            maxL = level;
        return r;
    }
    else
    {
        if(num <= r->data)
        {
            r->lc = insert(r->lc, num,level+1);
        }
        else{
            r->rc = insert(r->rc, num,level+1);
        }
        return r;
    }

}

int main()
{
    int N;
    tN *root;
    root = NULL;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        root = insert(root, t, 1);
    }
    printf("%d + %d = %d\n", ans[maxL].size(), ans[maxL-1].size(), ans[maxL].size() + ans[maxL-1].size());
    return 0;
}