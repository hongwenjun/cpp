#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 保持结构体定义与写入时完全一致
struct Book {
    char title[50];
    char author[50];
    float price;
};

struct FileHeader {
    char magic[4];    // 魔数 "BOOK"
    int version;      // 版本号
    int count;        // 书籍总数
};

int main() {
    FILE *fp = fopen("books.dat", "rb"); // "rb" 表示二进制读取模式

    // 1. 先读取文件头
    struct FileHeader header;
    if (fread(&header, sizeof(struct FileHeader), 1, fp) != 1) {
        printf("读取文件头失败！\n");
        fclose(fp);
        return 1;
    }

    // 3. 根据文件头里的 count 动态分配内存
    struct Book *books = (struct Book *)malloc(header.count * sizeof(struct Book));
    if (books == NULL) {
        printf("内存分配失败！\n");
        fclose(fp);
        return 1;
    }

    // 4. 一次性读取所有书籍数据
    // 从当前文件指针位置（文件头之后）开始读
    size_t read_count = fread(books, sizeof(struct Book), header.count, fp);
    
    if (read_count != (size_t)header.count) {
        printf("读取数据时发生错误，预期 %d 条，实际读取 %zu 条。\n", header.count, read_count);
    } else {
        // 5. 打印读取到的内容进行验证
        for (int i = 0; i < header.count; i++) {
            printf("ID: %d | 书名: %-20s | 作者: %-10s | 价格: %.2f\n", 
                    i + 1, books[i].title, books[i].author, books[i].price);
        }
    }

    // 6. 清理工作
    fclose(fp);
    free(books);
    books = NULL;

    return 0;
}