#include <stdio.h>
#include <stdlib.h>

// 定义函数指针类型
typedef double (*calc_func)(double, double);//定义一个指向函数的指针类型，该函数有两个double参数，返回值为double类型

// 函数声明
double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double divide(double a, double b);
double calculate(calc_func func, double a, double b);

int main()
{
    system("chcp 65001 > nul"); 
    int choice;
    double a, b;
    
    while(1)
    {
        printf("\n======= C语言计算器 =======\n");
        printf("1. 加法\n");
        printf("2. 减法\n");
        printf("3. 乘法\n");
        printf("4. 除法\n");
        printf("5. 退出\n");
        printf("请输入您的选择：");
        scanf("%d", &choice);
        
        if (choice == 5) {
            printf("感谢使用计算器，再见！\n");
            break;
        }
        
        if (choice < 1 || choice > 4) {
            printf("错误：无效的选择！请输入1-5之间的数字。\n");
            continue;
        }
        
        printf("请输入两个数字（用空格分隔）：");
        scanf("%lf %lf", &a, &b);
        
        switch(choice)
        {
            case 1:
                printf("%.2lf + %.2lf = %.2lf\n", a, b, calculate(add, a, b));
                break;
            case 2:
                printf("%.2lf - %.2lf = %.2lf\n", a, b, calculate(sub, a, b));
                break;
            case 3:
                printf("%.2lf × %.2lf = %.2lf\n", a, b, calculate(mul, a, b));
                break;
            case 4:
                if (b == 0) {
                    printf("错误：除数不能为零！\n");
                } else {
                    printf("%.2lf ÷ %.2lf = %.2lf\n", a, b, calculate(divide, a, b));
                }
                break;
        }
        
        system("pause");
        system("cls");
    }
    
    return 0;
}

// 加法函数
double add(double a, double b)
{
    return a + b;
}

// 减法函数
double sub(double a, double b)
{
    return a - b;
}

// 乘法函数
double mul(double a, double b)
{
    return a * b;
}

// 除法函数
double divide(double a, double b)
{
    return a / b;
}

// 回调函数：接收函数指针并调用
double calculate(calc_func func, double a, double b)
{
    return func(a, b);
}