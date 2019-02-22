#include<stdio.h>

int add(int a ,int b)
{
  return a+b;
}

int max(int a, int b)
{
  return a<b? a:b;
}

int main()
{
  //int *p(int *);
  //int (*p)(int *);
  //int *(*p)(int *);
  int status = 0;
  int (*p)(int,int);
  printf("please input status:");
  scanf("%d",&status);
  if(status==1)
  {
   p = add;
  }
  else
  {
   p = max;
  }
  int i = p(5,6);
  printf("%d\n",i);
  return 0;
}
