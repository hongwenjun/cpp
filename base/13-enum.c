#include <stdio.h>

typedef enum {
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY,
  SUNDAY
} Day;

int main() {
  Day today = TUESDAY;

  switch (today) {
  case MONDAY:
    printf("It's Monday.\n");
    break;
  case TUESDAY:
    printf("It's Tuesday.\n");
    break;
  case WEDNESDAY:
    printf("It's Wednesday.\n");
    break;
  case THURSDAY:
    printf("It's Thursday.\n");
    break;
  case FRIDAY:
    printf("It's Friday.\n");
    break;
  case SATURDAY:
    printf("It's Saturday.\n");
    break;
  case SUNDAY:
    printf("It's Sunday.\n");
    break;
  }

  return 0;
}