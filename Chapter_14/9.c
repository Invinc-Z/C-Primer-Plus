#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define NAME_LEN 20
#define SEAT_NUM 12
#define AIRLINE 4

/**
 * 巨人航空公司（编程练习 8）需要另一架飞机（容量相同），每天飞4班（航班 102、311、444 和519）。
 * 把程序扩展为可以处理4个航班。用一个顶层菜单提供航班选择和退出。
 * 选择一个特定航班，就会出现和编程练习8类似的菜单。但是该菜单要添加一个新选项：确认座位分配。
 * 而且，菜单中的退出是返回顶层菜单。每次显示都要指明当前正在处理的航班号。另外，座位分配显示要指明确认状态。
 */

typedef struct {
    int id;  // 座位编号
    bool is_booked; // 是否被预订， 1预订 0未预订
    bool is_confirmed; // 是否确认， 1 确认 0 不确定
    char first_name[NAME_LEN];
    char last_name[NAME_LEN];
} Order_t;

int initialize(Order_t (*orders)[SEAT_NUM], int n);
char get_flight();
char get_choice();
int show_num_empty_seats(Order_t orders[], int n);
void show_list_empty_seats(Order_t orders[], int n);
void show_list_alph_seats(Order_t orders[], int n);
void assign_seat(Order_t orders[], int n);
void del_seat_assign(Order_t orders[], int n);
int set_confirm(Order_t orders[], int n);
char* s_gets(char* str, int n);

char flight_num[AIRLINE] = {0}; //  全局变量，储存航线名称

int main()
{
    char flight, ch;
    Order_t orders[AIRLINE][SEAT_NUM] = { 0 };
    initialize(orders, AIRLINE);

    while((flight = get_flight() ) != 'q')
    {
        int idx = flight - 'a'; // 获取航线对应的订单索引
        while((ch = get_choice()) != 'g')
        {
            switch(ch)
            {
            case 'a':
                show_num_empty_seats(orders[idx], SEAT_NUM);
                break;
            case 'b':
                show_list_empty_seats(orders[idx], SEAT_NUM);
                break;
            case 'c':
                show_list_alph_seats(orders[idx], SEAT_NUM);
                break;
            case 'd':
                assign_seat(orders[idx], SEAT_NUM);
                break;
            case 'e':
                del_seat_assign(orders[idx], SEAT_NUM);
                break;
            case 'f':
                set_confirm(orders[idx], SEAT_NUM);
                break;
            default: 
                printf("Program error.\n");
                break;
            }
        }
    }
    printf("bye\n");

    return 0;
}

int initialize(Order_t (*orders)[SEAT_NUM], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < SEAT_NUM; j++)
        {
            orders[i][j].id = j + 1;
            orders[i][j].is_booked = 0;
            orders[i][j].is_confirmed = 0;
            memset(orders[i][j].first_name, 0, NAME_LEN);
            memset(orders[i][j].last_name, 0, NAME_LEN);
        }
    }
    return 0;
}

char get_flight()
{
    char ch;
    puts("To choose an airline or quit.");
    printf("a) 102      b) 311\n");
    printf("c) 444      d) 519\n");
    puts("q) Quit");

    while(((ch = getchar()) < 'a' || ch > 'd') && ch != 'q')
    {
        while(getchar() != '\n')
            continue;
        printf("Please enter the right letter (a, b, c, d or q).\n");
    }
    while(getchar() != '\n')
        continue;
    switch(ch)
    {
    case 'a': strcpy(flight_num, "102"); break;
    case 'b': strcpy(flight_num, "311"); break;
    case 'c': strcpy(flight_num, "444"); break;
    case 'd': strcpy(flight_num, "519"); break;
    default: break;
    }
    return ch;
}

char get_choice()
{
    char ch;

    printf("The number of the flight is %s. To choose a function, "
           "enter its letter label:\n", flight_num);
    printf("a) Show number of empty seats\n");
    printf("b) Show list of empty seats\n");
    printf("c) Show alphabetical list of seats\n");
    printf("d) Assign a customer to a seat assignment\n");
    printf("e) Delete a seat assignment\n");
    printf("f) Confirmed the seat assignment\n");
    printf("g) Quit\n");

    while ((ch = getchar()) < 'a' || ch > 'g')
    {
        while (getchar() != '\n')
            continue;
        printf("Please input the right letter.\n");
    }
    while (getchar() != '\n')
        continue;
    return ch;
}

int show_num_empty_seats(Order_t orders[], int n)
{
    int num_empty = 0;
    for (int i = 0; i < n; i++)
    {
        if (orders[i].is_booked == 0) num_empty++;
    }
    printf("The number of empty seats is: %d\n", num_empty);
    return num_empty;
}

void show_list_empty_seats(Order_t orders[], int n)
{
    printf("The list of empty seats is: [ ");
    for (int i = 0; i < n; i++)
    {
        if (orders[i].is_booked == 0) printf("%d,", orders[i].id);
    }
    printf("\b ]\n");
}

void show_list_alph_seats(Order_t orders[], int n)
{
    if (show_num_empty_seats(orders, n) == n)
    {
        printf("The seats are nobody to seat!\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (orders[i].is_booked == 1)
            printf("%d\t%s %s %s\n", orders[i].id, orders[i].first_name, orders[i].last_name, orders[i].is_confirmed ? "certain" : "uncertain");
    }
}

void assign_seat(Order_t orders[], int n)
{
    if (show_num_empty_seats(orders,n) == 0)
    {
        printf("The seats are full!\n");
        return;
    }
    show_list_empty_seats(orders, n);
    printf("Choose the seat for the customer is: ");
    int choose;
    scanf("%d", &choose);
    while (getchar() != '\n');
    printf("Enter the first name of the customer:\n");
    s_gets(orders[choose - 1].first_name, NAME_LEN);
    printf("Enter the last name of the customer:\n");
    s_gets(orders[choose - 1].last_name, NAME_LEN);
    orders[choose - 1].is_booked = true;
}

void del_seat_assign(Order_t orders[], int n)
{
    if (show_num_empty_seats(orders, n) == n)
    {
        printf("The seats are empty!\n");
        return;
    }
    show_list_alph_seats(orders, n);
    printf("Please enter the number you want to delete the seat assignment: ");
    int index;
    scanf("%d", &index);
    while(scanf("%d", &index) != 1 || index < 1 || index > 12 || orders[index -1].is_confirmed == 1)
    {
        printf("Please enter an integer value (1-12) and not confirmed: ");
        while (getchar() != '\n')
            continue;
    }
    while (getchar() != '\n');
    memset(orders[index - 1].first_name, 0, NAME_LEN);
    memset(orders[index - 1].last_name, 0, NAME_LEN);
    orders[index - 1].is_booked = false;
}

int set_confirm(Order_t orders[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (orders[i].is_booked == 1)
            orders[i].is_confirmed = 1;
    }

    return 0;
}

char* s_gets(char* str, int n)
{
    char* ret_val;
    char* find;
    ret_val = fgets(str, n, stdin);
    if(ret_val)
    {
        find = strchr(str, '\n');
        if(find) *find = '\0';
        else
        {
            while(getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}
