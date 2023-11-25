#include <stdio.h>

struct Flags {
    unsigned int isRed : 1;
    unsigned int isGreen : 1;
    unsigned int isBlue : 1;
};

int main() {
    struct Flags f;
    f.isRed = 1;
    f.isGreen = 0;
    f.isBlue = 1;
    
    printf("Red: %u\n", f.isRed);
    printf("Green: %u\n", f.isGreen);
    printf("Blue: %u\n", f.isBlue);
    
    return 0;
}