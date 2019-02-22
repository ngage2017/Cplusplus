#include <stdio.h>
#include "LinkStack.h"

//中辍转后辍
int isNumber(char c)
{
    int ret = 0;
    switch(c)
    {
    case'0':
        ret = 1;break;
    case'1':
        ret = 1;break;
    case'2':
        ret = 1;break;
    case'3':
        ret = 1;break;
    case'4':
        ret = 1;break;
    case'5':
        ret = 1;break;
    case'6':
        ret = 1;break;
    case'7':
        ret = 1;break;
    case'8':
        ret = 1;break;
    case'9':
        ret = 1;break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

int isNumber1(char c)
{
    return ('0' <= c ) && (c <= '9');
}

int isOperator1(char c)
{
    int ret = 0;
    switch(c)
    {
    case'+':
    case'-':
    case'*':
    case'/':
        ret = 1;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

int isOperator(char c)
{
    int ret = 0;
    switch(c)
    {
    case'+':
        ret = 1;
        break;
    case'-':
        ret = 1;
        break;
    case'*':
        ret = 1;
        break;
    case'/':
        ret = 1;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

int isLeft(char c)
{
    return c == '(';
}

int isRight(char c)
{
    return c == ')';
}

int priority(char c)
{
    if(c == '+' || c == '-')
    {
        return 1;
    }
    if(c=='*' || c == '/')
    {
        return 2;
    }

    return 0;
}

void output(char c)
{
    if(c != '\0')
    {
        printf("%c",c);
    }
}

int transform(const char *exp)
{
    int i = 0;
    LinkStack* stack = LinkStack_Create();
    
    while(exp[i] != '\0')
    {
        if(isNumber(exp[i]))
        {
            output(exp[i]);
        }
        else if(isOperator(exp[i]))
        {
           while(priority(exp[i]) <= priority((char)(long)LinkStack_Top(stack)))
           {
               output((char)(long)LinkStack_Top(stack));
           }
           LinkStack_Push(stack,(void *)(long)exp[i]);
        }
        else if(isLeft(exp[i]))
        {
            LinkStack_Push(stack,(void *)(long)exp[i]);
        }
        else if(isRight(exp[i]))
        {
           while(!isLeft((char)(long)LinkStack_Top(stack)))
           {
               output((char)(long)LinkStack_Pop(stack));
           }
           LinkStack_Pop(stack);
        }else
        {
            printf("Invalid expression!\n");
            break;
        }

        i++;
    }

    while(LinkStack_Size(stack) > 0 && exp[i] == '\0')
    {
        output((char)(long)LinkStack_Pop(stack));
    }

    LinkStack_Destory(stack);
}


int expression(int left,int right,char op)
{
    int ret = 0;
    switch(op)
    {
    case'+':
        ret = left + right;
        break;
    case'-':
        ret = left - right;
        break;
    case'*':
        ret = left * right;
        break;
    case'/':
        ret = left / right;
        break;
    default:
        ret = 0;
        break;
    }
}

int value(char c)
{
    return (c - '0');
}

int computer(const char *exp)
{
    LinkStack *stack = LinkStack_Create();

    int ret = 0, i= 0;
    while(exp[i] != '\0')
    {
        if(isNumber1(exp[i]))
        {
            LinkStack_Push(stack,(void *)(long)value(exp[i]));
        }
        else if(isOperator1(exp[i]))
        {
            int right = (long)(LinkStack_Pop(stack));
            int left = (long)(LinkStack_Pop(stack));
            int result = expression(left,right,exp[i]);

            LinkStack_Push(stack,(void *)(long)result);

        }else
        {
        printf("Invalid expression -1\n");
        break;
        }

        i++;
    }

    if((LinkStack_Size(stack) == 1) && (exp[i] == '\0'))
    {
        ret = (long)LinkStack_Pop(stack);

    }
    else
    {
        printf("Invalid expression!-2\n");
    }

    LinkStack_Destory(stack);

    return ret;
}

int main01()
{
    const char* string = "8+(3-1)*5";
    transform(string);
    printf("\n");
    return 0;
}


int main()
{
    const char * exp = "831-5*+";
    printf("831-5*+  ======>%d\n",computer(exp));
    return 0;
}

