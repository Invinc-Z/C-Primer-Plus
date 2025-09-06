#include <stdio.h>
#include <string.h>

/**
 * 设计一个位字段结构以储存下面的信息。
 * 字体ID：0～255之间的一个数；
 * 字体大小：0～127之间的一个数；
 * 对齐：0～2之间的一个数，表示左对齐、居中、右对齐；
 * 加粗：开（1）或闭（0）；
 * 斜体：开（1）或闭（0）；
 * 下划线：开（1）或关（0）;
 * 在一个程序中使用该结构来打印字体参数，并使用循环菜单来让用户改变参数。
 */

typedef struct {
    unsigned int id : 8;
    unsigned int size : 7;
    unsigned int alignment : 2;
    unsigned int bold : 1;
    unsigned int italic : 1;
    unsigned int underline : 1;
} Font;
const char* alignment[] = {"left", "center", "right"};
const char* toggle[] = {"off", "on"};

void show_font_info(const Font* p_font);
char get_choice();
void set_id(Font* p_font);
void set_size(Font* p_font);
void set_alignment(Font* p_font);
void toggle_bold(Font* p_font);
void toggle_italic(Font* p_font);
void toggle_underline(Font* p_font);

int main()
{
    char ch;
    Font font;
    memset(&font, 0, sizeof(font));
    show_font_info(&font);
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
        show_font_info(&font);
    }
    printf("bye\n");

    return 0;
}

void show_font_info(const Font* p_font)
{
    printf(" ID SIZE ALIGNMENT\tB\tI\tU\n");
    printf("%3d %4d %9s\t%s\t%s\t%s\n", p_font->id, p_font->size, alignment[p_font->alignment], toggle[p_font->bold],
           toggle[p_font->italic], toggle[p_font->underline]);
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
void set_id(Font* p_font)
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
    p_font->id = choice;
}

void set_size(Font* p_font)
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
    p_font->size = choice;
}

void set_alignment(Font* p_font)
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
    if(ch == 'l') p_font->alignment = 0;
    else if(ch == 'c') p_font->alignment = 1;
    else if(ch == 'r') p_font->alignment = 2;
}

void toggle_bold(Font* p_font)
{
    p_font->bold = !p_font->bold;
}
void toggle_italic(Font* p_font)
{
    p_font->italic = !p_font->italic;
}
void toggle_underline(Font* p_font)
{
    p_font->underline = !p_font->underline;
}
