#include <stdio.h>
#include <string.h>

int main()
{
	char str1[32];
	char str2[32];

	strcpy(str1, "String 1");
	strcpy(str2, "String 2");

	printf("String values are \"%s\" \"%s\"\n", str1, str2);
	int diff = strcmp(str1, str2);
	printf("First string is %s than second\n", (diff == 1 ? "bigger" : "less"));
	char str3[32];
	strcpy(str3, str1);
	strcat(str3, str2);
	printf("Concatenation of two strings is \"%s\"\n", str3);
	int ingpos = strstr(str3, "ing") - str3;
	printf("First occurrence of word ing in \"%s\" is at position %d\n", str3,
		   ingpos);
	return 0;
}
