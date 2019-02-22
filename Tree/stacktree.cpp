#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "stack"
using namespace std;

typedef struct BiTNode
{
    int data;
    struct BiTNode* lchild, *rchild;
}BiTNode;

int inOrder(BiTNode* tree)
{
    int ret = 0;
    if(tree->lchild != NULL)
    {
        inOrder(tree->lchild);
    }

    if(tree != NULL)
    {
        cout<<tree->data<<" ";
    }

    if(tree->rchild != NULL)
    {
        inOrder(tree->rchild);
    }
    return ret;
}

BiTNode* goLeft(BiTNode* tree,stack<BiTNode*> &stack)
{
    if(tree == NULL)
    {
        return NULL;
    }
    while(tree->lchild !=NULL)
    {
        stack.push(tree);
        tree = tree->lchild;
    }
    return tree;
}

int inOrder1(BiTNode* tree)
{
    int ret = 0;
    BiTNode* temp = NULL;
    stack<BiTNode*> stack;

    temp = goLeft(tree,stack);

    while(temp != NULL)
    {
        cout<<temp->data<<" ";

        if(temp->rchild)
        {
            temp = goLeft(temp->rchild,stack);
        }
        else if(!stack.empty())
        {
            temp = stack.top();
            stack.pop();
        }
        else
        {
            temp = NULL;
        }
    }

    return ret;
}

int main()
{
    BiTNode t1,t2,t3,t4,t5;

    memset(&t1,0,sizeof(BiTNode));
    memset(&t2,0,sizeof(BiTNode));
    memset(&t3,0,sizeof(BiTNode));
    memset(&t4,0,sizeof(BiTNode));
    memset(&t5,0,sizeof(BiTNode));
    
    t1.data = 1;
    t2.data = 2;
    t3.data = 3;
    t4.data = 4;
    t5.data = 5;

    //建立关系
    t1.lchild = &t2;
    t1.rchild = &t3;

    t2.lchild = &t4;
    t2.rchild = &t5;

    inOrder(&t1);

    cout<<"非递归遍历："<<endl;
    inOrder1(&t1);
    return 0;
}

