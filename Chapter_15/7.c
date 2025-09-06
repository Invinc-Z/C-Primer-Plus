#include <stdio.h>

/**
 * 设计一个位字段结构以储存下面的信息。
 * 字体ID：0～255之间的一个数；
 * 字体大小：0～127之间的一个数；
 * 对齐：0～2之间的一个数，表示左对齐、居中、右对齐；
 * 加粗：开（1）或闭（0）；
 * 斜体：开（1）或闭（0）；
 * 下划线：开（1）或关（0）;
 * 在一个程序中使用该结构来打印字体参数，并使用循环菜单来让用户改变参数。
 *
 * 编写一个与编程练习 6 功能相同的程序，使用 unsigned long 类型的变量储存字体信息，并且使用按位运算符而不是位成员来管理这些信息。
 * 该程序要使用按位与运算符（&）和合适的掩码来把字体ID和字体大小信息转换到指定的范围内。
 */

#define ID_MASK 0xFF
#define SIZE_MASK (0x7F << 8)
#define CENTER (0x1 << 15)
#define RIGHT (0x2 << 15)
#define BOLD (0x1 << 17)
#define ITALIC (0x1 << 18)
#define UNDERLINE (0x1 << 19)

const char* alignment[] = {"left", "center", "right"};
const char* toggle[] = {"off", "on"};

void show_font_info(unsigned long font);
char get_choice();
void set_id(unsigned long* font);
void set_size(unsigned long* font);
void set_alignment(unsigned long* font);
void toggle_bold(unsigned long* font);
void toggle_italic(unsigned long* font);
void toggle_underline(unsigned long* font);

int main()
{
    unsigned long font = 0;
    char ch;
    show_font_info(font);
    while((ch = get_choice()) && ch != 'q')
    {
        switch(ch)
        {
        case 'f': 
            set_id(&font);
            break;
        case 's':
            set_size(&font);
            break;
        case 'a':
            set_alignment(&font);
            break;
        case 'b':
            toggle_bold(&font);
            break;
        case 'i':
            toggle_italic(&font);
            break;
        case 'u':
            toggle_underline(&font);
            break;
        default:
            printf("Program error.\n");
            break;
        }
        show_font_info(font);
    }
    printf("bye\n");

    return 0;
}

void show_font_info(unsigned long font)
{
    printf(" ID SIZE ALIGNMENT\tB\tI\tU\n");
    printf("%3lu %4lu %9s\t%s\t%s\t%s\n", font & ID_MASK, font >> 8 & 0x7F, alignment[font >> 15 & 0x3], toggle[font >> 17 & 0x1], 
           toggle[font >> 18 & 0x1], toggle[font >> 19 & 0x1]);
    printf("f) change Font    s) change size    a) change alignment\n");
    printf("b) toggle bold    i) toggle italic  u) toggle underline\n");
    printf("q) quit\n");
}

char get_choice()
{
    char ch;
    while(scanf(" %c", &ch) != 1 || (ch != 'f' && ch != 's' && ch != 'a' && ch != 'b' && ch != 'i' && ch != 'u' && ch != 'q'))
    {
        printf("Invalid letter. Please enter letter (f, s, a, b, i, u) or q to quit: ");
        while(getchar() != '\n')
            continue;
    }
    while(getchar() != '\n')
        continue;

    return ch;
}
void set_id(unsigned long* p_font)
{
    int choice;
    printf("Enter font id (0-255): ");
    while(scanf("%d", &choice) != 1 || choice < 0 || choice > 255)
    {
        printf("Invalid font id. Please enter font id (0-255): ");
        while(getchar() != '\n')
            continue;
    }
    while(getchar() != '\n')
        continue;
    *p_font &= ~ID_MASK;
    *p_font |= choice;
}

void set_size(unsigned long* p_font)
{
    int choice;
    printf("Enter font size (0-127): ");
    while(scanf("%d", &choice) != 1 || choice < 0 || choice > 127)
    {
        printf("Invalid font id. Please enter font id (0-127): ");
        while(getchar() != '\n')
            continue;
    }
    while(getchar() != '\n')
        continue;
    *p_font &= ~SIZE_MASK;
    *p_font |= choice << 8;
}

void set_alignment(unsigned long* p_font)
{
    char ch;
    printf("Select alignment: \n");
    printf("l) left    c) center    r) right\n");
    while(scanf(" %c", &ch) != 1 || (ch != 'l' && ch != 'c' && ch != 'r'))
    {
        printf("Invalid alignment letter. Please enter letter (l, c, r): ");
        while(getchar() != '\n')
            continue;
    }
    while(getchar() != '\n')
        continue;
    if(ch == 'l')  *p_font &= ~CENTER;
    else if(ch == 'c') *p_font |= CENTER;
    else if(ch == 'r') *p_font |= RIGHT;
}

void toggle_bold(unsigned long* p_font)
{
    *p_font ^= BOLD; 
}
void toggle_italic(unsigned long* p_font)
{
    *p_font ^= ITALIC;
}
void toggle_underline(unsigned long* p_font)
{
    *p_font ^= UNDERLINE;
}
