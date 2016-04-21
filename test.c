#include <stdio.h>
#include <limits.h>
#include<stddef.h>
struct s {
	int i;
	char c;
	char a,v,s,w;
	long d;
};
int main(void)
{
    char *p="sandeep";
    printf("%zu\n",&p[7]-p);
    return 0;
}
