## 使用GPT 3.5 学习C语言: 25个简单代码让你了解 C 语言基本语法

![](https://lyvba.com/wp-content/uploads/2023/09/C_CPP零基础入门.jpg)

### 以下是一些学习C语言的常用代码示例，涵盖了各种语法和概念：

  1. Hello World

    
    
    #include <stdio.h>
    
    int main() {
    printf("Hello, World!\n");
    return 0;
    }

  2. 变量和数据类型

    
    
    #include <stdio.h>
    
    int main() {
    int age = 20;
    float weight = 65.5;
    char grade = 'A';
    printf("Age: %d\n", age);
    printf("Weight: %.2f\n", weight);
    printf("Grade: %c\n", grade);
    return 0;
    }

  3. 输入输出

    
    
    #include <stdio.h>
    
    int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("You entered: %d\n", num);
    return 0;
    }

  4. 条件语句

    
    
    #include <stdio.h>
    
    int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num > 0) {
        printf("Positive number\n");
    } else if (num < 0) {
        printf("Negative number\n");
    } else {
        printf("Zero\n");
    }
    return 0;
    }

  5. 循环语句

    
    
    #include <stdio.h>
    
    int main() {
    int i;
    for (i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    int j = 1;
    while (j <= 5) {
        printf("%d ", j);
        j++;
    }
    printf("\n");
    
    int k = 1;
    do {
        printf("%d ", k);
        k++;
    } while (k <= 5);
    printf("\n");
    
    return 0;
    }

  6. 数组

    
    
    #include <stdio.h>
    
    int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    printf("First element: %d\n", numbers[0]);
    printf("Second element: %d\n", numbers[1]);
    
    int i;
    for (i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    return 0;
    }

希望以上代码示例能帮助你学习C语言的基础知识。请注意，这只是一小部分C语言的语法示例，还有很多其他的语法和概念等待你去探索和学习。

当然，以下是更多的C语言代码示例，涵盖了更多的语法和概念：

  7. 函数

    
    
    #include <stdio.h>
    
    int add(int a, int b) {
    return a + b;
    }
    
    int main() {
    int result = add(2, 3);
    printf("Result: %d\n", result);
    return 0;
    }

  8. 字符串

    
    
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

  9. 结构体

    
    
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

  10. 指针

    
    
    #include <stdio.h>
    
    int main() {
    int num = 10;
    int *ptr = &num;
    
    printf("Value: %d\n", num);
    printf("Address: %p\n", &num);
    printf("Pointer value: %p\n", ptr);
    printf("Dereference pointer: %d\n", *ptr);
    
    return 0;
    }

  11. 文件操作

    
    
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

以上示例涵盖了C语言中的一些常用语法和概念，希望对你的学习有所帮助。记得不断练习和探索，以加深对C语言的理解和掌握。

当然，以下是更多的C语言代码示例，涵盖了更多的语法和概念：

  12. 动态内存分配

    
    
    #include <stdio.h>
    #include <stdlib.h>
    
    int main() {
    int *numbers = (int *)malloc(5 * sizeof(int));
    if (numbers != NULL) {
        numbers[0] = 1;
        numbers[1] = 2;
        numbers[2] = 3;
        numbers[3] = 4;
        numbers[4] = 5;
    
        int i;
        for (i = 0; i < 5; i++) {
            printf("%d ", numbers[i]);
        }
    
        free(numbers);
    } else {
        printf("Memory allocation failed.\n");
    }
    
    return 0;
    }

  13. 枚举

    
    
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

  14. 递归

    
    
    #include <stdio.h>
    
    int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
    }
    
    int main() {
    int num = 5;
    int result = factorial(num);
    printf("Factorial of %d is %d.\n", num, result);
    
    return 0;
    }

  15. 多文件编程

file1.c:

    
    
    #include <stdio.h>
    
    void sayHello() {
    printf("Hello from file1.c!\n");
    }

file2.c:

    
    
    #include <stdio.h>
    
    void sayHello(); // 函数声明
    
    int main() {
    sayHello();
    return 0;
    }

