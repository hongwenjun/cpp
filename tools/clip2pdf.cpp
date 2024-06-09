#include <windows.h>
#include <stdio.h>

#define CUSTOM_FORMAT  RegisterClipboardFormatA("Portable Document Format")

int main(int argc, char* argv[])
{
    // 要保存的PDF文件路径
    const char* outputFile = "output.pdf";
    if(2 == argc)
        outputFile = argv[1];

    // 打开剪贴板
    if (!OpenClipboard(NULL)) {
        printf("Failed to open clipboard.\n");
        return 1;
    }

    // 获取剪贴板中的PDF数据
    HANDLE hData = GetClipboardData(CUSTOM_FORMAT);
    if (!hData) {
        printf("Failed to get clipboard data.\n");
        CloseClipboard();
        return 1;
    }

    // 锁定内存并获取指针
    void* pdfData = GlobalLock(hData);
    if (!pdfData) {
        printf("Failed to lock global memory.\n");
        CloseClipboard();
        return 1;
    }

    // 获取PDF数据的大小
    size_t fileSize = GlobalSize(hData);

    // 将PDF数据写入文件
    FILE* file = fopen(outputFile, "wb");
    if (!file) {
        printf("Failed to open output file.\n");
        GlobalUnlock(hData);
        CloseClipboard();
        return 1;
    }

    fwrite(pdfData, 1, fileSize, file);
    fclose(file);

    // 解锁内存并关闭剪贴板
    GlobalUnlock(hData);
    CloseClipboard();

    printf("PDF binary data from clipboard saved to file: %s\n", outputFile);

    return 0;
}