#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *mem;
	mem = (char *)malloc(16);
	memset(mem, 'A', 15);
	mem[15] = 0;
	printf("Dynamically allocated memory at %p\n", mem);
	printf("Content: %s\n", mem);
	mem = (char *)realloc(mem, 32);
	memset(mem, 'A', 31);
	mem[31] = 0;
	printf("Reallocated, new address is %p\n", mem);
	printf("Content: %s\n", mem);
	free(mem);
	printf("Freed memory at %p\n", mem);
	return 0;
}
