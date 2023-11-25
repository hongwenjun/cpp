#include <stdio.h>

typedef struct {
  char name[20];
  int age;
} Person;

int main() {
  Person person;
  strcpy(person.name, "John Doe");
  person.age = 25;

  printf("Name: %s\n", person.name);
  printf("Age: %d\n", person.age);

  return 0;
}