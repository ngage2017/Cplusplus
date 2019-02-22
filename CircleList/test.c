#include <stdio.h>
#include <string.h>

int main()
{
    int some = 0;
    char buf[] = "aello";
    char buf1[] = "bello";
    printf("%d\n",some = strncmp(buf,buf1,3));
    return 0;
}

