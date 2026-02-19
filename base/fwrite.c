#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[50];
    char author[50];
    float price;
};

struct FileHeader {
    char magic[4];
    int version;
    int count;
};

int main() {
    int num_books = 5;
    struct Book *books = (struct Book *)malloc(num_books * sizeof(struct Book));
    
    memset(books, 0, num_books * sizeof(struct Book));

    // 填充模拟数据
    for (int i = 0; i < num_books; i++) {
        sprintf(books[i].title, "C Programming Vol.%d", i + 1);
        sprintf(books[i].author, "Author %d", i + 1);
        books[i].price = 30.0f + i;
    }

    // 准备文件头
    struct FileHeader header = {{'B', 'O', 'O', 'K'}, 1, num_books};

    // 以二进制写入模式打开文件
    FILE *fp = fopen("books.dat", "wb");
    if (!fp) {
        perror("文件打开失败");
        free(books);
        return 1;
    }

    // 1. 写入文件头
    fwrite(&header, sizeof(struct FileHeader), 1, fp);

    // 2. 一次性写入所有书籍数据 (效率极高)
    fwrite(books, sizeof(struct Book), num_books, fp);

    printf("二进制数据已成功保存至 books.dat\n");

    fclose(fp);
    free(books);
    return 0;
}