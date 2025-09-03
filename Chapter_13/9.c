#include <stdio.h>
#include <stdlib.h>
#define MAX 41

/**
 * 修改程序清单 13.3 中 (13.4.1节)的程序，从 1 开始，根据加入列表的顺序为每个单词编号。
 * 当程序下次运行时，确保新的单词编号接着上次的编号开始。
 */


int main()
{
    FILE* fp;
    char words[MAX] = { 0 };
    char line[MAX] = { 0 };
    int count = 1;

    if ((fp = fopen("wordy.txt", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");

    rewind(fp);    /* 返回到文件开始处 */

    while (fgets(words, MAX, fp))
        count++;

    fseek(fp, 0, SEEK_END);    /* 定位到文件末尾 */

    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
    {
        fprintf(fp, "%d. %s\n", count++, words);
    }

    puts("File contents:");
    rewind(fp);    /* 返回到文件开始处 */
    while ((fgets(line, MAX, fp)) != NULL) {
        fputs(line, stdout);
    }

    puts("Done!");

    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}
