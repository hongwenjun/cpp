#include <stdio.h>

int main() {
  FILE *file = fopen("file.txt", "w");
  if (file != NULL) {
    fprintf(file, "This is some text.");
    fclose(file);
    printf("File created and written successfully.\n");
  } else {
    printf("Error opening file.\n");
  }

  return 0;
}