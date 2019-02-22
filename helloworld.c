#include<stdio.h>

void print_array(int *p,int n)
{
  int i;
  for(i = 0; i< n; i++)
   {
     printf("array[%d] = %d\n",i,*(p+i));
   }
}

void mystrcpy(char p[],char p1[])
{
  
}

int main()
{
  int array[10] = {1,2,3,4,5,6,7,8,9,10};
  int *p = array;
  print_array(array,10);
  return 0;
}
