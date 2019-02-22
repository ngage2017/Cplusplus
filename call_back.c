#include<stdio.h>

int add(int a, int b)
{
  return a+b;
}

int max(int a,int b)
{
  return a>b? a:b;
}

int func(int (*p)(int,int),int a,int b)
{
  return p(a,b);
}

int main()
{
  int i = func(max,7,9);
  printf("i = %d\n",i);
  return 0;
}
