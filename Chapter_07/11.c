#include <stdio.h>
#include <ctype.h>
#define ARTICHOKE_PRICE 2.05 // 洋蓟价格
#define BEET_PRICE 1.15      // 甜菜价格
#define CARROT_PRICE 1.09    // 胡萝卜价格
#define DISCOUNT_THRESHOLD 100.0 // 折扣阈值
#define DISCOUNT_RATE 0.05       // 折扣率

/**
 * ABC邮购杂货店出售的洋蓟售价为2.05美元/磅，甜菜售价为1.15美元/磅，胡萝卜售价为1.09美元/磅。
 * 在添加运费之前，100美元的订单有5%的打折优惠。少于或等于5磅的订单收取6.5美元的运费和包装费，
 * 5磅～20磅的订单收取14美元的运费和包装费，超过20磅的订单在14美元的基础上每续重1磅增加0.5美元。
 * 编写一个程序，在循环中用switch语句实现用户输入不同的字母时有不同的响应，
 * 即输入a的响应是让用户输入洋蓟的磅数，b是甜菜的磅数，c是胡萝卜的磅数，q是退出订购。
 * 程序要记录累计的重量。即，如果用户输入4磅的甜菜，然后输入5磅的甜菜，程序应报告9磅的甜菜。
 * 然后，该程序要计算货物总价、折扣（如果有的话）、运费和包装费。
 * 随后，程序应显示所有的购买信息：
 * 物品售价、订购的重量（单位：磅）、订购的蔬菜费用、订单的总费用、折扣（如果有的话）、运费和包装费，以及所有的费用总额。
 */

double calculate_shipping(double total_weight);

int main()
{
    char choice;
    double artichoke_weight = 0.0, beet_weight = 0.0, carrot_weight = 0.0;
    double weight, subtotal, discount = 0.0, shipping, total;

    printf("ABC 邮购杂货店订单系统\n");
    printf("a) 洋蓟 ($%.2f/磅)\n", ARTICHOKE_PRICE);
    printf("b) 甜菜 ($%.2f/磅)\n", BEET_PRICE);
    printf("c) 胡萝卜 ($%.2f/磅)\n", CARROT_PRICE);
    printf("q) 退出订购\n");

    while (1) {
        printf("\n请选择要购买的蔬菜 (a/b/c/q): ");
        scanf(" %c", &choice); // 注意空格，跳过空白字符
        choice = toupper(choice); // 转换为大写

        switch (choice) {
        case 'A':
            printf("请输入洋蓟的磅数: ");
            scanf("%lf", &weight);
            artichoke_weight += weight;
            printf("当前洋蓟重量: %.2f 磅\n", artichoke_weight);
            break;
        case 'B':
            printf("请输入甜菜的磅数: ");
            scanf("%lf", &weight);
            beet_weight += weight;
            printf("当前甜菜重量: %.2f 磅\n", beet_weight);
            break;
        case 'C':
            printf("请输入胡萝卜的磅数: ");
            scanf("%lf", &weight);
            carrot_weight += weight;
            printf("当前胡萝卜重量: %.2f 磅\n", carrot_weight);
            break;
        case 'Q':
            goto calculate; // 退出循环，计算总价
        default:
            printf("无效输入，请重新选择！\n");
            continue;
        }
    }
calculate:
    // 计算小计
    subtotal = artichoke_weight * ARTICHOKE_PRICE + beet_weight * BEET_PRICE + carrot_weight * CARROT_PRICE;

    // 计算折扣
    if (subtotal >= DISCOUNT_THRESHOLD) {
        discount = subtotal * DISCOUNT_RATE;
    }

    // 计算总重量
    double total_weight = artichoke_weight + beet_weight + carrot_weight;

    // 计算运费
    shipping = calculate_shipping(total_weight);

    // 计算总费用
    total = subtotal - discount + shipping;

    // 显示订单详情
    printf("\n================ 订单详情 ================\n");
    printf("蔬菜种类    单价($)   重量(磅)   费用($)\n");
    printf("------------------------------------------\n");
    if (artichoke_weight > 0) {
        printf("洋蓟        %6.2f    %6.2f    %6.2f\n",
               ARTICHOKE_PRICE, artichoke_weight, artichoke_weight * ARTICHOKE_PRICE);
    }
    if (beet_weight > 0) {
        printf("甜菜        %6.2f    %6.2f    %6.2f\n",
               BEET_PRICE, beet_weight, beet_weight * BEET_PRICE);
    }
    if (carrot_weight > 0) {
        printf("胡萝卜      %6.2f    %6.2f    %6.2f\n",
               CARROT_PRICE, carrot_weight, carrot_weight * CARROT_PRICE);
    }
    printf("------------------------------------------\n");
    printf("小计: $%.2f\n", subtotal);
    if (discount > 0) {
        printf("折扣 (%.0f%%): -$%.2f\n", DISCOUNT_RATE * 100, discount);
    }
    printf("运费和包装费: $%.2f\n", shipping);
    printf("总费用: $%.2f\n", total);
    printf("------------------------------------------\n");

    return 0;
}

// 运费计算
double calculate_shipping(double total_weight) {
    if(total_weight <= 0){
        return 0.0;
    }
    else if (total_weight <= 5.0) {
        return 6.5;
    }
    else if (total_weight <= 20.0) {
        return 14.0;
    }
    else {
        return 14.0 + 0.5 * (total_weight - 20.0);
    }
}
