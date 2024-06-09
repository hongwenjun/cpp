#include <windows.h>
#include <stdio.h>

#define CUSTOM_FORMAT  RegisterClipboardFormatA("Portable Document Format")

int main(int argc, char* argv[])
 {
    // PDF文件路径
    const char* pdffile = "file.pdf";
    if(2 == argc)
        pdffile = argv[1];

    // 打开剪贴板
    if (!OpenClipboard(NULL)) {
        printf("Failed to open clipboard.\n");
        return 1;
    }

    // 清空剪贴板
    EmptyClipboard();

    // 读取PDF文件到内存
    FILE* file = fopen(pdffile, "rb");
    if (!file) {
        printf("Failed to open file.\n");
        CloseClipboard();
        return 1;
    }

    // 获取文件大小
    fseek(file, 0, SEEK_END);
    size_t fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // 分配内存并读取文件内容
    void* pdfData = malloc(fileSize);
    if (!pdfData) {
        printf("Failed to allocate memory.\n");
        fclose(file);
        CloseClipboard();
        return 1;
    }

    fread(pdfData, 1, fileSize, file);
    fclose(file);

    // 将二进制数据写入剪贴板
    HGLOBAL hGlobal = GlobalAlloc(GHND, fileSize);
    if (!hGlobal) {
        printf("Failed to allocate global memory.\n");
        free(pdfData);
        CloseClipboard();
        return 1;
    }

    memcpy(GlobalLock(hGlobal), pdfData, fileSize);
    GlobalUnlock(hGlobal);

    if (!SetClipboardData(CUSTOM_FORMAT, hGlobal)) {
        printf("Failed to set clipboard data.\n");
        GlobalFree(hGlobal);
        free(pdfData);
        CloseClipboard();
        return 1;
    }

    // 关闭剪贴板
    CloseClipboard();

    printf("PDF binary data copied to clipboard using custom format.\n");

    // 不要忘记释放内存
    free(pdfData);

    return 0;
}
