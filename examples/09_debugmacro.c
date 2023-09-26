#include <stdio.h>

#define IS_DEBUG
#define printnum(x) printf("%d\n", x)
#ifdef IS_DEBUG
#define readnum(x)                                  \
	{                                               \
		printf("Reading number with scanf(%%d)\n"); \
		scanf("%d", &x);                            \
	}
#else
#define readnum(x) scanf("%d", &x)
#endif

#if defined(IS_DEBUG) && !defined(debuginit)
void debuginit()
{
	printf("Running in debug mode, disable this by commenting out #define "
		   "IS_DEBUG\n");
}
#endif

int main()
{
#ifdef IS_DEBUG
	debuginit();
#endif

	printf("Enter some number:\n");
	int x;
	readnum(x);
	printf("Number was ");
	printnum(x);
	return 0;
}
