#include<stdio.h>

/*int main01()
{
  int a;
  printf("please input a:\n");
  scanf("%d",&a);
  printf("a = %d\n",a);
  return 0;
}

int main()
{
  int a = 10;
  int *p = &a;
  if(*p)
  { 
    printf("true\n");
  }
    else
    {
     printf("false\n");
    }
  return 0;
}*/

int test(int *n)
{
  return (*n)++;
}
void print_buf(int buf[],int n)
{
  int i;
  for(i = 0; i < n;i++)
     printf("buf[%d] = %d\n",i,buf[i]); 
}

void set_buf(int buf[])
{
  *buf=100;
  buf++;
  *buf=200;
}
int main()
{ 
  int buf[]={1,2,3,4,5,6,7,8,9,10};
  int a = 0x1234;
  char *p = &a;
  int i = 100;
  p++;
  test(&i);
  set_buf(buf);
  print_buf(buf,sizeof(buf)/sizeof(int));
  printf("%d\n",i);
  printf("%x\n",*p);
  return 0;
}
