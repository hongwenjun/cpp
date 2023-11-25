#include <stdio.h>

int main() {
  char name[20] = "John Doe";
  printf("Name: %s\n", name);

  char message[50];
  printf("Enter a message: ");
  fgets(message, sizeof(message), stdin);
  printf("You entered: %s\n", message);

  return 0;
}