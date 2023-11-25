#include <stdio.h>

#define PI 3.14159
#define SQUARE(x) ((x) * (x))

int main() {
    float radius = 2.5;
    float area = PI * SQUARE(radius);
    
    printf("Area: %.2f\n", area);
    
    return 0;
}