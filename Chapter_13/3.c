#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 256
/**
 * 编写一个文件拷贝程序，提示用户输入文本文件名，并以该文件名作为原始文件名和输出文件名。
 * 该程序要使用 ctype.h 中的 toupper()函数，在写入到输出文件时把所有文本转换成大写。使用标准I/O和文本模式。
 */

char* s_gets(char* st, int n);

int main()
{
    char filename[SIZE];
    char output_filename[SIZE + 10];
    char temp[SIZE];
    FILE* input_file, * output_file;
    int ch;

    // 1. 提示用户输入文件名
    printf("Please enter filename (example: example.txt): ");
    if (s_gets(filename, SIZE) == NULL) {
        printf("Error: can not read file name!\n");
        return -1;
    }

    // 2. 生成输出文件名（原文件名 + "_UPPER.txt"）
    strcpy(output_filename, filename);
    strcpy(temp, filename);
    char* dot = strrchr(temp, '.');  // 查找最后一个点（扩展名）
    if (dot != NULL) {
        *dot = '\0';  // 截断扩展名
        sprintf(output_filename, "%s_UPPER.txt", temp);
    }
    else {
        sprintf(output_filename, "%s_UPPER", temp);  // 无扩展名的情况
    }

    // 3. 打开输入文件（文本模式）
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error: can not open file %s\n", filename);
        return -1;
    }

    // 4. 创建输出文件（文本模式）
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: can not create file %s\n", output_filename);
        fclose(input_file);
        return -1;
    }

    // 5. 逐字符读取输入文件，转换为大写后写入输出文件
    while ((ch = fgetc(input_file)) != EOF) {
        fputc(toupper(ch), output_file);  // 关键转换：toupper()
    }

    // 6. 关闭文件
    fclose(input_file);
    fclose(output_file);

    printf("Transfer file succeed, save to: %s\n", output_filename);

    return 0;
}

char* s_gets(char* st, int n)
{
    char* ret_val;
    char* find;
    ret_val = fgets(st, n, stdin);
    if(ret_val == NULL)
        return NULL;
    else
    {
        if((find = strchr(st, '\n')) != NULL)
            *find = '\0';
        else
        {
            while(getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}
