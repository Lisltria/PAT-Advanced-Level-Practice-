#include <iostream>
#include <cstdio>
using namespace std;

typedef struct node
{
    int data;
    node *lc, *rc;
} treeNode;

int findDeep(treeNode *r)
{
    if(r==NULL)
    {
        return 0;
    }
    else
    {
        int ll, rr;
        ll = findDeep(r->lc);
        rr = findDeep(r->rc);
        return (ll < rr ? rr : ll) + 1;
    }
}
treeNode *Right(treeNode *r)
{
    treeNode *temp = r->lc;
    r->lc = temp->rc;
    temp->rc = r;
    return temp;
}
treeNode *Left(treeNode *r)
{
    treeNode *temp = r->rc;
    r->rc = temp->lc;
    temp->lc = r;
    return temp;
}
treeNode *RightLeftR(treeNode *r)
{
    r->rc = Right(r->rc);
    r = Left(r);
    return r;
}
treeNode *LeftRightR(treeNode *r)
{
    r->lc = Left(r->lc);
    r = Right(r);
    return r;
}
treeNode *insert(int num,treeNode *r)
{
    if(r==NULL)
    {
        r = new treeNode();
        r->data = num;
        r->lc = NULL;
        r->rc = NULL;
        return r;
    }
    else
    {
        if(num<r->data)
        {
            int ll, rr;
            r->lc = insert(num, r->lc);
            ll = findDeep(r->lc);
            rr = findDeep(r->rc);
            if(ll-rr>=2)
            {
                if(num<r->lc->data)
                {
                    r = Right(r);
                }
                else
                {
                    r = LeftRightR(r);
                }
            }
        }
        else
        {
            int ll, rr;
            r->rc = insert(num, r->rc);
            ll = findDeep(r->lc);
            rr = findDeep(r->rc);
            if(rr-ll>=2)
            {
                if(num>r->rc->data)
                {
                    r = Left(r);
                }
                else
                {
                    r = RightLeftR(r);
                }
            }
        }
        return r;
    }
}

int main()
{
    int N;
    treeNode *root;
    root = NULL;
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        int t;
        cin >> t;
        root = insert(t, root);
    }
    cout << root->data << endl;
    return 0;
}