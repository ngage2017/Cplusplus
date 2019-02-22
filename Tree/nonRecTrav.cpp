#include <iostream>
#include <string.h>
#include "stack"
using namespace std;

typedef struct BiTNode
{
    int data;
    BiTNode* lchild,*rchild;
}BiTNode;

BiTNode* goLeft(BiTNode* tree,stack<BiTNode*> &_stack)
{
    if(tree == NULL)
    {
        return NULL;
    }

    while(tree->lchild)
    {
        _stack.push(tree);
        tree = tree->lchild;
    }

    return tree;
}

int nonRecTrav(BiTNode* _tree)
{
    int ret = 0;
    if(_tree == NULL)
    {
        ret = -1;
        return ret;
    }

    

    return ret;
}

int main()
{
    BiTNode r1,r2,r3,r4,r5;
    memset(&r1,0,sizeof(BiTNode));
    memset(&r2,0,sizeof(BiTNode));
    memset(&r3,0,sizeof(BiTNode));
    memset(&r4,0,sizeof(BiTNode));
    memset(&r5,0,sizeof(BiTNode));

    r1.data = 1;
    r2.data = 2;
    r3.data = 3;
    r4.data = 4;
    r5.data = 5;

    r1.lchild = &r2;
    r1.rchild = &r3;
    r2.lchild = &r4;
    r2.rchild = &r5;

    return 0;
}

