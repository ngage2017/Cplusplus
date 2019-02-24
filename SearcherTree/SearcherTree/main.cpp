//
//  main.cpp
//  SearcherTree
//
//  Created by ChenJun on 19/2/24.
//  Copyright © 2019年 ChenJun. All rights reserved.
//

#include <iostream>
using namespace std;

struct BiTNode
{
    int value;
    BiTNode* left;
    BiTNode* right;
    BiTNode ()
    {
        left = NULL;
        right = NULL;
        value = 0;
    }
};

//递归创建搜索树
void AddNode(BiTNode*& root,int _value)
{
    if(root == NULL)
    {
        root = new BiTNode;
        root->value = _value;
        return;
    }
    
    if(_value < root->value)
    {
        AddNode(root->left,_value);
    }else
    {
        AddNode(root->right,_value);
    }
    return;
}

void AddNode1(BiTNode*& root,int _value)
{
    if(root == NULL)
    {
        root = new BiTNode;
        root->value = _value;
        return;
    }
    
    BiTNode* pNode = root;
    while(true)
    {
        //判断是加入右子树还是左子树
        if(_value > pNode->value)
        {
            //加入右子树
            if(pNode->right == NULL)
            {
                pNode->right = new BiTNode;
                pNode->right->value = _value;
                break;
            }
            pNode = pNode->right;
        }
        else
        {
            //加入左子树
            if(pNode->left == NULL)
            {
                pNode->left = new BiTNode;
                pNode->left->value = _value;
                break;
            }
            pNode = pNode->left;
        }
    }
}

void inOrder(BiTNode* tree)
{
    if(tree == NULL)
    {
        return ;
    }
    
    if(tree->left != NULL)
    {
        inOrder(tree->left);
    }
    
    cout<<tree->value<<" ";
    
    if(tree->right != NULL)
    {
        inOrder(tree->right);
    }
    return;
}

struct Teacher
{
    int age;
    char name[64];
};

int main(int argc, const char * argv[]) {
    // insert code here...
    //int mArray[] = {12,22,32,56,8,41,10,66};
    BiTNode *tree = NULL;
    Teacher tArray[8] = {0};
    
    for(int i = 0; i < 8;i++)
    {
        tArray[i].age = i + 10;
    }
    
    for(int i = 0; i < 8;i++)
    {
        AddNode1(tree, tArray[i].age);
    }
    
    inOrder(tree);
    
    cout << "Hello, World!\n";
    return 0;
}
