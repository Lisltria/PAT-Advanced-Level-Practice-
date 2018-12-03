#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;

int insertQuery[20];
int N;

typedef struct node
{
    int data;
    node *lc, *rc;
} treeNode;
vector<treeNode> aTree;
int nodeCount = 0;
int ROOT=0;

int getDeepth(treeNode *r)
{
    int l, rr;
    if(r==NULL)
        return 0;
  
    l = getDeepth(r->lc);
    rr = getDeepth(r->rc);

    return (l > rr ? l : rr)+1;
}

treeNode *RotationRight(treeNode *r)
{
    treeNode *temp = r->lc;
    r->lc = temp->rc;
    temp->rc = r;
    return temp;
}
treeNode *RotationLeft(treeNode *r)
{
    treeNode *temp = r -> rc;
    r -> rc = temp->lc;
    temp->lc = r;
    return temp;
}
treeNode *RotationLeftRight(treeNode *r)
{
    r->lc = RotationLeft(r->lc);
    r = RotationRight(r);
    return r;
}
treeNode *RotationRightLeft(treeNode *r)
{
    r->rc = RotationRight(r -> rc);
    r = RotationLeft(r);
    return r;
}

treeNode *insertNode(int num,treeNode *r)
{
    if(r==NULL)
    {
        r = new treeNode();
        r->data = num;
        return r;
    }
    else
    {
        if(num<r->data)
        {
            int ll, rr;
            r->lc = insertNode(num, r->lc);
            ll = getDeepth(r->lc);
            rr = getDeepth(r->rc);
            if(ll-rr>=2)
            {
                if(num<r->lc->data)
                {
                    r = RotationRight(r);
                }
                else
                {
                    r = RotationLeftRight(r);
                }
            }
        }
        else
        {
            int ll, rr;
            r->rc = insertNode(num, r->rc);
            ll = getDeepth(r->lc);
            rr = getDeepth(r->rc);
            if(rr-ll>=2)
            {
                if(num>r->rc->data)
                {
                    r = RotationLeft(r);
                }
                else
                {
                    r = RotationRightLeft(r);
                }
            }
        }
        return r;
    }
}


int main(int argc, char const *argv[])
{
    /* code */
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> insertQuery[i];
    }
    treeNode *root;
    root = NULL;
    for (int i = 0; i < N; i++)
    {
        root = insertNode(insertQuery[i], root);
    }
    bool flag = false;
    bool isComplete = true;
    bool leftLeaf=false;
    queue<treeNode> q;
    q.push(*root);
    while(!q.empty())
    {
        treeNode t = q.front();
        q.pop();
        if(flag)
            cout << " ";
        else
            flag = true;
        cout << t.data;
        if(t.lc!=NULL)
            q.push(*t.lc);
        if(t.rc!=NULL)
            q.push(*t.rc);

        if(leftLeaf)
        {
            if(t.rc!=NULL||t.lc!=NULL)
            {
                isComplete = false;
            }
        }
        
        if(t.rc==NULL||t.lc==NULL)
        {
            if(t.rc==NULL&&t.lc!=NULL)
            {
                leftLeaf = true;
            }
            else if(t.rc==NULL&&t.lc==NULL)
            {
                leftLeaf = true;
            }
            else if(t.rc!=NULL&&t.lc==NULL)
            {
                isComplete = false;
            }

        }
    }
    cout << endl;
    if(isComplete)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}

