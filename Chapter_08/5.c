#include <stdio.h>

/**
 * 修改程序清单8.4(8.5.1节)的猜数字程序，使用更智能的猜测策略。
 * 例如，程序最初猜50，询问用户是猜大了、猜小了还是猜对了。
 * 如果猜小了，那么下一次猜测的值应是50和100中值，也就是75。如果这次猜大了，那么下一次猜测的值应是50和75的中值，等等。
 * 使用二分查找（binary search）策略，如果用户没有欺骗程序，那么程序很快就会猜到正确的答案。
 */

int main()
{
    int guess = 50;
    printf("Pick an integer from 1 to 100. I will try to guess it\n");
    printf("Respond with 'h' if my guess is too high, 'l' if it is too low, or 'c' if I guessed it right.\n");
    char response;
    int low = 1, high = 100; // 范围从1到100
    do
    {
        printf("Is your number %d? ", guess);
        response = getchar();
        while (getchar() != '\n'); // 清除输入缓冲区
        if (response == 'h') { //实际32 猜测guess = 50 猜高了 更新上界为 guess - 1
            high = guess - 1;
            guess = (low + guess) / 2;
        }
        else if (response == 'l') {  //51实际 猜测guess = 50 猜低了 更新下界为 guess + 1
            low = guess + 1;
            guess = (guess + high) / 2;
        }
    } while (response != 'c');
    printf("Your number is %d\n", guess);
    return 0;
}

