#include <iostream>
#include <assert.h>
#include <string>
#include <cstring>
using namespace std;

const int maxn = 200 + 1;//definition of max length of number

class Num
{
private:
        int a[maxn];//saving number as array
        int length;//saving number length
        bool neg;//saving if the number is negative

public:
        Num();
        Num operator +(const Num &b) const;
        Num operator -(const Num &b) const;
        Num operator *(const Num &b) const;
        Num operator *(int b) const;
        Num operator /(const Num &b) const;

        Num operator <<(int shft) const;//shft:移相器
        int& operator [](int idx);//idx:length of number
        int operator [](int idx) const;
        bool operator <(const Num &b) const;

        void init();
        void print();
};

Num::Num()
{
        memset(a, 0, sizeof(a));
        /*void *memset(void *s, int ch, size_t n);
        函数解释：将s中前n个字节 （typedef unsigned int size_t ）用 ch 替换并返回 s 。
        memset：作用是在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行清零操作的一种最快方法*/
        length = 0;//length of number array set zero
        neg = 0;//initialization:the number is positive
}

int& Num::operator [](int idx)//Check if digit overflow
{
        assert(idx >= 0 && idx < maxn);//judge if length of number is overflow
        /*Evaluate assertion:
        If the argument expression of this macro with functional form compares equal to zero (i.e., the expression is false),
        a message is written to the standard error device and abort is called, terminating the program execution.*/
        return a[idx];
}
int Num::operator [](int idx) const
{
        assert(idx >= 0 && idx < maxn);
        return a[idx];
}

Num Num::operator +(const Num &b) const//加法
{
        Num c;
        int t = 0;
        for (int i = 0; i < length || i < b.length || t; i++) {
                int s = a[i] + b[i] + t;//逐位相加
                c[i] = s % 10;//if 进位，该数字对10求模再存储
                t = s / 10;//存储是否进位（10进制）
                c.length++;//the length of calculation result +1，begin:高一位 calculation
        }
}

bool Num::operator <(const Num &b) const//是否小于等于判断：为下面的减法运算判断两数谁大谁小以确定符号作铺垫
{
        if (length != b.length) {//判断a数和b数是否有相同位数；如果不具有相同位数，进入下面的for循环判断每一位数谁大谁小
                return length < b.length;//如果a位数<b，返回true；反之false
        }
        for (int i = length - 1; i >= 0; i--) {//从高到低位判断每一位数谁大谁小
                if (a[i] != b[i]) {//如果从某一位开始不相等
                        return a[i] < b[i];//判断谁大，a该位大返回true
                }
        }
        return false;//全部比较完毕，a>=b
}

Num Num::operator -(const Num &b) const//减法
{
        if (*this < b) {//*this:point to object itself
                Num c = b - *this;
                c.neg = true;//a<b,so c is negative number
                return c;
        }

        int t = 0;//是否向a的高位借一位
        Num c;
        for (int i = 0; i < length; i++) {
                int s = a[i] - b[i] - t;//c的每一位s计算
                if (s < 0) {//a的某一位小于b的某一位，要向高位借1
                        s += 10;
                        t = 1;
                } else {
                        t = 0;
                }
                c[i] = s;
                c.length++;
        }
        while (c.length > 0 && c[c.length - 1] == 0) {
                c.length--;
        }
        return c;
}

Num Num::operator *(int b) const//乘法
{
        Num c;
        int t = 0;
        for (int i = 0; i < length || t; i++) {
                int s = b * a[i] + t;//b乘上a的每一位
                c[i] = s % 10;//该次计算的个位数字
                t = s / 10;//进位个数
                c.length++;
        }
        return c;
}

Num Num::operator <<(int shft) const//shft:移相器
{
        Num c;
        for (int i = 0; i < length; i++) {
                c[i + shft] = a[i];//shft:移相器
        }
        c.length = length + shft;
        return c;
}

Num Num::operator *(const Num &b) const
{
        Num c;
        for (int i = 0; i < b.length; i++) {
                c = c + (((*this) * b[i]) << i);
        }
        return c;
}

Num Num::operator /(const Num &b) const//除法
{
        assert(b.length > 0);//b长度若不大于0则报错

        Num c, tmpa = *this;
        c.length = length - b.length + 1;//c的最大位数为a的位数减去b的位数加1
        for (int i = length - b.length; i >= 0; i--) {//从高位开始做除法
                Num d = (b << i);

                /* while (tmpa >= d) */
                while (! (tmpa < d) ) {
                        tmpa = tmpa - d;
                        c[i]++;
                }
        }
        while (c.length > 0 && c[c.length - 1] == 0) {
                c.length--;
        }
        return c;
}

void Num::init()//init number
{
        char tmp[100 + 1];
        cin >> tmp;
        length = strlen(tmp);
        for (int i = 0; i < length; i++) {//convert char to int
                a[length - i - 1] = tmp[i] - '0';
        }
}

void Num::print()
{
        if (length == 0) {
                cout << 0 << endl;
                return ;
        }
        if (neg) {//judge positive or negative number
                cout << "-";
        }
        for (int i = length - 1; i >= 0; i--) {
                cout << a[i];
        }
        cout << endl;
}
int main()
{
        while (1) {
                Num a, b, c;//存储两个操作数和结果数
                char op[2];//操作符存储

                //input
                cout << "**********Big integer Calculation Program****Designed by 王昊(AnHui Normal University)*********" << endl;
                cout << "Welcome to big integer calculation program,you are allow to calculate no more than 300 digital!" << endl;
                cout << "Please input the first number:";
                a.init();
                cout << "Please input the opeator:";
                cin >> op;
                cout << "Please input the second number:";
                b.init();

                //judge opearation and calculation
                if (op[0] == '+') {
                        c = a + b;
                }
                if (op[0] == '-') {
                        c = a - b;
                }
                if (op[0] == '*') {
                        c = a * b;
                }
                if (op[0] == '/') {
                        c = a / b;
                }
                c.print();
        }

        return 0;
}
