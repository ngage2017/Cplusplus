#include<stdio.h>

void swap(int *a,int *b)
{
  int tmp = *a;
     *a = *b;
     *b = tmp;
}

void two_dimen_array(int (*p)[3])
{
   int i,j;
   for(i = 0; i < 2;i++)
   {
    for(j = 0; j < 3;j++)
    {
       printf("two_dimen_array[%d][%d] = %d\n",i,j,*(*(p+i)+j));
    }
   }
}

void mystrcpy(char *chr,const char *chr1)
{
   while(*chr1)
   {
      *chr = *chr1;
      chr++;
      chr1++;
   }
}

void mystrcat(char *chr,const char *chr1)
{
   while(*chr)
   {
     chr++;
   }
   while(*chr1)
   {
     *chr = *chr1;
     chr++;
     chr1++;
   }
}

char *mystrchr(char *str,const char c)
{
   while(*str)
   {
     if(*str == c)
      return str;
     str++;
   }
  return NULL;
}

int main()
{
  char str1[30] = "hello";
  char str2[20] = "nihaoma?";
  int array[2][3] = {{1,2,3},{4,5,6}};
  char *s = mystrchr(str1,'e');
  two_dimen_array(array);
 // mystrcpy(str1,str2);
  // mystrcat(str1,str2);
  int a =10;
  int b = 20;
  swap(&a,&b);
  printf("a = %d,b =%d \n",a,b);
  printf("str1 = %s\n",s);
  return 0;
}
