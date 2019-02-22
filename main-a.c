#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main01(int argc,char *args[])
{
  int i;
  for(i = 0; i < argc;i++)
  {
    printf("args[%d] = %s\n",i,args[i]);
  }
 // printf("%d\n",argc);
 // printf("args[0] = %s\n",args[0]);
  return 0;
}


int main02(int argc,char *args[])
{
  char buf[100]="ls";
  int i;
  for(i=1;i<argc;i++)
  {
    strcat(buf," ");
    strcat(buf,args[i]);
  }
  system(buf);
  //printf("buf = %s\n",buf);
  return 0;
}


int main03(int argc,char *args[])
{
  if(argc < 3)
   { 
     printf("参数不足，程序退出\n");
   }
  int a = atoi(args[1]);
  int b = atoi(args[2]);
  printf("%d\n",a+b);
  return 0;
}


int main(int argc,char *args[])
{
  if(argc < 4)
   {
     printf("参数不足，程序退出\n");
     return 0;
   }
  int a = atoi(args[1]);
  int b = atoi(args[3]);
  
  char *s = args[2];
  char c = s[0];

  switch(c)
  {
   case '+':
       printf("%d\n",a+b);
       break;
   case '*':
       printf("%d\n",a*b);
       break;
   case '-':
       printf("%d\n",a-b);
       break;
   case '/':
       if(b)
      {
       printf("%d\n",a/b);
      }
   }
  return 0;
}
