#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096

/**
 * 修改程序清单13.5中(13.7.8节)的程序，用命令行界面代替交互式界面。
 */

void append(FILE* source, FILE* dest)
{
    size_t bytes;
    static char temp[BUFSIZE]; // 只分配一次
    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "args error\n");
        exit(EXIT_FAILURE);

    }
    FILE* fa, * fs; // fa指向目标文件，fs指向源文件
    int files = 0;
    if ((fa = fopen(argv[1], "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    for (int i = 2; i < argc; i++)
    {
        if (strcmp(argv[i], argv[1]) == 0)
        {
            fputs("Can't append file to itself\n", stderr);
            continue;
        }
        else if ((fs = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "Can't open %s\n", argv[i]);
            continue;
        }
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }
        }
        append(fs, fa);
        files++;
        if (ferror(fs) != 0)
        {
            fprintf(stderr, "Error in reading file %s.\n", argv[i]);
        }
        if (ferror(fs) != 0)
        {
            fprintf(stderr, "Error in writing file %s.\n", argv[1]);
        }
        fclose(fs);
        printf("File %s appended.\n", argv[i]);
    }
    printf("Done appending. %d files appended.\n", files);
    rewind(fa);
    printf("%s contents:\n", argv[1]);
    char ch;
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("\nDone displaying.");
    fclose(fa);

    return 0;
}
