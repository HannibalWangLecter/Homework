#include "common.h"
#include "ComplexTestApp.h"
#include "FunctionBody.h"






int main(void)
{
        realimag Z1, Z2, sum, sub, mul;
        printf("*���������������ͼ���������*\n");
        printf("****************************\n");
        printf("* 1.��������C1             *\n");
        printf("* 2.��������C2             *\n");
        printf("* 3.�������C1             *\n");
        printf("* 4.�������C2             *\n");
        printf("* 5.��C1��C2�ĺ�,�������  *\n");
        printf("* 6.��C1��C2�Ĳ�,�������  *\n");
        printf("* 7.��C1��C2�Ļ�,�������  *\n");
        printf("* 0.����                   *\n");
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
                        printf("Created Succeed��\n");
                        break;
                }
                case 2: {
                        ElemType v1, v2;
                        printf("Please input real and imaginary part of C2:");
                        scanf("%d%d", &v1, &v2);
                        AssignComplex(Z2, v1, v2);
                        printf("Created Succeed��\n");
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
