/*模拟简单运算器，假设计算器只能进行加减乘除运算，操作数和结果都是整数，假设4种运算符的优先级相同，按从左到右的顺序计算。
【要求】
a)	输入说明：输入一个四则混合算式（没有空格，且至少有一个操作数），遇到等号“=”则输入结束。
b)	输出说明：输出算式的运算结果或者错误信息。*/


#include <stdio.h>

int main(void)
{
        int Result, X;//save result and element
        char operator='+';

        printf("Please input the equation(must be integer~):");
        scanf("%d%c", &Result, &operator);        /* Input,because there is no space,we needn't deal with that*/
        while (operator != '=') {
                scanf("%d", &X); //input the next element

                switch (operator) {
                case '+':            // Calculate according to the exact operator
                        Result += X;
                        break;
                case '-':
                        Result -= X;
                        break;
                case '*':
                        Result *= X;
                        break;
                case '/':
                        if ( X == 0 ) {
                                printf("The denominator can be 0!Are you a child??\n");  //分母denominator
                                return 0;
                        }
                        Result /= X;
                        break;
                default:
                        printf("Illegal!\n");
                        return 0;
                }
                scanf("%c", &operator);        /*Input the next operator */
        }
        printf("%d\n", Result);        /* Print the result*/

}


