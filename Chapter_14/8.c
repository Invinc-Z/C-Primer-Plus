#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define NAME_LEN 20
#define SEAT_NUM 12

/**
 * 巨人航空公司的机群由12个座位的飞机组成。它每天飞行一个航班。根据下面的要求，编写一个座位预订程序。
 * a.该程序使用一个内含 12 个结构的数组。每个结构中包括：
 * 一个成员表示座位编号、一个成员表示座位是否已被预订、一个成员表示预订人的名、一个成员表示预订人的姓。
 * b.该程序显示下面的菜单：
 * To choose a function, enter its letter label:
 * a) Show number of empty seats
 * b) Show list of empty seats
 * c) Show alphabetical list of seats
 * d) Assign a customer to a seat assignment
 * e) Delete a seat assignment
 * f) Quit
 * c.该程序能成功执行上面给出的菜单。选择d)和e)要提示用户进行额外输入，每个选项都能让用户中止输入。
 * d.执行特定程序后，该程序再次显示菜单，除非用户选择f)。
 */

typedef struct {
    int id;  // 座位编号
    bool is_booked; // 是否被预订， 1预订 0未预订
    char first_name[NAME_LEN];
    char last_name[NAME_LEN];
} order_t;

void show_menu();
int show_num_empty_seats(order_t orders[], int n);
void show_list_empty_seats(order_t orders[], int n);
void show_list_alph_seats(order_t orders[], int n);
void assign_seat(order_t orders[], int n);
void del_seat_assign(order_t orders[], int n);
char* s_gets(char* str, int n);

int main()
{
    order_t orders[SEAT_NUM] = { 0 };
    show_menu();
    char ch;
    while ((ch = getchar()))
    {
        while (getchar() != '\n'); // 清除输入缓冲区
        switch (ch) {
        case 'a':
            // Show number of empty seats
            show_num_empty_seats(orders, SEAT_NUM);
            break;
        case 'b':
            // Show list of empty seats
            show_list_empty_seats(orders, SEAT_NUM);
            break;
        case 'c':
            // Show alphabetical list of seats
            show_list_alph_seats(orders, SEAT_NUM);
            break;
        case 'd':
            // Assign a customer to a seat assignment
            assign_seat(orders, SEAT_NUM);
            break;
        case 'e':
            // Delete a seat assignment
            del_seat_assign(orders, SEAT_NUM);
            break;
        case 'f':
            // Quit
            puts("bye");
            exit(0);
        }
        show_menu();
    }

    return 0;
}
void show_menu()
{
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Quit");
};

int show_num_empty_seats(order_t orders[], int n)
{
    int num_empty = 0;
    for (int i = 0; i < n; i++)
    {
        if (orders[i].is_booked == 0) num_empty++;
    }
    printf("The number of empty seats is: %d\n", num_empty);
    return num_empty;
}

void show_list_empty_seats(order_t orders[], int n)
{
    printf("The list of empty seats is: [ ");
    for (int i = 0; i < n; i++)
    {
        if (orders[i].is_booked == 0) printf("%d,", i + 1);
    }
    printf("\b ]\n");
}

void show_list_alph_seats(order_t orders[], int n)
{
    if (show_num_empty_seats(orders, n) == n)
    {
        printf("The seats are nobody to seat!\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (orders[i].is_booked == 1)
            printf("%d\t%s %s\n", i + 1, orders[i].first_name, orders[i].last_name);
    }
}

void assign_seat(order_t orders[], int n)
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
    char first_name[NAME_LEN] = { 0 };
    char last_name[NAME_LEN] = { 0 };
    printf("Enter the first name of the customer:\n");
    s_gets(orders[choose - 1].first_name, NAME_LEN);
    printf("Enter the last name of the customer:\n");
    s_gets(orders[choose - 1].last_name, NAME_LEN);
    orders[choose - 1].is_booked = true;
}

void del_seat_assign(order_t orders[], int n)
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
    while (getchar() != '\n');
    memset(orders[index - 1].first_name, 0, NAME_LEN);
    memset(orders[index - 1].last_name, 0, NAME_LEN);
    orders[index - 1].is_booked = false;
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
