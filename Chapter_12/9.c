#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 编写一个符合以下描述的函数。首先，询问用户需要输入多少个单词。
 * 然后，接收用户输入的单词，并显示出来，使用malloc()并回答第1个问题（即要输入多少个单词），
 * 创建一个动态数组，该数组内含相应的指向char的指针（注意，由于数组的每个元素都是指向char的指针，
 * 所以用于储存malloc()返回值的指针应该是一个指向指针的指针，且它所指向的指针指向char）。
 * 在读取字符串时，该程序应该把单词读入一个临时的char数组，使用malloc()分配足够的存储空间来储存单词，并把地址存入该指针数组（该数组中每个元素都是指向 char 的指针）。
 * 然后，从临时数组中把单词拷贝到动态分配的存储空间中。
 * 因此，有一个字符指针数组，每个指针都指向一个对象，该对象的大小正好能容纳被储存的特定单词。
 * 下面是该程序的一个运行示例：
 * How many words do you wish to enter? 5
 * Enter 5 words now:
 * I enjoyed doing this exerise
 * Here are your words:
 * I
 * enjoyed
 * doing
 * this
 * exercise
 */

int main()
{
    int num_words = 0;
    printf("How many words do you wish to enter (0 to quit) ? ");
    while (scanf("%d", &num_words) == 1 && num_words > 0)
    {
        char** words = (char**)malloc(num_words * sizeof(char*)); // 动态分配指针数组
        if (words == NULL)
        {
            printf("Memory allocation failed.\n");
            return -1; // 返回NULL表示分配失败
        }

        printf("Enter %d words now:\n", num_words);

        // 为每个单词分配内存
        for (int i = 0; i < num_words; i++)
        {
            char temp[20] = { 0 }; // 临时存储输入的单词
            scanf("%s", temp); // 输入单词
                               // 分配内存并复制单词
            words[i] = (char*)malloc((strlen(temp) + 1) * sizeof(char)); // 分配足够的空间
            if (words[i] == NULL)
            {
                printf("Memory allocation failed for word %d.\n", i + 1);
                for (int j = 0; j < i; j++) // 释放之前分配的内存
                    free(words[j]);
                free(words);
                return -1; 
            }
            strcpy(words[i], temp); // 复制单词到分配的内存
        }

        printf("Here are your words:\n");
        for (int i = 0; i < num_words; i++)
        {
            printf("%s\n", words[i]); // 打印每个单词
            free(words[i]); // 释放每个单词的内存
        }
        free(words); // 释放指针数组的内存
        printf("How many words do you wish to enter (0 to quit) ? ");
    }
    printf("Done.\n");

    return 0;
}
