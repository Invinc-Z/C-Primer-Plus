#include <stdio.h>

/**
 * 编写一个程序，创建一个包含26个元素的数组，并在其中储存26个小写字母。然后打印数组的所有内容。
 */

int main()
{
    char arr[26] = {0};
    for(int i = 0; i < 26; i++)
    {
        arr[i] = 'a' + i;
    }
    for(int i = 0; i < 26; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
    return 0;
}

