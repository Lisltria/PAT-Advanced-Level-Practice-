
#include<iostream>
#include<cstdio>
#include<cmath> //abs需要
using namespace std;

struct Node{
    int value;
    Node *lchild;
    Node *rchild;
    int height;
    Node(int v) :value(v), lchild(NULL), rchild(NULL), height(0){}
    Node() :lchild(NULL), rchild(NULL){}
};

int getHeight(Node *t)
{
    if (t == NULL)return -1;
    else return t->height;
}
int max(int a, int b){
    return a > b ? a : b;
}

Node *SingleRotateLeft(Node *k2)
{//左左的情况
    Node *k1;
    k1 = k2->lchild;
    k2->lchild = k1->rchild;
    k1->rchild = k2;
    k2->height = max(getHeight(k2->lchild), getHeight(k2->rchild)) + 1;
    k1->height = max(getHeight(k1->lchild), getHeight(k1->rchild)) + 1;
    return k1;
}
Node *SingleRotateRight(Node *k2)
{//右右的情况
    Node *k1;
    k1 = k2->rchild;
    k2->rchild = k1->lchild;
    k1->lchild = k2;
    k2->height = max(getHeight(k2->lchild), getHeight(k2->rchild)) + 1;
    k1->height = max(getHeight(k1->lchild), getHeight(k1->rchild)) + 1;
    return k1;
}
Node *DoubleRotateLR(Node *k3)
{//左右的情况
    k3->lchild = SingleRotateRight(k3->lchild);
    return SingleRotateLeft(k3);
}
Node *DoubleRotateRL(Node *k3)
{//右左的情况
    k3->rchild = SingleRotateLeft(k3->rchild);
    return SingleRotateRight(k3);
}
bool isBalanced(Node *left, Node *right)
{
    return abs(getHeight(left) - getHeight(right)) < 2;
}
Node *insert(int v, Node *root)
{
    if (root == NULL)
    {
        root = new Node(v);
        return root;
    }
    else if (v > root->value)
    {
        root->rchild = insert(v, root->rchild);
        if (!isBalanced(root->lchild, root->rchild))
        {
            if (v > root->rchild->value)
                root = SingleRotateRight(root);
            else
                root = DoubleRotateRL(root);
        }
    }
    else
    {
        root->lchild = insert(v, root->lchild);
        if (!isBalanced(root->lchild, root->rchild))
        {
            if (v < root->lchild->value)
                root = SingleRotateLeft(root);
            else
                root = DoubleRotateLR(root);
        }
    }
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
    return root;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    Node *root = NULL;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        root = insert(tmp, root);
    }
    printf("%d\n", root->value);
    return 0;
}
