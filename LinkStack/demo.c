#include <stdio.h>
#include "LinkStack.h"

int isLef(char c)
{
    int ret = 0;
    switch(c)
    {
    case'<':
    case'(':
    case'{':
    case'[':
    case'\'':
    case'\"':
        ret = 1;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

int isRight(char c)
{
    int ret = 0;
    switch(c)
    {
        case'>':
        case')':
        case'}':
        case']':
        case'\"':
        case'\'':
            ret = 1;
            break;
        default:
            ret = 0;
            break;
    }
    return ret;
}

int match(char left,char right)
{
    int ret = 0;
    switch(left)
    {
    case'<':
        ret = (right == '>');
        break;
    case'(':
        ret = (right == ')');
        break;
    case'{':
        ret = (right == '}');
        break;
    case'[':
        ret = (right == ']');
        break;
    case'\'':
        ret = (right == '\'');
        break;
    case'\"':
        ret = (right == '\"');
        break;
    default:
        ret = 0;
        break;

    }
    return ret;
}

int Scanner(const char *code)
{
    int ret = 0, i = 0;
    LinkStack *stack = LinkStack_Create();
    while(code[i] != '\0')
    {
        if(isLef(code[i]))
        {
            LinkStack_Push(stack,(void *)&code[i]);
        }
        if(isRight(code[i]))
        {
            char *c = LinkStack_Pop(stack);
            if((c == NULL) || !match(*c,code[i]))
            {
                printf("%c does not match!\n",code[i]);
                ret = 0;
                break;
            }
        }
        i++;
    }

    if(LinkStack_Size(stack) == 0 && code[i]=='\0')
    {
        printf("Succeed!\n");
        ret = 0;
    }else
    {
        printf("Invalid code!\n");
        ret = 0;
    }

    LinkStack_Destory(stack);
    return ret;
}

int main()
{
    
    const char *code = "#inclue<stdio.h> int main() { int a[4][4];int (*p)[4]; p = [0];return 0;}";

    Scanner(code);
    printf("Hello world\n");
    return 0;
}

