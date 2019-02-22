#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct BiTNode
{
    int data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode;


//先序遍历
void preOrder(BiTNode* root)
{
    if(root == NULL)
    {
        return;
    }

    printf("%-2d",root->data);
    preOrder(root->lchild);
    preOrder(root->rchild);
}

//中序遍历
void inOrder(BiTNode* root)
{
    if(root == NULL)
    {
        return;
    }

    inOrder(root->lchild);
    printf("%-2d",root->data);
    inOrder(root->rchild);
}

//后序遍历
void posOrder(BiTNode* root)
{
    if(root == NULL)
    {
        return;
    }

    posOrder(root->lchild);
    posOrder(root->rchild);
    printf("%-2d",root->data);
}

void CountLeaf(BiTNode* tree,int* sum)
{
    if(tree!= NULL)
    {
        if(tree->lchild == NULL && tree->rchild == NULL)
        {
            (*sum)++;
        }
        if(tree->lchild)
        {
            CountLeaf(tree->lchild,sum);
        }
        if(tree->rchild)
        {
            CountLeaf(tree->rchild,sum);
        }
    }
}

//求树的高度
int Deepth(BiTNode* tree)
{
    int LDeepth=0;
    int RDeepth=0;
    int DeepthVal = 0;

    if(tree == NULL)
    {
        DeepthVal = 0;
        return DeepthVal;
    }

    LDeepth = Deepth(tree->lchild);
    RDeepth = Deepth(tree->rchild);

    DeepthVal = (LDeepth > RDeepth ? LDeepth : RDeepth) + 1;
    return DeepthVal;
}

BiTNode* CopyT(BiTNode* tree)
{
    BiTNode* temp = NULL; 
    if(tree == NULL)
    {
        return NULL;
    }
    temp = (BiTNode*)malloc(sizeof(BiTNode));
    memset(temp,0,sizeof(BiTNode));
    temp = tree;

    if(tree->lchild != NULL)
    {
        CopyT(tree->lchild);
    }
    if(tree->rchild != NULL)
    {
        CopyT(tree->rchild);
    }

    return temp;
}

BiTNode* CopyTree(BiTNode* tree)
{
    BiTNode* NewNode = NULL;
    BiTNode* NewLp = NULL;
    BiTNode* NewRp= NULL;

    if(tree == NULL)
    {
        return NULL;
    }
    if(tree->lchild != NULL)
    {
        CopyTree(tree->lchild);
    }else
    {
        NewLp = NULL;
    }

    if(tree->rchild != NULL)
    {
        CopyTree(tree->rchild);
    }else
    {
        NewRp = NULL;
    }

    NewNode = (BiTNode*)malloc(sizeof(BiTNode));
    NewNode->lchild = tree->lchild;
    NewNode->rchild = tree->rchild;
    NewNode->data = tree->data;
    return NewNode;
}

int Destory(BiTNode* tree)
{
    int ret = 0;

    if(tree->lchild != NULL)
    {
        Destory(tree->lchild);
    }

    if(tree->rchild != NULL)
    {
        Destory(tree->rchild);
    }

    if(tree != NULL)
    {
        free(tree);
    }
    return ret;
}

int main()
{
    int sum = 0;
    int mDeepth = 0;
    BiTNode t1,t2,t3,t4,t5,*temp;
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

    CountLeaf(&t1,&sum);
    printf("sum = %d\n",sum);


    mDeepth = Deepth(&t1);
    printf("Deepth = %d\n",mDeepth);

    temp = CopyTree(&t1);

    //先序遍历
    printf("temp preOrder:\n");
    preOrder(temp);
    printf("\n");

    //中序遍历
    printf("temp inOrder:\n");
    inOrder(temp);
    printf("\n");
    //后序遍历
    printf("temp posOrder:\n");
    posOrder(temp);
    printf("\n");

    printf("\ntemp->lchild->data:%d\n",temp->lchild->data);
    Destory(&t1);
    return 0;
}


int main01()
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

    printf("t1.lchild->data:%d\n",t1.lchild->data);
    printf("t1.rchild->data:%d\n",t1.rchild->data);
    printf("t3.lchild->data:%d\n",t3.lchild->data);
    printf("t3.rchild->data:%d\n",t3.rchild->data);

    printf("Hello world\n");
    return 0;
}

