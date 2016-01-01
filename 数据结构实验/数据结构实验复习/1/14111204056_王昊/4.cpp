/*      假设有N个物品，大小分别为s1,s2,s3,..,sN，其中si(i=1,2,..N)为满足大于等于1小于等于100的整数。
要把这些物品装入到容量为100的一批箱子（序号为1~N）里。
装箱方法是：对每个物品，顺序扫描箱子，把该物品放入足以能够容纳下的第一个箱子中。
请编程模拟这种装箱过程，并输出每个物品所在的箱子序号，以及放置全部物品所需的箱子数目。
【要求】
a)      输入说明：输入第1行给出物品个数N（小于等于50），第2行给出N个物品的大小；
b)      输出说明：按照输入顺序输出每个物品的大小及其所在箱子序号，每个物品占一行，最后一行输出所需的箱子数目。
*/

#include <iostream>
#include <cstring>
using namespace std;

char box[1010];
int main(void)
{
        memset(box, 100, sizeof(box));
        int N; //number of goods
        int t;//size of goods
        int num = 0;
        cout<<"Please input the number of goods:"<<endl;
        cin >> N;
        int temp = N;
        cout<<"Please input the size of each good:"<<endl;
        while (temp--) {
                cin >> t;
                for (int i = 0; i != N; i++) {
                        int a = box[i];
                        if (a >= t) {
                                if (a == 100) {
                                        num++;
                                }
                                box[i] -= t;
                                cout << t << " " << i + 1 << endl;
                                break;
                        }
                }
        }
        cout << num << endl;


}