编译和链接两个文件：

    
    
    gcc file1.c file2.c -o program

以上示例涵盖了C语言中的更多语法和概念，希望对你的学习有所帮助。记得不断练习和探索，以加深对C语言的理解和掌握。

当然，以下是更多的C语言代码示例，涵盖了更多的语法和概念：

  16. 链表

    
    
    #include <stdio.h>
    #include <stdlib.h>
    
    typedef struct Node {
    int data;
    struct Node *next;
    } Node;
    
    void insert(Node **head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    }
    
    void display(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    }
    
    int main() {
    Node *head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    display(head);
    
    return 0;
    }

  17. 函数指针

    
    
    #include <stdio.h>
    
    int add(int a, int b) {
    return a + b;
    }
    
    int subtract(int a, int b) {
    return a - b;
    }
    
    int main() {
    int (*ptr)(int, int);
    
    ptr = add;
    printf("Addition: %d\n", ptr(2, 3));
    
    ptr = subtract;
    printf("Subtraction: %d\n", ptr(5, 3));
    
    return 0;
    }

  18. 位运算

    
    
    #include <stdio.h>
    
    int main() {
    unsigned int a = 5; // 0000 0101
    unsigned int b = 3; // 0000 0011
    
    unsigned int result;
    
    result = a & b; // 0000 0001 (位与)
    printf("Bitwise AND: %u\n", result);
    
    result = a | b; // 0000 0111 (位或)
    printf("Bitwise OR: %u\n", result);
    
    result = a ^ b; // 0000 0110 (位异或)
    printf("Bitwise XOR: %u\n", result);
    
    result = ~a; // 1111 1010 (位取反)
    printf("Bitwise NOT: %u\n", result);
    
    result = a << 2; // 0001 0100 (左移)
    printf("Left Shift: %u\n", result);
    
    result = a >> 1; // 0000 0010 (右移)
    printf("Right Shift: %u\n", result);
    
    return 0;
    }

  19. 宏定义

    
    
    #include <stdio.h>
    
    #define PI 3.14159
    #define SQUARE(x) ((x) * (x))
    
    int main() {
    float radius = 2.5;
    float area = PI * SQUARE(radius);
    
    printf("Area: %.2f\n", area);
    
    return 0;
    }

  20. 错误处理

    
    
    #include <stdio.h>
    #include <errno.h>
    #include <string.h>
    
    int main() {
    FILE *file = fopen("nonexistent.txt", "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
    } else {
        // 文件操作
        fclose(file);
    }
    
    return 0;
    }

以上示例涵盖了C语言中的更多语法和概念，希望对你的学习有所帮助。记得不断练习和探索，以加深对C语言的理解和掌握。

当然，以下是更多的C语言代码示例，涵盖了更多的语法和概念：

  21. 位字段

    
    
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

  22. 类型转换

    
    
    #include <stdio.h>
    
    int main() {
    int a = 10;
    double b = 3.14;
    
    double result = (double)a + b;
    
    printf("Result: %.2f\n", result);
    
    return 0;
    }

  23. 函数参数默认值

    
    
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

  24. 结构体指针与箭头操作符

    
    
    #include <stdio.h>
    #include <stdlib.h>
    
    typedef struct {
    int x;
    int y;
    } Point;
    
    int main() {
    Point *p = (Point *)malloc(sizeof(Point));
    p->x = 2;
    p->y = 3;
    
    printf("x: %d\n", p->x);
    printf("y: %d\n", p->y);
    
    free(p);
    
    return 0;
    }

  25. 逗号运算符

    
    
    #include <stdio.h>
    
    int main() {
    int a = 2, b = 3, c = 4, result;
    
    result = (a * b) + (c - a), a++, b++, c++;
    
    printf("Result: %d\n", result);
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);
    
    return 0;
    }

以上示例涵盖了C语言中的更多语法和概念，希望对你的学习有所帮助。记得不断练习和探索，以加深对C语言的理解和掌握。