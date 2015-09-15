/*      编写程序要求用户输入身高、体重和年龄，然后根据以下计算公式计算该用户适合穿什么尺码的服装：
     帽子的尺码=体重（以磅为单位）除以身高（以英寸为单位），结果乘以2.9；
     上衣尺码（以英寸为单位的胸围尺寸）=身高乘以体重除以288（年龄在30岁以上的人士要进行修正，即每10年多加1/8英寸）。注意：只有满了十年才进行这个修正（例如，年龄在30到39之间，无需修正；但40岁，就要增加1/8英寸）。
     腰围尺码=体重除以5.7（年龄在28岁以上的人士要进行修正，即每2年多加1/10英寸）；注意：只有满了2年才进行这个修正（例如，年龄在29之间，无需修正；但30岁，就要增加1/10英寸）。
【要求】
     每个计算都要使用一个函数；
     允许根据需要任意重复计算（即：输入任意一个用户信息，都能计算）。*/

#include <iostream>
using namespace std;

double hat(double h, double w, int age)
{
        return w / h * 2.9;
}

double clothes(double h, double w, int age)
{
        if (age <= 30) {
                return h * w / 288;
        } else {
                return h * w / 288 + (age - 30) / 10 * (1.0 / 8);
        }
}

double stomach(double h, double w, int age)
{
        if (age <= 28) {
                return w / 5.7;
        } else {
                return w / 5.7 + (age - 28) / 2 * 0.1;
        }
}

int main()
{
        double height, weight;
        int age, a;
        for ( ; ; ) {
                cout << "Input height,weight and age:";
                cin >> height >> weight >> age;
                cout << "Size of hat:" << hat(height, weight, age) << endl
                     << "Size of clothes:" << clothes(height, weight, age) << endl
                     << "Size of stomach:" << stomach(height, weight, age) << endl;
                cout << "Continue?      1、Yes  2、No" << endl;
                cin >> a;
                if (a == 2) {
                        break;
                }
        }
        return 0;
}



