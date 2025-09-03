#include <stdio.h>
#define SIZE 4096

/**
 * 编写一个文件拷贝程序，该程序通过命令行获取原始文件名和拷贝文件名。尽量使用标准I/O和二进制模式。
 */

void file_copy(const char* src, const char* dest)
{
    FILE* sourceFile = fopen(src, "rb");
    if (sourceFile == NULL) {
        printf("Can't open source file: %s\n", src);
        return;

    }
    FILE* destFile = fopen(dest, "wb");
    if (destFile == NULL) {
        printf("Can't create dest file:  %s\n", dest);
        fclose(sourceFile);
        return;

    }
    char buffer[SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }
    fclose(sourceFile);
    fclose(destFile);
    printf("File copy success: %s -> %s\n", src, dest);

}
int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Usage: ./a.out src dest\n");
        return -1;

    }
    file_copy(argv[1], argv[2]);
}

