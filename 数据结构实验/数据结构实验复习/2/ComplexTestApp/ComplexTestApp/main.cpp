#include "common.h"
#include "ComplexTestApp.h"
#include "FunctionBody.h"






int main(void)
{
        realimag Z1, Z2, sum, sub, mul;
        printf("*复数抽象数据类型及基本操作*\n");
        printf("****************************\n");
        printf("* 1.创建复数C1             *\n");
        printf("* 2.创建复数C2             *\n");
        printf("* 3.输出复数C1             *\n");
        printf("* 4.输出复数C2             *\n");
        printf("* 5.求C1和C2的和,并输出和  *\n");
        printf("* 6.求C1和C2的差,并输出差  *\n");
        printf("* 7.求C1和C2的积,并输出积  *\n");
        printf("* 0.结束                   *\n");
        printf("****************************\n");
        int choose;
        while (1) {
                scanf("%d", &choose);
                switch (choose) {
                case 1: {
                        ElemType v1, v2;
                        printf("Please input real and imaginary part of C1:");
                        scanf("%d%d", &v1, &v2);
                        AssignComplex(Z1, v1, v2);
                        printf("Created Succeed！\n");
                        break;
                }
                case 2: {
                        ElemType v1, v2;
                        printf("Please input real and imaginary part of C2:");
                        scanf("%d%d", &v1, &v2);
                        AssignComplex(Z2, v1, v2);
                        printf("Created Succeed！\n");
                        break;
                }
                case 3: {
                        printf("The value of C1 is:");
                        PrintComplex(Z1);
                        printf("\n");
                        break;
                }
                case 4: {
                        printf("The value of C2 is:");
                        PrintComplex(Z2);
                        printf("\n");
                        break;
                }
                case 5: {
                        printf("C1+C2=");
                        AddComplex(Z1, Z2, sum);
                        PrintComplex(sum);
                        printf("\n");
                        break;
                }
                case 6: {
                        printf("C1-C2=");
                        SubComplex(Z1, Z2, sub);
                        PrintComplex(sub);
                        printf("\n");
                        break;
                }
                case 7: {
                        printf("C1*C2=");
                        MulComplex(Z1, Z2, mul);
                        PrintComplex(mul);
                        printf("\n");
                        break;
                }
                case 0: {
                        printf("Exit!\n");
                        exit(0);
                }
                }
        }
        system("pause");
}
