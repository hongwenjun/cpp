#include <stdio.h>

void greet(char *name, char *message) {
  if (name == NULL) {
    name = "Guest";
  }
  printf("Hello, %s! %s\n", name, message);
}

int main() {
  greet(NULL, "Welcome to the program.");
  greet("John", "Nice to meet you.");

  return 0;
}