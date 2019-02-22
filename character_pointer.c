#include<stdio.h>

void print_string(char *s)
{
  int i = 0;
  while(s[i])
  {
     printf("%c",s[i++]);
  }
}

void print_string_a(char *p, int n)
{
  int i;
  for(i = 0; i < n; i++)
  {
     printf("%c",p[i]);
  }
}

int main()
{
  char buf[] = "hello world";
  buf[3] = 0;
  print_string_a(buf,sizeof(buf));
  //print_string(buf);
  return 0;
  char *p = buf;
  p+=5;
  *p = 'a';
  printf("buf = %s\n",buf);
  return 0;
}
